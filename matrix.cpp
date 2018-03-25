#include "matrix.hpp"


Matrix::Matrix(unsigned int rows,unsigned int cols)
{
    m_elements = new Array[rows]();
    for(unsigned int i = 0;i < rows; ++i)
    {
        m_elements[i].setLength(cols);
    }
}
Matrix::Matrix(const Matrix &matrix)
{
    m_elements = new Array[matrix.getRows()]();
    for(unsigned int i = 0;i<matrix.getRows();++i)
    {
        m_elements[i].setLength(matrix.getCols());
        for(unsigned int j = 0;j< matrix.getCols();++j)
        {
            m_elements[i][j] = matrix[i][j];
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
