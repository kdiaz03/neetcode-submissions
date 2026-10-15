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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        std::vector<ListNode*> linkedList;

        while( curr ) {
            linkedList.push_back(curr);
            curr = curr->next;
        }

        int left = 0;
        int right = (int)linkedList.size() - 1;

        while( left < right ) {
            ListNode* temp = linkedList[left]->next;

            linkedList[left]->next = linkedList[right];
            linkedList[right]->next = temp;

            left++;
            right--;
        }

        linkedList[left]->next = nullptr;
    }
};