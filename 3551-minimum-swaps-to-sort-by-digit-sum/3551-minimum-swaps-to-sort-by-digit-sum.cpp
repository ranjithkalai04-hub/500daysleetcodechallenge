
class Solution {
public:
    int getdigitsum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> aftersort(nums);

        auto lambda = [&](int num1, int num2) {
            int sum1 = getdigitsum(num1);
            int sum2 = getdigitsum(num2);

            if (sum1 != sum2)
                return sum1 < sum2;

            return num1 < num2;
        };

        sort(aftersort.begin(), aftersort.end(), lambda);

        unordered_map<int, int> valtoidx;

        for (int i = 0; i < n; i++) {
            valtoidx[nums[i]] = i;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int expected = aftersort[i];
            int currval = nums[i];

            if (expected == currval)
                continue;

            int idx = valtoidx[expected];

            swap(nums[i], nums[idx]);

            valtoidx[expected] = i;
            valtoidx[currval] = idx;

            cnt++;
        }

        return cnt;
    }
};
