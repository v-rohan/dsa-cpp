//https://www.interviewbit.com/problems/rain-water-trapped/
int Solution::trap(const vector<int> &A) {
    vector<int> right(A.size());
    vector<int> left(A.size());
    left[0]=A[0];
    for(int i=1; i<A.size(); i++){
        left[i]=max(A[i],left[i-1]);
    }
    right[A.size()-1] = A[A.size()-1];
    for(int i=A.size()-2; i>=0; i--){
        right[i]=max(A[i],right[i+1]);
    }
    int water=0;
    for(int i=0; i<A.size();i++){
        water += min(right[i],left[i])-A[i];
    }
    return water;
}
