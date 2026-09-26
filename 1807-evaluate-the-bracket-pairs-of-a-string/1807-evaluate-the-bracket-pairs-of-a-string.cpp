class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        string key="";
        string res="";
        for(auto& list:knowledge){
            mp[list[0]]=list[1];
        }
        bool flag =false;
        for(char c:s){
            if(c=='('){
                flag=true;
            }
            else if(c==')'){
                if(mp.find(key)!=mp.end()){
                    res+=mp[key];
                }
                else{
                    res+='?';
                }
                flag=false;
                key="";
            }
            else if(flag){
                key+=c;
            }
            else{
                res+=c;
            }
        }
        return res;

    }
};