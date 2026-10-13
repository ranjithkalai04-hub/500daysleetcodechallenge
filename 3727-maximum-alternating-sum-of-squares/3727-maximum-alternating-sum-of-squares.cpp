class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            nums[i]=nums[i]*nums[i];
        }
        nth_element(begin(nums), begin(nums)+n/2, end(nums));

        long long largest = accumulate(begin(nums)+n/2,  end(nums), 0LL);
        long long smallest = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largest - smallest;

    }

};