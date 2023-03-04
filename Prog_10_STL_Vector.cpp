/*
Objective:
    To demonstrate how to create your own vector (similar to 'std::vector')
*/

#include <iostream>
using namespace std;

template <typename T>
class MyVector
{
    T *_ptr = nullptr;
    long unsigned int _capacity = 1;
    long unsigned int _size = 0;

public:
    MyVector()
    {
        _ptr = new T[_size];
    }

    ~MyVector()
    {
        if (_ptr)
        {
            delete[] _ptr;
            _ptr = nullptr;
        }
    }

    void push_back(T iData)
    {
        if (_size == _capacity)
        {
            _capacity = 2 * _capacity;
            T *pNew = new T[_capacity];
            if (pNew)
            {
                if (_ptr)
                {
                    for (auto idx = 0; idx < _size; idx++)
                    {
                        pNew[idx] = _ptr[idx];
                    }
                    delete[] _ptr;
                }
                _ptr = pNew;
            }
        }

        // After clear, pointer should be allocated to default size
        if (nullptr == _ptr)
        {
            _ptr = new T[_size];
        }
        //

        _ptr[_size++] = iData;
    }

    void pop() { size--; }

    void clear()
    {
        if (_ptr)
        {
            delete[] _ptr;
            _ptr = nullptr;
            _size = 0;
            _capacity = 1;
        }
    }

    long unsigned int size() const
    {
        return _size;
    }

    long unsigned int capacity() const { return _capacity; }

    void print()
    {
        if ((_size != 0) && (_ptr != nullptr))
        {
            for (int idx = 0; idx < _size; idx++)
            {
                cout << _ptr[idx] << " " << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    MyVector<int> obj;
    obj.push_back(11);
    obj.push_back(22);
    obj.push_back(33);
    obj.push_back(44);

    obj.print();

    obj.clear();
    cout << "After Clearing.. " << endl;
    obj.push_back(100);
    obj.print();

    return 0;
}