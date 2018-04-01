#ifndef MATRIX_H
#define MATRIX_H

using namespace std;
#include <stdexcept>
#include <initializer_list>

class Matrix
{
public:
    Matrix() = delete;
    Matrix(const Matrix& matrix);
    Matrix(initializer_list<initializer_list<double>> initList);
    Matrix(unsigned int rows,unsigned int cols);
    Matrix& operator=(const Matrix& matrix);
    ~Matrix();
    double& at(unsigned int row,unsigned int col);
    inline const double &at(unsigned int row,unsigned int col) const;
    Matrix operator *(const Matrix& matr);


    unsigned int getColsCount() {return m_colsCount; }
    unsigned int getRowsCount() {return m_rowsCount; }
private:
    double **m_elements;
    unsigned int m_rowsCount;
    unsigned int m_colsCount;
};

#endif // MATRIX_H
