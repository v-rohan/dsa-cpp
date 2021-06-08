#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int minElem = -1;

int getMin()
{
    if (s.empty())
        return -1;
    else
        return minElem;
}
int pop()
{
    if(s.empty()) return -1;
    if (s.top() < minElem)
        minElem = 2 * minElem - s.top();
    s.pop();
}

int push(int num)
{
    if (s.empty())
    {
        s.push(num);
        minElem = num;
    }
    else if (num < minElem)
    {
        s.push((2 * num) - minElem);
        minElem = num;
    }
    else if (num >= minElem)
        s.push(num);
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