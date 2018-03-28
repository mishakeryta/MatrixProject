#include "array.hpp"



//Defoult constructors,one element with value 0
Array::Array():m_elements{new double[1]()},m_lenght{1}
{

}

//Copy constructor
Array::Array(const Array& array):m_elements{new double[array.getLength()]{}} ,m_lenght{array.getLength()}
{
    for(unsigned int i = 0;i < m_lenght;++i)
    {
        m_elements[i] = array[i];
    }
}

Array::Array(initializer_list<double>  in_list)
{
    m_lenght  = in_list.size();
    m_elements = new double[m_lenght]{};
    for(unsigned int i = 0;i<m_lenght;++i)
    {
        m_elements[i] = in_list.begin()[i];
    }
}
Array::Array(unsigned int length,initializer_list<double> in_list)
{
    m_lenght = length;
    m_elements = new double[m_lenght]{};
    for(unsigned int i = 0; i < m_lenght && i < in_list.size();++i)
    {
        m_elements[i] = in_list.begin()[i];
    }
}

Array::~Array()
{
    delete[] m_elements;
}


//operator [] for const object
const double& Array::operator[](unsigned int index) const
{
    if(index >= m_lenght) throw std::out_of_range("Out of range");
    return m_elements[index];
}

//operator [] for normal object
double& Array::operator[](unsigned int index)
{
    if(index >= m_lenght) throw std::out_of_range("Out of range");
    return m_elements[index];
}

Array& Array::setLength(unsigned int lenght)
{
    double* tmp = new double[lenght]{};

    for(unsigned int i = 0;i<lenght && i<m_lenght;++i)
    {
        tmp[i] = m_elements[i];
    }
    m_lenght = lenght;
    delete[] m_elements;
    m_elements = tmp;
    tmp = nullptr;
    return *this;
}

//find something
double Array::findMaxValue() const
{
    double max = m_elements[0];
    for(unsigned int i = 1; i < m_lenght; ++i)
    {
        if(m_elements[i]>max) max = m_elements[i];
    }
    return max;
}

double Array::findMaxNegativeValue() const
{
    double max = m_elements[0];
    for(unsigned int i = 1;i<m_lenght;++i)
    {
        if(m_elements[i]<0)
        {
            if(max >= 0)
            {
                max = m_elements[i];
            }
            else if(max < m_elements[i])
            {
                max = m_elements[i];
            }
        }
    }
    return max;
}

double Array::findMinPositiveValue() const
{
    double min = m_elements[0];
    for(unsigned int i = 1;i < m_lenght;++i )
    {
        if(m_elements[i] > 0)
        {
            if(min <= 0)
            {
                min = m_elements[i];
            }
            else if(min>m_elements[i])
            {
                min = m_elements[i];
            }
        }
    }
    return min;
}

double Array::findMaxAbsValue() const
{
    double max = m_elements[0];
    for(unsigned int i = 1;i < m_lenght; ++i)
    {
        if(fabs(m_elements[i]) > fabs(max))
        {
            max = m_elements[i];
        }
    }
    return max;
}
void swap_arrays(Array &array1, Array &array2)
{
    swap(array1.m_elements,array2.m_elements);
    swap(array1.m_lenght,array2.m_lenght);
}

Array operator +(const Array& array1,const Array& array2)
{
    if(array1.getLength()!=array2.getLength()) throw logic_error("Cant add, inappropriate length");
    Array result(array1.getLength());
    for(unsigned int i = 0;i<array1.getLength();++i)
    {
        result[i] = array1[i] + array2[i];
    }
    return result;
}
Array operator -(const Array& array1,const Array& array2)
{
    if(array1.getLength()!=array2.getLength()) throw logic_error("Cant add, inappropriate length");
    Array result(array1.getLength());
    for(unsigned int i = 0;i<array1.getLength();++i)
    {
        result[i] = array1[i] - array2[i];
    }
    return result;
}
Array operator *(double val1,const Array& array1)
{
    Array result(array1.getLength());
    for(unsigned int i = 0;i<array1.getLength();++i)
    {
        result[i] = val1*array1[i];
    }
    return result;
}
Array& Array::operator *=(double val1)
{
    for(unsigned int i = 0;i<getLength();++i)
    {
        m_elements[i] *= val1;
    }
    return *this;
}
Array& Array::operator=(Array&& array)
{
    swap_arrays(*this,array);
}

Array& Array::operator -=(const Array& array2)
{
    if(m_lenght != array2.getLength()) throw logic_error("Inappropriate arrays size");
    for(unsigned int i = 0;i<array2.getLength();++i)
    {
        m_elements[i] -= array2[i];
    }
    return *this;
}


