#include <iostream>
#include "complexnumber.h"
using namespace std;

int main()
{
    //(1 + 2i), (5 + 6i)
    ComplexNumber a, b;
    cin >> a;
    cin >> b;
    cout << a + b << endl;
    cout << a * b << endl;
    return 0;
}
