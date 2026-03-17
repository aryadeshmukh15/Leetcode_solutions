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

    // Function to get kth node
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != NULL && k > 0){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    // Reverse a linked list
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev; // new head
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while(temp != NULL){

            // Step 1: find kth node
            ListNode* KthNode = getKthNode(temp, k);

            if(KthNode == NULL){
                if(prevLast) prevLast->next = temp;
                break;
            }

            // Step 2: store next group
            ListNode* nextNode = KthNode->next;

            // Step 3: break the group
            KthNode->next = NULL;

            // Step 4: reverse current group
            ListNode* newHead = reverseLinkedList(temp);

            // Step 5: connect previous group
            if(prevLast == NULL){
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            // Step 6: update prevLast
            prevLast = temp;

            // Step 7: move to next group
            temp = nextNode;
        }

        return head;
    }
};