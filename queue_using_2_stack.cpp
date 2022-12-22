//Implementation of Queue using 2 stacks.

#include <iostream>
using namespace std;
#define max 5
int s1[max], s2[max], t1 = -1, t2 = -1,data;
void transpose1()
{
    for (; t1 >= 0; t1--)
    {
        t2++;
        s2[t2] = s1[t1];
    }
}
void transpose2()
{
    for (; t2 >= 0; t2--)
    {
        t1++;
        s1[t1] = s2[t2];
    }
}
void insert()
{
            cout << "Enter the data to be inserted : ";
            cin >> data;
            if (t1 == max - 1)
            {
                cout << "Stack Overflow" << endl;
            }
            else
            {
                t1++;
                s1[t1] = data;
                cout << "Data inserted Successfully" << endl;
            }
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
        if (t1 == -1 && t2 == -1)
        {
            cout << "Enter the data to be inserted : ";
            cin >> data;
            t1++;
            s1[t1] = data;
            cout << "Data inserted Successfully" << endl;
            goto a;
        }
        if (t1 > -1)
        {   insert();
            goto a;
        }
        if (t1 == -1 && t2 > -1)
        {
            transpose2();
            insert();
            goto a;
        }
    }
    if (ch == 2)
    {
        if (t2 == -1 && t1 > -1)
        {
            transpose1();
        }
        if (t2 == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << s2[t2] << "\tData deleted Successfully" << endl;
            t2--;
        }
        goto a;
    }
    if (ch == 3)
    {
        transpose2();
        for (int i = 0; i <= t1; i++)
        {
            cout << s1[i] << "\t";
        }
        cout << endl;
        goto a;
    }
    return 0;
}
