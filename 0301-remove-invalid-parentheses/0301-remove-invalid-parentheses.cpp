class Solution {
public:
    vector<string> ans;

    void removeInvalid(string s, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            int balance = 0;

            for (char c : s) {
                if (c == '(')
                    balance++;
                else if (c == ')') {
                    balance--;
                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.length(); i++) {

            // Avoid removing the same parenthesis repeatedly
            if (i > start && s[i] == s[i - 1])
                continue;

            // Remove '('
            if (lremove > 0 && s[i] == '(') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                removeInvalid(temp, i, lremove - 1, rremove);
            }

            // Remove ')'
            if (rremove > 0 && s[i] == ')') {
                string temp = s.substr(0, i) + s.substr(i + 1);
                removeInvalid(temp, i, lremove, rremove - 1);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int lremove = 0;
        int rremove = 0;

        // Find the minimum number of '(' and ')' that must be removed
        for (char c : s) {
            if (c == '(') {
                lremove++;
            }
            else if (c == ')') {
                if (lremove > 0)
                    lremove--;
                else
                    rremove++;
            }
        }

        removeInvalid(s, 0, lremove, rremove);

        return ans;
    }

};