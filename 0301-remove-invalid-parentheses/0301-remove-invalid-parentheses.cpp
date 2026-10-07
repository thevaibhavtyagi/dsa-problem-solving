class Solution {
public:
    bool isValid(string str) {
        int bal = 0;
        for (char ch : str) {
            if (ch == '('){
                bal++;
            }
            else if (ch == ')') {
                bal--;
            }

            if (bal < 0) {
                return false;
            }
        }
        return bal == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string nxt = curr.substr(0, i) + curr.substr(i + 1);

                if (vis.find(nxt) == vis.end()) {
                    vis.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        return ans;
    }
};