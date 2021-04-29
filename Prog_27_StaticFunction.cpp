#include<iostream>
using namespace std;

class Demo
{
public:
    static void Greetings() {
        cout << "Hello" << endl;
    }
};

int main()
{
    Demo::Greetings();
    return 0;
}