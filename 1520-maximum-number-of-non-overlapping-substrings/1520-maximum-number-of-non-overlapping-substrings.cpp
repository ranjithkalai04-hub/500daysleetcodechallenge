class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n= s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(first[c]==-1){
                first[c]=i;
            }
            last[c]=i;
        }
        vector<pair<int,int>>intervals;
        for(int i=0;i<26;i++){
            
            if(first[i]==-1)continue;
            int l =first[i];
            int r=last[i];
            bool valid=true;
            for(int j=l;j<=r;j++){
                int current=s[j]-'a';
                if(first[current]<l){valid=false;break;}
                r=max(r,last[current]);
            }
            if(valid){
                intervals.push_back({l,r});
            }
        }
        sort(intervals.begin(),intervals.end(),[]( pair<int,int>a,pair<int,int>b){
            return a.second<b.second;
        });
        vector<string>ans;
        int end=-1;
        for(auto interval:intervals){
            int left=interval.first;
            int right=interval.second;
            if(left>end){
                ans.push_back(s.substr(left,right-left+1));
                end=right;
            }  
        }
        return ans;
    }
};