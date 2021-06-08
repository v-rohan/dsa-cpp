//https://www.interviewbit.com/problems/evaluate-expression/
int Solution::evalRPN(vector<string> &A) {
    stack<string> st;
    for(auto i: A){
        if(i=="+"){
            int op1 = stoi(st.top());
            st.pop();
            int op2 = stoi(st.top());
            st.pop();
            st.push(to_string(op1+op2));
        }
        else if(i=="-"){
            int op1 = stoi(st.top());
            st.pop();
            int op2 = stoi(st.top());
            st.pop();
            st.push(to_string(op2-op1));
        }
        else if(i=="/"){
            int op1 = stoi(st.top());
            st.pop();
            int op2 = stoi(st.top());
            st.pop();
            st.push(to_string(op2/op1));
        }
        else if(i=="*"){
            int op1 = stoi(st.top());
            st.pop();
            int op2 = stoi(st.top());
            st.pop();
            st.push(to_string(op1*op2));
        }
        else{
            st.push(i);
        }
    }
    return stoi(st.top());
}