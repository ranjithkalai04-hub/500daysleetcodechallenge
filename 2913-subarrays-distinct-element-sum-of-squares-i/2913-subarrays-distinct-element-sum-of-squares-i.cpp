class Solution
{
public:
    int sumCounts(vector<int> &nums)
    {

        int n = nums.size();

        int sum = 0;
        
          
        for(int i=0;i<n;i++){
            int cnt = 0;
            set<int> st;
            for(int j=i;j<n;j++){
                if(st.find(nums[j])==st.end())
                
                  {  st.insert(nums[j]);
                    cnt++;  
}
                    sum+=cnt*cnt;
            }
            
        }
        return sum;
    }
};
