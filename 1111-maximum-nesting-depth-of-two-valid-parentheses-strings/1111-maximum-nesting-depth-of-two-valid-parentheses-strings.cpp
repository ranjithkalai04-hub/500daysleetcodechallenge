class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int>ans;
        for(int i=0; i<seq.length(); i++){
            if(seq[i]=='('){
                depth++;
                ans.push_back(1-(depth%2));
            }
            else{
                ans.push_back(1-(depth%2));
                depth--;
            }
        }
         return ans;
  
        
    }
};