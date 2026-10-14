class Solution {
public:
    vector<int> generatorrow(int row){
        long long ansrow=1;
        vector<int>res;
        res.push_back(ansrow);
        for(int i=1; i<row; i++){
            ansrow= ansrow*(row-i);
            ansrow= ansrow/i;
            res.push_back(ansrow);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generatorrow(i));
        }
       return ans; 
    }
};