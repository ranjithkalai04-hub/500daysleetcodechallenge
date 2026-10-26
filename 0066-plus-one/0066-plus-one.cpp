class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int j=n-1;
        while(j>=0 && digits[j]==9){
            digits[j]=0;
            j--;
        }
        if(j>=0){
            digits[j]+=1;
        }
        else{
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};