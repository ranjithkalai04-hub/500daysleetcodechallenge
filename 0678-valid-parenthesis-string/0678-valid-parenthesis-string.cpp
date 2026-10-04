class Solution {
public:
    bool checkValidString(string s) {

        int leftMin = 0;
        int leftMax = 0;

        for (char c : s) {

            if (c == '(') {
                leftMin++;
                leftMax++;
            }

            else if (c == ')') {
                leftMin--;
                leftMax--;
            }

            else { // '*'
                leftMin--;  // '*' can become ')'
                leftMax++;  // '*' can become '('
            }

            // We cannot have more ')' than '('
            if (leftMax < 0)
                return false;

            // Minimum cannot stay negative
            if (leftMin < 0)
                leftMin = 0;
        }

        return leftMin == 0;
    }
};
        /*
        int leftmin=0;
        int leftmax=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                leftmin++;
                leftmax++;
            }
            else if(s[i]==')'){
                leftmin--;
                leftmax--;
            }
            else{
                leftmin--;
                leftmax++;
            }
        }
        if(leftmax<0){
          return false;
        }
        if(leftmin<0){
            leftmin=0;
        }
        return leftmin==0;

    }
};*/