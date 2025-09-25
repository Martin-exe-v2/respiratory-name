#include <iostream>
using namespace std;

/**
 * Example comment for a function
 * exampleFunction takes in two parameters, an integer and a boolean
 * if the boolean is true, it prints the integer
 * it returns nothing (void)
 */
void exampleFunction(int param1, bool param2)
{
    // this is an example function
    if (param2) {
        cout << "param1 is " << param1 << endl;
    } else {
        cout << "param1 is not printed" << endl;
    }
}

/**
 * HOMEWORK TODO 1: write the comments for the function "secret".
 * 
 * You should describe what the function does, its parameters, and its return value.
 * Use the exampleFunction above as a reference.
 * 
 * 
 */

 /**
  * secret takes in 3 parameters, x, y and z
  * @param x: int
  * @param y: int
  * @param z: bool
  * 
  * @return if x > y or z, returs true
  * else returns false
  */
bool secret(int x, int y, bool z)
{
    if (x > y || z) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    // HOMEWORK TODO 2: give the results of each function call

    exampleFunction(5, true);
    // result 1: "param1 is 5" is printed

    exampleFunction(10, false);
    // result 2: "param1 is not printed" is printed

    bool result = secret(3, 4, false);
    // result 3: result is false

    result = secret(5, 2, false);
    // result 4: result is true

    result = secret(1, 1, true);
    // result 5: result is true

    return 0;
}