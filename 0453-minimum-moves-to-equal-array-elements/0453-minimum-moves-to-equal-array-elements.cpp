class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int add= accumulate(nums.begin(), nums.end(), 0);
        int min= *min_element(nums.begin(), nums.end());

        return add-n*min;        
    }
};