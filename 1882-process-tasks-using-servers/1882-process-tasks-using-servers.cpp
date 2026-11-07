class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;

        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans(m);
        long long curTime = 0;

        for (int i = 0; i < m; i++) {
            curTime = max(curTime, (long long)i);

            if (freeServers.empty()) {
                curTime = busyServers.top().first;
            }

            while (!busyServers.empty() && busyServers.top().first <= curTime) {
                int idx = busyServers.top().second;
                busyServers.pop();
                freeServers.push({servers[idx], idx});
            }

            int bestServer = freeServers.top().second;
            freeServers.pop();

            ans[i] = bestServer;
            busyServers.push({curTime + tasks[i], bestServer});
        }

        return ans;
    }
};