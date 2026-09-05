class Solution {
public:
    string largestOddNumber(string num) {
        char c;
        int n=num.length();
        string ans;
        int mark;
        for(int i=n-1;i>=0;i--){
            c=num[i];
            if(c%2!=0){
                mark=i;
                break;
            }
        }
        for(int i=0;i<=mark;i++)
        {

            ans+=num[i];
        }
        return ans;
    }
};
/*class Solution {
public:
    string largestOddNumber(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] % 2 != 0) {
                return s.substr(0, i + 1);
            }
        }

        return "";
    }
};*/