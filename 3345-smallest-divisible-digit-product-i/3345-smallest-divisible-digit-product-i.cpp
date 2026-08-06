class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int num=n;;num++){
            int copy=num;
            int prod =1;
            while(copy>0){
                int digit=copy%10;
                prod*=digit;
                copy=copy/10;
            }
            if(prod%t==0)
             return num;
        }
       
    }
};