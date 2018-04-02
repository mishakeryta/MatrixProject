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
    //Matrix& operator=(const Matrix& matrix);
    ~Matrix();
    double& at(unsigned int row,unsigned int col);
    inline const double &at(unsigned int row,unsigned int col) const;
    Matrix operator *(const Matrix& matr);
    Matrix& swapRows(unsigned int row1,unsigned int row2);

    unsigned int getColsCount()const {return m_colsCount; }
    unsigned int getRowsCount() const{return m_rowsCount; }
private:
    double **m_elements;
    unsigned int m_colsCount;
    unsigned int m_rowsCount;
};

#endif // MATRIX_H
