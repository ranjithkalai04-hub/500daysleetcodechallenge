class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
      int mini=*min_element(nums1.begin(),nums1.end());
      for(int x:nums1){
      if(x%2==0 && x== mini)
      {
      bool alleven=true;
      
      for(int y:nums1){
        if(y%2!=0) alleven=false;
      }
      if(!alleven) return false;
      }

    }
      return true;
    }
};