#ifndef ROOTFINDER_H
#define ROOTFINDER_H

using namespace std;
#include "matrix.hpp"
#include <vector>
#include <string>
class RootFinder
{
public:
    RootFinder(Matrix matrixA, vector<double> vectorB);

    vector<double> findRootsGauss(string& message);
private:
    Matrix m_matrixA;
    vector<double> m_vectorB;
    RootFinder& toTriangel(string& message);
};

#endif // ROOTFINDER_H
