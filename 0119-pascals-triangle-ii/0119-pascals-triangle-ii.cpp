class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ansrow=1;
        vector<int>res;
        res.push_back(ansrow);
        for(int i=1; i<=rowIndex; i++){
            ansrow= ansrow*(rowIndex-i+1);
            ansrow= ansrow/i;
            res.push_back(ansrow);
        }
        return res;

    }
};