// Dynamic array Creation - VECTOR creation

#include <iostream>
using namespace std;

#define DEFAULT_SIZE 1

// Creating customized VECTOR class using template (i.e., class template)
template <typename T>
class MyVector
{
    T *_Ptr = nullptr;
    int _Size;

public:
    MyVector();
    void push_back(T iVal);

    /* Similarly you can implement pop_back, size, etc., */

    void PrintValues();
};

template <typename T>
MyVector<T>::MyVector()
{
    _Size = DEFAULT_SIZE;
}

template <typename T>
void MyVector<T>::push_back(T iVal)
{
    if (nullptr == _Ptr)
        _Ptr = new T[_Size]{iVal};
    else
    {
        // 1) Create New Arr and update values
        T *NewPtr = new T[_Size + 1]; // increment size by 1
        for (int idx = 0; idx < _Size; idx++)
            NewPtr[idx] = _Ptr[idx];
        NewPtr[_Size] = iVal;

        // 2) Update new size
        _Size++;

        // 3) Delete existing arr and update to new array
        if (_Ptr)
        {
            delete[] _Ptr;
            _Ptr = NewPtr;
        }
    }
}

template <typename T>
void MyVector<T>::PrintValues()
{
    if (_Ptr)
    {
        for (int idx = 0; idx < _Size; idx++)
        {
            cout << _Ptr[idx] << " ";
        }
        cout << endl;
    }
}

int main()
{
    MyVector<int> vec;
    vec.push_back(34);
    vec.PrintValues();

    vec.push_back(45);
    vec.push_back(56);
    vec.PrintValues();
}