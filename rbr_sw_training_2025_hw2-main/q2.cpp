/*
1.
line 29, while (repeat = true)
issue:
Does not compare repeat to true.
Acts as while(true) as it is an assignment, which returns the value assigned (true).
Causes the value of repeat to be ignored.
fix:
while (repeat == true)
2.
line 35, repeat == false;
issue:
Does not set repeat to false. Computes the comparison between repeat and false.
Causes -1 to not properly act as an exit condition.
fix:
repeat = false
3.
line 39, int delta = inp - a;
issue:
Creates a local variable delta and sets it to inp - a. The outer variable delta does not get it's value updated.
This causes the output of final delta to be incorrect.
fix:
delta = inp - a
*/
#include <iostream>
using namespace std;
int main()
{
    int inp = 0;
    int a = 3;
    int delta = 0;
    bool repeat = true;
    while (repeat == true)
    {
        cin >> inp;

        if (inp == -1)
        {
            repeat = false;
        }
        else
        {
            delta = inp - a;
            cout << "Delta: " << delta << ". Enter -1 to exit.\n";
        }
    }

    cout << "Final Delta: " << delta << endl;
    return 0;
}