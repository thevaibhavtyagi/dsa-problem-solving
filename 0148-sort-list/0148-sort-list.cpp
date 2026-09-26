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
    ListNode* sortList(ListNode* head) {
        vector<int> v;

        ListNode* temp = head;

        while(temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        sort(v.begin(), v.end());

        temp = head;
        for(auto x : v) {
            temp->val = x;
            temp = temp->next;
        }

        return head;
    }
};