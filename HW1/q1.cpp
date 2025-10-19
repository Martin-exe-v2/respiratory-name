#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    bool result;
    a = 3;
    b = 4;

    // HOMEWORK TODO1: set c to be the sum of a and b
    c = a + b;
    // HOMEWORK TODO2: set d to be the difference of a and b (a - b)
    d = a - b;
    // HOMEWORK TODO3: set e to be the product of c and d
    e = c * d;
    // HOMEWORK TODO4: set f to be a*a-b*b
    f = a * a - b * b;
    // HOMEWORK TODO5: set result to if e is equal to f.
    result = (e == f);

    // output all variables
    cout << "a: " << a << ", b: " << b << endl;
    cout << "c: " << c << ", d: " << d << endl; 
    cout << "e: " << e << ", f: " << f << endl;
    cout << "Is e equal to f? " << (result ? "Yes" : "No") << endl;
    return 0;
}