class Solution {
public:
    bool isPalindrome(int x) {
       long long  copy = x;
        long long  sum =0;
        while(copy>0){
            sum=sum*10;
            sum+=(copy%10);
            copy/=10;
        }
        if(sum==x){
            return true;
        }
        return false;
    }
};