class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans =strs[0];
        int n=strs.size();
        string str;
        for(int i=1;i<n;i++){
            str=strs[i];
            int m=ans.length();
            for(int j=0;j<m;j++)
            {
                if(ans[j]!=str[j]){
                    ans=ans.substr(0,j);
                }
            }
        }
        return ans;
    }
};
