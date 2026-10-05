class Solution {
public:
    int scoreOfParentheses(string s) {
       
        stack<int>st;
        st.push(0);
        
        

        for(char ch:s){
            if(ch=='('){
                st.push(0);
            }
            else if(ch==')'){
                int value;
                int inside=st.top();
                st.pop();
                if(inside==0){
                    value=1;
                }
                else{
                    value=2*inside;
                }
                st.top()+=value;
            }

        }
        return st.top();




    }
};