//Implementation of stack using 2 Queue
#include <iostream>
using namespace std;
#define max 5
int q1[max], q2[max], f1 = -1, r1 = -1, f2 = -1, r2 = -1, data;
void transpose1()
{
    f1++;
    for (int i = 0; i <= r2; i++)
    {
        r1++;
        q1[r1] = q2[f2];
        f2++;
    }
}
void transpose2()
{
    f2++;
    for (int i = 0; i <= r1; i++)
    {
        r2++;
        q2[r2] = q1[f1];
        f1++;
    }
}
void display()
{
    for (int i = 0; i <= r1; i++)
        cout << q1[i] << "\t";
    cout << endl;
}
int main()
{
    int ch;
a:
    cout << "1. Enter 1 to insert" << endl
         << "2. Enter 2 to delete" << endl
         << "3. Enter 3 to display" << endl
         << "4. Enter 4 to exit" << endl
         << "Enter your choice : ";
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter data to be inserted : ";
        cin >> data;
        if (r2 == -1 && r1 == -1)
        {
            f1++;
            r1++;
            q1[r1] = data;
        }
        else if (r1 == -1 && r2 != -1)
        {
            transpose1();
            r1++;
            f1++;
            q1[r1] = data;
        }
        else if (r1 != -1 && r2 == -1)
        {
            if (r1 == max - 1)
            {
                cout << "Queue Overflow" << endl;
            }
            else
            {
                r1++;
                q1[r1] = data;
            }
        }
        goto a;
    }
    else if (ch == 2)
    {
        if (r1 == -1 && r2 == -1)
        {
            cout << "Queue Underflow" << endl;
        }
        if (r1 != -1 && r2 == -1)
        {
            cout << q1[r1] << " Deleted Successfully" << endl;
            r1--;
        }
        if (r1 == -1 && r2 != -1)
        {
            transpose2();
            cout << q1[r1] << " Deleted Successfully" << endl;
            r1--;
        }
        goto a;
    }
    else if (ch == 3)
    {
        display();
        goto a;
    }
    return 0;
}