class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }

        int validCount = 0;

        for (int num = 100; num < 1000; num += 2) {
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;

            std::vector<int> needed(10, 0);
            needed[d1]++;
            needed[d2]++;
            needed[d3]++;

            if (needed[d1] <= count[d1] &&
                needed[d2] <= count[d2] &&
                needed[d3] <= count[d3]) {
                validCount++;
            }
        }

        return validCount;
    }
};