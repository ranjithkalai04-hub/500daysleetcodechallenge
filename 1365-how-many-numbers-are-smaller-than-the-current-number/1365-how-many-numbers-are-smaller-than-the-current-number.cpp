class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]<nums[i])
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
/*
 int count[101] = {0};

        // Count frequency
        for (int x : nums) {
            count[x]++;
        }

        // Prefix sum
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }

        vector<int> ans;

        for (int x : nums) {
            if (x == 0)
                ans.push_back(0);
            else
                ans.push_back(count[x - 1]);
        }

        return ans;

*/