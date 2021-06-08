// Problem Description
//https://www.interviewbit.com/problems/maxspprod/

// PARTIALLY CORRECT

// You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
// Write a program to find the maximum special product of any integer in the array.

// NOTE: As the answer can be large, output your answer modulo 109 + 7.



// Problem Constraints
// 1 <= N <= 105
// 1 <= A[i] <= 109



// Input Format
// First and only argument is an integer array A.



// Output Format
// Return an integer denoting the maximum special product of any integer.



// Example Input
// Input 1:

//  A = [1, 4, 3, 4]
// Input 2:

//  A = [10, 7, 100]


// Example Output
// Output 1:

//  3
// Output 2:

//  0


// Example Explanation
// Explanation 1:

//  For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
//  So, the ans is 1*3 = 3.
 
// Explanation 2:

//  There is not any integer having maximum special product > 0. So, the ans is 0.
#define modulo 1000000007
int Solution::maxSpecialProduct(vector<int> &A) {
    int maximum=INT_MIN;
    stack<int>st;
    vector<int> l;
    vector<int> r;
    for(int i=0; i<A.size(); i++){
        if(st.empty())
        l.push_back(0);
        else if(A[st.top()]>A[i]){
            l.push_back(st.top());
        }else if(A[st.top()]<= A[i] && !st.empty()){
            while(!st.empty() && A[st.top()]<= A[i])
            st.pop();
            if(st.empty())
            l.push_back(0);
            else l.push_back(st.top());
        }
        st.push(i);
    }
   // cout << "loop1" << endl;
    while(!st.empty())st.pop();
    for(int i=A.size()-1; i>=0; i--){
        if(st.empty())
        r.push_back(0);
        else if(A[st.top()]>A[i]){
            r.push_back(st.top());
        }else if (A[st.top()]<= A[i] && !st.empty()){
            while(!st.empty() && A[st.top()]<= A[i])
            st.pop();
            if(st.empty())
            r.push_back(0);
            else r.push_back(st.top());
        }
        st.push(i);
    }
   // cout << "loop2" << endl;
    reverse(r.begin(),r.end());
    for(int i=0; i<A.size(); i++){
        maximum = max(((l[i]%modulo * r[i]%modulo)%modulo),maximum);
    }
    return maximum;
}
