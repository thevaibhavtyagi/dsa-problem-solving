class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> lastSeen(26, -1);
        vector<int> newParent = parent;

        auto findNewParents = [&](auto& self, int u) -> void {
            int charIdx = s[u] - 'a';
            int prevAncestor = lastSeen[charIdx];

            if (prevAncestor != -1) {
                newParent[u] = prevAncestor;
            }

            lastSeen[charIdx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }

            lastSeen[charIdx] = prevAncestor;
        };

        findNewParents(findNewParents, 0);

        vector<vector<int>> newAdj(n);
        for (int i = 1; i < n; ++i) {
            newAdj[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        auto calcSizes = [&](auto& self, int u) -> void {
            for (int v : newAdj[u]) {
                self(self, v);
                ans[u] += ans[v];
            }
        };

        calcSizes(calcSizes, 0);
        return ans;
    }
};