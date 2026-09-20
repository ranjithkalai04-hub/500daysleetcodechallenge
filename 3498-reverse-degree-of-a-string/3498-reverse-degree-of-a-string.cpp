class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(abs(s[i-1]-'z')+1)*i;
        }
        return sum;
    }
};