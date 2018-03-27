#ifndef MATRIX_H
#define MATRIX_H
#include "array.hpp"
using namespace  std;

#define PERCISION 0.000000001
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

    double findMaxValue() const;
    double findMaxAbsValue() const;
    double findMaxNegativeValue()const;
    double findMinPositiveValue() const;
    unsigned int findIndexMaxAbsValueInColumn(unsigned int column,unsigned int startRow) const;
    Matrix& setRows(int rows); //resize matrix
    Matrix& setCols(int cols);
    friend Matrix transpose(const Matrix& matrix );
    friend Matrix inverse(const Matrix& matrix);
    friend double determinant(const Matrix& matrix);
    inline friend bool isSizeEquele(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator+(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator-(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator*(const Matrix& matrix1,const Matrix& matrix2);


private:
    Array* m_elements;
    unsigned int m_rows;
    unsigned int m_cols;
};

#endif // MATRIX_H
