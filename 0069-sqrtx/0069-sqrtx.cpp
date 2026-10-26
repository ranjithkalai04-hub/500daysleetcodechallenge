class Solution {
public:
    int mySqrt(int x) {
        int low=0;
        int high =x;
        long long sqrt;
        while(low<=high){
            int mid=low + (high - low) / 2;
            sqrt=1LL*mid*mid;
            if(sqrt<=x){
                low=mid+1;
            }
            else{
                 high=mid-1;   
            }
        }
        return high ;
    }
};