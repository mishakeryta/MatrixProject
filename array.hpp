#ifndef ARRAY_H
#define ARRAY_H
#include <initializer_list>
#include <exception>
#include <stdexcept>
#include <cmath>
using namespace std;


class Array
{

    public:
    Array();
    Array(unsigned int lenght):m_elements{new double[lenght]{}},m_lenght{lenght} { }
    Array(const Array& array);
    Array(initializer_list< double > in_list);
    Array(unsigned int length,initializer_list<double> in_list);
    ~Array();
    //Array(Array&& array);
    double findMaxValue() const;
    double findMaxAbsValue() const;
    double findMaxNegativeValue()const;
    double findMinPositiveValue() const;
    Array& operator*=(double val1);
    Array& operator-=(const Array array2);
    friend Array operator+(const Array& array1,const Array& array2);
    friend Array operator-(const Array& array1,const Array& array2);
    friend Array operator*(double val1,const Array& array);

    Array& setLength(unsigned int length);
    unsigned int getLength() const  {return m_lenght;}
    const double& operator[](unsigned int index) const;
    double& operator[](unsigned int index);
    static void swap(Array& array1,Array& array2);



    private:
    double* m_elements;
    unsigned int m_lenght;

};

#endif // ARRAY_H
