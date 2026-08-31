/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1;
        int minDist = INT_MAX;
        int pos = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next) {
            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                if (first == -1)
                    first = pos;
                else
                    minDist = min(minDist, pos - last);

                last = pos;
            }

            prev = curr;
            curr = next;
            pos++;
        }

        if (first == last)
            return {-1, -1};

        return {minDist, last - first};
    }
};