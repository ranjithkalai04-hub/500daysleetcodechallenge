class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string word;
        string ans;
        for(char ch :s){
            if(ch!=' '){
                word+=ch;
            }
            else if(!word.empty()){
                st.push(word);
                word="";
            }
        }
        if(!word.empty()){
            st.push(word);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
           if(!st.empty()) {
                ans+=" ";
            }
        }
        return ans;
    }
};