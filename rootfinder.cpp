#include "rootfinder.h"
#include <QDebug>


RootFinder::RootFinder(Matrix matrixA,vector<double> vectorB):m_matrixA{matrixA},
m_vectorB{vectorB}{

}

vector<double> RootFinder::findRootsGauss(string& message) {
    message += "Gauss method:\n";
    for(unsigned int diag = 0;diag<m_matrixA.getColsCount() - 1;++diag) {
        message+= "Iteration: " + to_string(diag) + "\n";
        unsigned int rowMaxAbsValue = m_matrixA.findRowMaxAbsValueOn(diag,diag);
        m_matrixA.swapRows(rowMaxAbsValue,diag);
        swap(m_vectorB[diag],m_vectorB[rowMaxAbsValue]);
        for(unsigned int row = diag + 1;row < m_matrixA.getColsCount();++row) {
            double curElementToNull = m_matrixA.at(row,diag);
            for(unsigned int col = 0;col < m_matrixA.getColsCount();++col) {
                m_matrixA.at(row,col)-=(curElementToNull*m_matrixA.at(diag,col))/
                        m_matrixA.at(diag,diag);
               }
            m_vectorB.at(row)  -=(curElementToNull*m_vectorB.at(diag))/m_matrixA.at(diag,diag);
        }
        for(unsigned int row = 0;row < m_matrixA.getRowsCount();++row) {
            for(unsigned int col = 0; col < m_matrixA.getColsCount();++col) {
                message+= to_string(m_matrixA.at(row,col)) + " ";
            }
            message+= to_string(m_vectorB.at(row)) + "\n";
        }
        message+= "\n";


    }
    vector<double> vectorX(m_matrixA.getColsCount());
    for(unsigned int row = m_matrixA.getRowsCount()-1;(row+1) > 0; --row) {
        vectorX.at(row) = m_vectorB.at(row);
        for(unsigned int col = m_matrixA.getColsCount()-1;col > row; --col ) {
            vectorX.at(row) -= m_matrixA.at(row,col)*vectorX.at(col);
        }
        vectorX.at(row) /= m_matrixA.at(row,row);

    }
    message += "Vector X:\n";
    for(unsigned int row = 0;row < vectorX.size();++row) {
        message += to_string(vectorX.at(row))+ " ";
    }
    return vectorX;
}

RootFinder &RootFinder::toTriangel(string& message)
{
    for(unsigned int diag = 0;diag<m_matrixA.getColsCount() - 1;++diag) {
        message+= "Iteration: " + to_string(diag) + "\n";
        unsigned int rowMaxAbsValue = m_matrixA.findRowMaxAbsValueOn(diag,diag);
        m_matrixA.swapRows(rowMaxAbsValue,diag);
        swap(m_vectorB[diag],m_vectorB[rowMaxAbsValue]);
        for(unsigned int row = diag + 1;row < m_matrixA.getColsCount();++row) {
            double curElementToNull = m_matrixA.at(row,diag);
            for(unsigned int col = 0;col < m_matrixA.getColsCount();++col) {
                m_matrixA.at(row,col)-=(curElementToNull*m_matrixA.at(diag,col))/
                        m_matrixA.at(diag,diag);
               }
            m_vectorB.at(row)  -=(curElementToNull*m_vectorB.at(diag))/m_matrixA.at(diag,diag);
        }
        for(unsigned int row = 0;row < m_matrixA.getRowsCount();++row) {
            for(unsigned int col = 0; col < m_matrixA.getColsCount();++col) {
                message+= to_string(m_matrixA.at(row,col)) + " ";
            }
            message+= to_string(m_vectorB.at(row)) + "\n";
        }
        message+= "\n";
    }
}
