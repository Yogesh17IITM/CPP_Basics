// Dynamic array Creation - VECTOR creation

#include <iostream>
#include <cstring>
using namespace std;

// Creating customized VECTOR class using template (i.e., class template)
template <typename T>
class MyVector
{
    T *_pData = nullptr;
    int _size = 1;

public:
    void push_back(const T &iVal)
    {
        if (!_pData)
        {
            _pData = new T[_size]{iVal}; // use { } to initialize array list
        }
        else
        {
            T *pNewData = new T[_size + 1];

            // use memcpy to copy one array data into another of definite size.
            memcpy(pNewData, _pData, _size * sizeof(int)); // notice: _size * sizeof(int)

            delete[] _pData;
            _pData = pNewData; // updated pointer of new size => size+1 with old data.

            // update the new incoming data
            _pData[_size++] = iVal; // assign the input value at size and then increment the size to +1.
        }
    }

    /* Similarly you can implement pop_back, size, etc., */

    void PrintValues()
    {
        try
        {
            if (!_pData)
                throw -999;

            for (int idx = 0; idx < _size; idx++)
            {
                cout << _pData[idx] << " ";
            }
            cout << endl;
        }
        catch (int &e)
        {
            cout << "Nothing to print. No data available." << endl;
        }
    }
};

int main()
{
    MyVector<int> vec;
    vec.push_back(34);
    vec.PrintValues();

    vec.push_back(45);
    vec.push_back(56);
    vec.PrintValues();

    MyVector<int> emptyVec;
    emptyVec.PrintValues();
}