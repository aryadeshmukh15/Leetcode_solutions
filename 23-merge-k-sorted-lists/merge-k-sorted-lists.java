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
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        // min heap
        PriorityQueue<ListNode> pq =
                new PriorityQueue<>((a,b) -> a.val - b.val);

        // add first node of all lists
        for(ListNode list : lists){
            if(list != null){
                pq.add(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;

        while(!pq.isEmpty()){

            ListNode node = pq.poll();

            temp.next = node;
            temp = temp.next;

            if(node.next != null){
                pq.add(node.next);
            }
        }

        return dummy.next;
    }
}