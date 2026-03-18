/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;

        Node* temp = head;

        // STEP 1: Insert copy nodes in between
        while(temp != NULL){
            Node* nextElement = temp->next;

            Node* copy = new Node(temp->val); // FIXED

            copy->next = nextElement;
            temp->next = copy;

            temp = nextElement;
        }

        // STEP 2: Connect random pointers
        temp = head;
        while(temp != NULL){
            if(temp->random != NULL){
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }

        // STEP 3: Separate the lists
        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL){
            Node* copy = temp->next;

            res->next = copy;
            res = res->next;

            temp->next = copy->next; // restore original list
            temp = temp->next;
        }

        return dummy->next;
    }
};