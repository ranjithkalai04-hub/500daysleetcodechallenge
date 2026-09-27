class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<string>st;
        string curr="";

        for(char ch:s){
            if(ch=='('){
                st.push(curr);
                curr="";
            }
            else if(ch==')'){
                reverse(curr.begin(),curr.end());
                curr=st.top()+curr;
                st.pop();
            }
            else{
                curr+=ch;
            }
        }
        return curr;
       
    }
};
/*
optimal code
class Solution {
public:
    string reverseParentheses(string s) {

        int n = s.size();

        vector<int> pair(n);
        stack<int> st;

        // Step 1: Find matching parentheses
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {

                int j = st.top();
                st.pop();

                pair[i] = j;
                pair[j] = i;
            }
        }

        // Step 2: Traverse with direction
        string ans = "";
        int dir = 1;

        for (int i = 0; i < n; i += dir) {

            if (s[i] == '(' || s[i] == ')') {

                i = pair[i];
                dir = -dir;

            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};*/