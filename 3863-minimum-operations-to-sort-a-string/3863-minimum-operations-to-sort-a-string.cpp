class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }

        if(n==2){
            return -1;
        }
        
        char max= *max_element(begin(s), end(s));
        char min= *min_element(begin(s), end(s));

        char min_mid= *min_element(begin(s)+1, end(s)-1);
        char max_mid= *max_element(begin(s)+1, end(s)-1);

        if(s[0]==min || s[n-1]==max){
            return 1;
        }

        if(s[0]>max_mid && min_mid>s[n-1]){
            return 3;
        }

        return 2;
        
    }

};