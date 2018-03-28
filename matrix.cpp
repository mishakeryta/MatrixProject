#include "matrix.hpp"
#include "QDebug"

Matrix::Matrix(unsigned int rows,unsigned int cols):m_rows{rows},m_cols{cols}
{
    m_elements = new Array[rows]();
    for(unsigned int i = 0;i < rows; ++i)
    {
        m_elements[i].setLength(cols);
    }

}
Matrix::Matrix(const Matrix &matrix):m_rows{matrix.getRows()},m_cols{matrix.getCols()}
{
    m_elements = new Array[matrix.getRows()]();
    for(unsigned int i = 0;i < matrix.getRows();++i)
    {
        m_elements[i].setLength(matrix.getCols());
        for(unsigned int j = 0;j< matrix.getCols();++j)
        {
           (*this)[i][j] = matrix[i][j];
        }
    }
}

Array& Matrix::operator [](unsigned int row)
{
    if(row > m_rows) throw std::out_of_range("No so many rows in matrix");
    return m_elements[row];
}
const Array& Matrix::operator [](unsigned int row) const
{
    if(row > m_rows) throw std::out_of_range("No so many rows in matrix");
    return m_elements[row];
}

bool isSizeEquele(const Matrix& matrix1,const Matrix& matrix2)
{
    return (matrix1.m_cols == matrix2.m_cols && matrix1.m_rows == matrix2.m_rows);
}
Matrix operator +(const Matrix& matrix1,const Matrix& matrix2)
{
    if(!isSizeEquele(matrix1,matrix2))
    {
        throw logic_error("Logic,size error.");
    }
    Matrix result(matrix1);
    for(unsigned int i = 0;i<matrix1.getRows();++i)
    {
        for(unsigned int j = 0;j<matrix2.getCols();++j)
        {
            result[i][j] += matrix2[i][j];
        }
    }
    return result;
}

Matrix operator - (const Matrix& matrix)
{
    Matrix result(matrix);
    for(unsigned int i = 0;i < matrix.getRows();++i)
    {
        for(unsigned int j = 0;j < matrix.getCols();++j)
        {
            result[i][j] = -matrix[i][j];
        }
    }
    return result;
}

Matrix operator+(const Matrix& matrix,double val)
{
    if(matrix.getCols() != matrix.getRows()) throw logic_error("Not square matrix\n");
    Matrix result(matrix);
    for(unsigned int i = 0;i<matrix.getRows();++i)
    {

            result[i][i]+=val;
    }
    return result;
}

Matrix operator +(double val,const Matrix& matrix)
{
    return matrix+val;
}
Matrix Matrix::operator ++() const
{
    return *this + 1;
}
Matrix Matrix::operator --() const
{
    return *this - 1;
}

