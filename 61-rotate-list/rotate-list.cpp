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

    // Find nth node (1-based index)
    ListNode* findNthNode(ListNode* temp, int k){
        int cnt = 1;
        while(temp != NULL){
            if(cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return NULL;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        // Edge case
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // Step 1: find length and tail
        int len = 1;
        ListNode* tail = head;

        while(tail->next != NULL){
            tail = tail->next;
            len++;
        }

        // Step 2: reduce k
        k = k % len;
        if(k == 0) return head;

        // Step 3: make circular
        tail->next = head;

        // Step 4: find new tail
        ListNode* newLastNode = findNthNode(head, len - k);

        // Step 5: set new head
        ListNode* newHead = newLastNode->next;

        // Step 6: break circle
        newLastNode->next = NULL;

        return newHead;
    }
};