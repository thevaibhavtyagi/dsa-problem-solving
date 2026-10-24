class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto getDay = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            int total = d;
            for (int i = 0; i < m - 1; i++) {
                total += days[i];
            }
            return total;
        };

        int a1 = getDay(arriveAlice);
        int a2 = getDay(leaveAlice);
        int b1 = getDay(arriveBob);
        int b2 = getDay(leaveBob);

        int start = max(a1, b1);
        int end = min(a2, b2);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};