Matrix operator -(const Matrix& matrix1, const Matrix& matrix2)
{
    return matrix1+(-matrix2);
}
Matrix operator * (const Matrix& matrix1, const Matrix& matrix2)
{
    if(matrix1.getCols() != matrix2.getRows())
    {
        throw logic_error("Try to multiply matrix with in appropriate size.");
    }
    Matrix result(matrix1.getRows(),matrix2.getCols());
    for(unsigned int i = 0;i<matrix1.getRows();++i)
    {
        for(unsigned int j = 0;j < matrix2.getCols();++j )
        {
            for(unsigned int k = 0;k<matrix1.getCols();++k)
            {
                result[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    return result;
}

double  Matrix::determinant()
{
    if(this->getCols()!= this->getRows()) throw logic_error("Only squere matrix have determinant.");
    double det = 1;
    Matrix tmpMatrix{*this};
    for(unsigned int mid = 0;mid < tmpMatrix.getCols(); ++mid)
    {
        det *= tmpMatrix[mid][mid];
        if(fabs(tmpMatrix[mid][mid]) < 0.0001)
        {
            swap_arrays(tmpMatrix[mid], tmpMatrix[tmpMatrix.findIndexMaxAbsValueInColumn(mid,mid)]);
        }
        if(fabs(tmpMatrix[mid][mid]) < PERCISION)
        {
            return 0;
        }
        for(unsigned int row = mid + 1;row < this->getCols();++row)
        {
            if(tmpMatrix[row][mid])
            {
                double coef  = tmpMatrix[mid][mid]/tmpMatrix[row][mid];
                tmpMatrix[row]*=coef;
                tmpMatrix[row]-=tmpMatrix[mid];
                tmpMatrix[row]*=(1/coef);
            }
        }

    }
    return det;
}
Matrix Matrix::minor(unsigned int row,unsigned int col)
{
    Matrix minor(m_rows-1,m_cols-1);
    unsigned int minorRow = 0,minorCol = 0;
    for(unsigned int i = 0;i < m_rows;++i )
    {
        for(unsigned int j = 0;j < m_cols;++j )
        {
            if(i != row &&  j != col)
            {
                minor[(i<row)?i:i-1][(j<col)?j:j-1] = m_elements[i][j];
            }
        }
    }
    return minor;
}
Matrix Matrix::transpose()
{
    Matrix result(m_cols,m_rows);
    for(unsigned int i = 0;i<m_rows;++i)
    {
        for(unsigned int j = 0;j<m_cols;++j)
        {
            result[j][i] = m_elements[i][j];
        }
    }
    return result;
}
Matrix Matrix::inverse()
{
    if(m_rows != m_cols) throw logic_error("");
    double detMatrix = determinant();
    if(!detMatrix) throw logic_error("");
    Matrix addMatrix(m_rows,m_cols);
    for(unsigned int i = 0;i < m_rows;++i)
    {
        for(unsigned int j = 0;j < m_cols;++j)
        {
            Matrix minor1 = minor(i,j);
            double detMinor = minor1.determinant();
            addMatrix[i][j] =(((i+j)%2)?(-1):(1))*(detMinor/detMatrix);
            if(fabs(addMatrix[i][j])<PERCISION)
            {
                addMatrix[i][j] = 0;
            }

        }
    }
    QString str{""};
    str<<addMatrix;
    qDebug()<<str;
    return addMatrix.transpose();
}



unsigned int Matrix::findIndexMaxAbsValueInColumn(unsigned int column,unsigned int startRow) const
{
    if(column>=m_cols ) throw out_of_range("No so many cols in matrix.");
    if(startRow>=m_rows) throw out_of_range("No so many rows in matrix.");
    unsigned int result = startRow;
    for(unsigned int i = startRow+1;i < m_rows;++i)
    {
        if(fabs(m_elements[i][column])>fabs(m_elements[result][column]))
        {
            result = i;
        }
    }
    return result;
}
double Matrix::findMaxAbsValue() const
{
    double result = m_elements[0].findMaxAbsValue();
    for(unsigned int i = 1;i<m_rows;++i)
    {
        double tmp = m_elements[i].findMaxAbsValue();
        if(fabs(tmp)>fabs(result))
        {
            result = tmp;
        }
    }
    return result;
}
double Matrix::findMaxNegativeValue() const
{
    double result = m_elements[0].findMaxNegativeValue();
    for(unsigned int i = 1;i<m_rows;++i)
    {
        double tmp = m_elements[i].findMaxNegativeValue();
        if(result>=0)
        {
            if(tmp<0)
            {
                result = tmp;
            }
        }
        else
        {
            if(tmp<0 && tmp>result)
            {
                result = tmp;
            }
        }
    }
    return result;
}
double Matrix::findMinPositiveValue() const
{
    double result = m_elements[0].findMinPositiveValue();
    for(unsigned int i = 1;i<m_rows;++i)
    {
        double tmp = m_elements[i].findMinPositiveValue();
        if(result<0)
        {
            if(tmp>0)
            {
                result = tmp;
            }
        }
        else if(tmp<result)
        {
            result = tmp;
        }
    }
    return result;
}


QString& operator <<(QString& string,const Matrix& matrix)
{
    for(unsigned int i = 0;i < matrix.getRows(); ++i)
    {
        for(unsigned int j = 0;j < matrix.getCols(); ++j)
        {
            string+=" "+QString::fromStdString(to_string(matrix[i][j]));
        }
        string+="\n";
    }
    return string;
}
QString& operator>>(const Matrix& matrix,QString& string)
{
    return string<<matrix;
}

Matrix& operator>>(const QString& qsMatrix,Matrix& matrix)
{
    QList<QString> qsRowsValues = qsMatrix.split(QRegExp("\n"),QString::SkipEmptyParts);
    QList<double>* valueOnRows = new QList<double>[qsRowsValues.length()]{};
    unsigned int maxLength = 0;
    for(int i = 0;i < qsRowsValues.length();++i)
    {
        QList<QString> qsValueOnRow = qsRowsValues.at(i).split(QRegExp(" "),QString::SkipEmptyParts);
        if(qsValueOnRow.length()>maxLength)
        {
            maxLength = qsValueOnRow.length();
        }
        for(auto qsVal:qsValueOnRow)
        {
            valueOnRows[i].append(qsVal.toDouble());
        }
    }
    matrix.setRows(qsRowsValues.length()).setCols(maxLength);
    for(int i = 0;i < qsRowsValues.length();++i)
    {
        for(int j = 0;j < valueOnRows[i].length();++j)
        {
            matrix[i][j] = valueOnRows[i].at(j);
        }
    }
    delete[] valueOnRows;
    return matrix;
}
Matrix& operator<<(Matrix& matrix,const QString& str)
{
    return str>>matrix;
}
Matrix& Matrix::setCols(unsigned int cols)
{
    if(cols == 0) cols = 1;
    for(unsigned int i = 0;i<m_rows;++i)
    {
        m_elements[i].setLength(cols);
    }
    m_cols = cols;
    return *this;
}

Matrix& Matrix::setRows(unsigned int rows)
{
    if(rows == 0) rows =1;
    Array* new_elements = new Array[rows]{};
    for(unsigned int i = 0;i < rows && i < m_rows;++i)
    {
        new_elements[i].setLength(m_cols);
        for(unsigned int j = 0;j < m_cols;++j)
        {
            new_elements[i][j] = m_elements[i][j];
        }
    }
    m_rows = rows;
    delete[]m_elements;
    m_elements = new_elements;
    setCols(m_cols);
    new_elements = nullptr;
    return *this;
}

Matrix& operator<<(Matrix& matrix,const QTableWidget* tbMatrix)
{
    matrix.setRows(tbMatrix->rowCount());
    matrix.setCols(tbMatrix->columnCount());
    for(int i = 0;i < tbMatrix->rowCount();++i)
    {
        for(int j = 0;j < tbMatrix->columnCount();++j)
        {
            matrix[i][j] = tbMatrix->item(i,j)->text().toDouble();
        }
    }
    return matrix;
}
QTableWidget* operator>>(const Matrix& matrix,QTableWidget* tbMatrix)
{
    tbMatrix->setRowCount(matrix.getRows());
    tbMatrix->setColumnCount(matrix.getCols());
    for(int i = 0;i<matrix.getRows();++i)
    {
        for(int j = 0;j<matrix.getCols();++j)
        {
            tbMatrix->item(i,j)->setText(QString::fromStdString(to_string(matrix[i][j])));
        }
    }
    return tbMatrix;
}


