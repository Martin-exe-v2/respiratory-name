/*
Give your answer to part 1 here.

a.
This one is given to you as an example.

#include <iostream>
using namespace std;
int main() {
    char inp[8];
    cin >> inp;
    cout << inp << endl;
    return 0;
}

Runtime error.
The code declares an array of size 8 to hold a string input.
If the user inputs a string longer than 7 characters (plus the null terminator),
it will cause a buffer overflow, leading to a runtime error.

b.

int main() {
    int a = "hello" / "world";
    return 0;
}

Runtime error.
"/" operator does not accept string operands of any form.
As int a is defined as string/string, a runtime error will occur when the program is run.

c.

#include <iostream>
using namespace std;
int main()
{
    int myNum = 5;
    if (myNum < 10)
    {
        cout << "myNum is greater than 10" << endl;
    }
    else
    {
        cout << "myNum is 10 or less" << endl;
    }
}

Logic error.
The "<" operator is being used in place of ">", causing the code to give an unintended result.
Alternatively, the cout statements are incorrectly written.

d.

int main()
{
    int a = 4;
    int b = 0;
    int c = a / b;
}

Runtime error.
The code divides by 0 while trying to set the value of int c, which causes an exception.

Your answers to parts b, c, and d should end before this line.
*/

/*
Part 2:
Explain the what the following code is trying to do.
Find the bug making the results wrong
Document why and how it happens.
Write a simple fix for it.


What is the code trying to do?

Divide a by b, and return the result as a %

What is the bug?

percent returns 0 when it should be 75

Why and how does it happen?

division with 2 ints truncates the output 

How to fix it?

static cast at least one of the values as a float in the operand

*/

#include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int b = 4;
    int percent = ((float)a / b) *100;
    cout << percent << "%" << endl;
    return 0;  // returning 0 for main() just means the program ended successfully
}
