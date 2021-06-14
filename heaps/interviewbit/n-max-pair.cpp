/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

https://www.interviewbit.com/problems/n-max-pair-combinations/
*/
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int,pair<int,int>> maxH;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    vector<int> answer;
    int n = A.size();
    //int count = 0;
    set<pair<int,int>> s;
    s.insert({A.size()-1,A.size()-1});
    while(n--){
        if(maxH.empty())
        maxH.push({(A[A.size()-1]+B[B.size()-1]),{A.size()-1,A.size()-1}});
        
        pair<int,pair<int,int> top  = maxH.top();
        maxH.pop();
        
        answer.push_back(top.first);
        
        if(top.second.first>=1 && s.find({top.second.first-1,top.second.second})==s.end())
        {
            maxH.push({(A[top.second.first-1]+B[top.second.second]),{top.second.first-1,top.second.second}});
            s.insert({top.second.first-1,top.second.second});
        }
        
        if(top.second.second >=1 && s.find({top.second.first,top.second.second-1})==s.end()){
            maxH.push({(A[top.second.first-1]+B[top.second.second]),{top.second.first-1,top.second.second}});
            s.insert({top.second.first-1,top.second.second});
        }
        
    }
}
