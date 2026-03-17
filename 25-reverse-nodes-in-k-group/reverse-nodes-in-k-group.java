/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    // Function to get kth node
    public ListNode getKthNode(ListNode temp, int k) {
        k -= 1;
        while(temp != null && k > 0){
            temp = temp.next;
            k--;
        }
        return temp;
    }

    // Reverse a linked list
    public ListNode reverseLinkedList(ListNode head){
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null){
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    public ListNode reverseKGroup(ListNode head, int k) {

        ListNode temp = head;
        ListNode prevLast = null;

        while(temp != null){

            // Step 1: find kth node
            ListNode KthNode = getKthNode(temp, k);

            if(KthNode == null){
                if(prevLast != null) prevLast.next = temp;
                break;
            }

            // Step 2: store next group
            ListNode nextNode = KthNode.next;

            // Step 3: break the group
            KthNode.next = null;

            // Step 4: reverse current group
            ListNode newHead = reverseLinkedList(temp);

            // Step 5: connect previous group
            if(prevLast == null){
                head = newHead;
            } else {
                prevLast.next = newHead;
            }

            // Step 6: update prevLast
            prevLast = temp;

            // Step 7: move to next group
            temp = nextNode;
        }

        return head;
    }
}