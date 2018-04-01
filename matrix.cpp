#include "matrix.hpp"



Matrix::Matrix(unsigned int rows, unsigned int cols):m_rowsCount{rows},m_colsCount{cols}
  ,m_elements{new double*[rows]}
{
    for(unsigned int i = 0;i<rows;++i)
    {
        m_elements[i] = new double[cols]{};
    }
}
Matrix::Matrix(initializer_list<initializer_list<double> > initList)
{
    m_elements = new double*[initList.size()]{};
    unsigned int colsCount = 0;
    for(auto initListForRow:initList)
    {
        if(initListForRow.size()>colsCount)
        {
            colsCount = initListForRow.size();
        }
    }
    for(unsigned int row = 0;row < initList.size();++row)
    {
        m_elements[row] = new double[colsCount]{};
        for(unsigned int col = 0; col<initList.begin()[row].size(); ++col)
        {
            m_elements[row][col] = initList.begin()[row].begin()[col];
        }
    }
    m_rowsCount = initList.size();
    m_colsCount = colsCount;
}
/*Matrix::Matrix(const Matrix& matrix):m_rowsCount{matrix.getRows()},
    m_colsCount{matrix.getCols()}
  ,m_elements{new double*[matrix.getRows()]}
{
   for(int i = 0;i < matrix.getRows();++i)
   {
       matrix[i] = new double[matrix.getCols()]{};
       for(int j = 0;j<matrix.getCols();++j)
       {
           m_elements[i][j] = matrix.at(i,j);
       }
   }
}
*/
Matrix::~Matrix()
{
    for(unsigned int i = 0; i < m_rowsCount;++i)
    {
        delete[] m_elements[i];
    }
    delete[] m_elements;
    m_elements = nullptr;
}
double& Matrix::at(unsigned int row,unsigned int col)
{
    if(row>m_rowsCount || col>m_colsCount) throw out_of_range("Matrix::out_of_range");
    return m_elements[row][col];
}
const double& Matrix::at(unsigned int row, unsigned int col) const
{
    return this->at(row,col);
}
