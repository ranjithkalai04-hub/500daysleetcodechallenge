class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int low=0;
        int high=0;
        for(char ch:s){
            if(ch=='('){
                low++;
                high++;
            }
            else if(ch==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            low=max(0,low);
            if(high<0)return false;
        }
        if(low==0)return true;
        return 0;
    }
};