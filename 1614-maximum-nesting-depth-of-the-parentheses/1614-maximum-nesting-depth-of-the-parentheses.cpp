class Solution {
public:
    int maxDepth(string s) {
      int cnt=0;
      int maxi=0;
     int n=s.length();
      for(char ch:s){
        if(ch=='('){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else if(ch==')'){
             cnt-=1;      
            
        }
        else continue;
      }  
      return maxi;
    }
};