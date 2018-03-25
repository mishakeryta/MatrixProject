#ifndef MATRIX_H
#define MATRIX_H
#include "array.hpp"
using namespace  std;

class Matrix
{
public:
    Matrix():m_elements{new Array[1]{}},m_rows{1},m_cols{1} {  }
    Matrix(unsigned int rows,unsigned int cols);
    Matrix(unsigned int order):Matrix(order,order) {  }
    Matrix(const Matrix& matrix);
    ~Matrix(){delete[] m_elements;}
    unsigned int getRows() const { return m_rows; }
    unsigned int getCols() const { return m_cols; }
    const Array& operator[](unsigned int row) const;
    Array& operator[](unsigned int row);




private:
    Array* m_elements;
    unsigned int m_rows;
    unsigned int m_cols;
};

#endif // MATRIX_H
