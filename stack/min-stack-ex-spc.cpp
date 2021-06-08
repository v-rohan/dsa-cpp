#include <bits/stdc++.h>
using namespace std;
stack<int> s;
stack<int> ss;

int getMin()
{
    if (ss.empty())
        return -1;
    else
        return ss.top();
}
int pop()
{
    if (s.top() == ss.top())
        ss.pop();
    s.pop();
}

int push(int num)
{
    s.push(num);
    if (ss.empty())
        ss.push(num);
    else if (num <= ss.top())
        ss.push(num);
}
int main()
{
    cout << "Min stack\n";
    while (true)
    {
        int a;
        cin >> a;
        switch (a)
        {
        case 1:
            int input;
            cin >> input;
            push(input);
            break;
        case 2:
            pop();
            break;
        case 3:
            cout << getMin() << endl;
            break;
        default:
            break;
        }
    }
}