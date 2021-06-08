//https://www.interviewbit.com/problems/largest-rectangle-in-histogram/
int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st;
    vector<int> l;
    vector<int> r;
    for(int i=0; i<A.size(); i++)
    {
        if(st.empty())
        l.push_back(-1);
        else if(A[st.top()]<A[i])
        l.push_back(st.top());
        else{
            while(!st.empty() && A[st.top()]>= A[i])
            st.pop();
            if(st.empty())
            l.push_back(-1);
            else
            l.push_back(st.top());
        }
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=A.size()-1; i>=0; i--)
    {
        if(st.empty())
        r.push_back(A.size());
        else if(A[st.top()]<A[i])
        r.push_back(st.top());
        else{
            while(!st.empty() && A[st.top()]>= A[i])
            st.pop();
            if(st.empty())
            r.push_back(A.size());
            else
            r.push_back(st.top());
        }
        st.push(i);
    }
    reverse(r.begin(),r.end());
    int area= INT_MIN;
    for(int i=0; i<A.size(); i++){
        area = max(area, ((r[i]-l[i]-1)*A[i]));
    }
    return area;
}