class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9+7;
        long long dp=1;
        long long last[26]={};
        for(char c :s){
            int x= c-'a';
            long long old=dp;
            dp=(2*dp-last[x]+mod)%mod;
            last[x]=old;
        }
        return (dp-1+mod)%mod;

    }
};