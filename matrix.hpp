#ifndef MATRIX_H
#define MATRIX_H
#include "array.hpp"
#include <QMainWindow>
#include <QTableWidget>
#include<QDebug>
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

    const Array& operator[](unsigned int row) const;
    Array& operator[](unsigned int row);

    double findMaxAbsValue() const;
    double findMaxNegativeValue()const;
    double findMinPositiveValue() const;
    unsigned int findIndexMaxAbsValueInColumn(unsigned int column,unsigned int startRow) const;

    Matrix& setRows(unsigned int rows); //resize matrix
    Matrix& setCols(unsigned int cols);
    unsigned int getRows() const { return m_rows; }
    unsigned int getCols() const { return m_cols; }

    Matrix transpose();
    Matrix inverse();
    double determinant();
    Matrix minor(unsigned int row,unsigned int col);
    inline friend bool isSizeEquele(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator+(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator+(const Matrix& matrix1,double val);
    inline Matrix operator++() const;
    inline Matrix operator--() const;
    friend Matrix operator -(const Matrix& matrix);
    inline friend Matrix operator+(double val, const Matrix& matrix1);
    friend Matrix operator-(const Matrix& matrix1,const Matrix& matrix2);
    friend Matrix operator*(const Matrix& matrix1,const Matrix& matrix2);

    friend Matrix& operator >>(const QString& str,Matrix& matrix);
    inline friend Matrix& operator <<(Matrix& matrix,const QString& str);
    friend QString& operator <<(QString& str,const Matrix& matrix);
    inline friend QString& operator >> (const Matrix& matrix,QString& str);
    friend Matrix& operator << (Matrix& matrix,const QTableWidget* tbMatrix);
    friend QTableWidget* operator>>(const Matrix& matrix,QTableWidget* tbMatrix);

private:
    Array* m_elements;
    unsigned int m_rows;
    unsigned int m_cols;
};

#endif // MATRIX_H
