#include "matrix.hpp"

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
        throw logic_error("Try to add matrix with different size of matrix.");
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

Matrix operator -(const Matrix& matrix1, const Matrix& matrix2)
{
    if(!isSizeEquele(matrix1,matrix2))
    {
        throw logic_error("Try to subtract matrix with different size of matrix.");
    }
    Matrix result(matrix1);
    for(unsigned int i = 0;i<matrix1.getRows();++i)
    {
        for(unsigned int j = 0;j<matrix2.getCols();++j)
        {
            result[i][j] -= matrix2[i][j];
        }
    }
    return result;
}

Matrix operator * (const Matrix& matrix1, const Matrix& matrix2)
{
    if(matrix1.getCols() != matrix2.getRows())
    {
        throw logic_error("Try to multiply matrix with in appropriate size.");
    }
    Matrix result{};
    for(unsigned int i = 0;i<matrix1.getCols();++i)
    {
        for(unsigned int j = 0;j < matrix1.getRows();++j )
        {
            for(unsigned int k = 0;k<matrix1.getCols();++j)
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
            Array::swap(tmpMatrix[mid],tmpMatrix[tmpMatrix.findIndexMaxAbsValueInColumn(mid,mid)]);
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

QString& operator <<(QString& string,const Matrix& matrix)
{
    for(int i = 0;i < matrix.getRows(); ++i)
    {
        for(int j = 0;j < matrix.getCols(); ++j)
        {
            string+=" "+QString::fromStdString(to_string(matrix[i][j]));
        }
        string+="\n";
    }
    return string;
}
