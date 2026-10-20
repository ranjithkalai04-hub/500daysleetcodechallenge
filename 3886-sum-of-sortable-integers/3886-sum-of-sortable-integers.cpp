class Solution {
public:
bool kmpsearch(vector<int>& pattern, vector<int>& text) {
    int m = pattern.size();
    int n = text.size();

    if (m == 0) return true;
    if (m > n) return false;

    // Build LPS array
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        }
        else if (len > 0) {
            len = lps[len - 1];
        }
        else {
            lps[i++] = 0;
        }
    }

    // Search pattern in text
    i = 0;
    int j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            return true;
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j > 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return false;
}

    bool isrotationpossible(vector<int>&vec1,vector<int>&vec2){
        vector<int>text=vec2;
        text.insert(end(text),begin(vec2),end(vec2));
        return kmpsearch(vec1,text); 
    }
    int sortableIntegers(vector<int>& nums) {
       int n=nums.size();

       vector<int>sorted=nums;
       sort(sorted.begin(),sorted.end());

       int result=0;
       
       for(int k=1;k<=n;k++){
        if(n%k!=0)continue;

        bool valid=true;
         for(int start=0;start<n;start+=k){
            vector<int>vec1(begin(nums)+start,begin(nums)+start+k);
             vector<int>vec2(begin(sorted)+start,begin(sorted)+start+k);
             
             if(!isrotationpossible(vec1,vec2)){
                valid=false;
                break;
             }
         }
         if(valid){
            result+=k;
         }
       }
       return result;
    }
};