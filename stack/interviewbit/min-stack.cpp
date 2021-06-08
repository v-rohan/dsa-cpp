/*https://www.interviewbit.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
*/
stack<int> st;
int minEle;

MinStack::MinStack()
{
    while(!st.empty()) st.pop();
    minEle = -1;
}

void MinStack::push(int x)
{
    if(st.empty()==1)
    {
        st.push(x);
        minEle=x;
    }
    else if(x>=minEle)
    {
        st.push(x);
    }
    else
    {
        st.push(2*x-minEle);
        minEle=x;
    }
}

void MinStack::pop() 
{
    if(st.empty()==1)
    return;
    if(st.top()>=minEle)
    {
        st.pop();
    }
    else
    {
        int c=st.top();
        st.pop();
        minEle=2*minEle-c;
    }
}

int MinStack::top() 
{
    if(st.empty()==1)
    return -1;
    if(st.top()>=minEle)
    return st.top();
    else
    {
        return minEle;
    }
}

int MinStack::getMin()
{
    if(st.empty()==1)
    return -1;
    return minEle;
}

