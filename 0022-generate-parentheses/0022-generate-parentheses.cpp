
class Solution {
public:
    void solve(int open, int close, int n, string current,
               vector<string>& ans) {

        // Base case: used all 2*n brackets
        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Choice 1: Add opening bracket
        if (open < n) {
            solve(open + 1, close, n, current + "(", ans);
        }

        // Choice 2: Add closing bracket
        if (close < open) {
            solve(open, close + 1, n, current + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        solve(0, 0, n, "", ans);

        return ans;
    }
};