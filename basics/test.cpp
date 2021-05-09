#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
   //   return s;
   stack<char> st;
   string res;
   string buf;
   int multiply = 0;
   ;
   for (int i = 0; i < s.length(); i++)
   {
      buf = "";
      res = "";
      multiply = 1;
      if (s[i] != ']')
         st.push(s[i]);
      else if (s[i] == ']')
      {
         while (st.top() != '[')
         {
            buf = st.top() + buf;
            st.pop();
         }
         st.pop();
         while (!st.empty())
         {
            if (st.top() == '[' || !(st.top()-'0' >=0 && st.top()-'0'<=9 ))
               break;
            res += st.top();
            st.pop();
         }
         reverse(res.begin(), res.end());
         multiply = stoi(res);
         res = "";
         for (int j = 1; j <= multiply; j++)
         {
            res += buf;
         }

         for (int k = 0; k < res.length(); k++)
            st.push(res[k]);
      }
   }
   res="";
   while(!st.empty())
   res += st.top(), st.pop();
   reverse(res.begin(),res.end());
   return res;
}

int main()
{
   string a = decodeString("3[a]2[bc]");
   cout << a  << endl;
}