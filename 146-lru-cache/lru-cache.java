
import java.util.HashMap;

class LRUCache {

    // Node class
    class Node {
        int key;
        int value;
        Node prev;
        Node next;

        Node(int k, int v) {
            key = k;
            value = v;
        }
    }

    int capacity;
    HashMap<Integer, Node> map;

    Node head;
    Node tail;


    // Constructor
    public LRUCache(int capacity) {

        this.capacity = capacity;
        map = new HashMap<>();

        // dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head.next = tail;
        tail.prev = head;
    }


    // delete node
    private void deleteNode(Node node) {

        Node prevNode = node.prev;
        Node nextNode = node.next;

        prevNode.next = nextNode;
        nextNode.prev = prevNode;
    }


    // insert after head
    private void insertAfterHead(Node node) {

        Node temp = head.next;

        head.next = node;
        node.prev = head;

        node.next = temp;
        temp.prev = node;
    }


    public int get(int key) {

        // key not present
        if (!map.containsKey(key)) {
            return -1;
        }

        Node node = map.get(key);

        // move to front
        deleteNode(node);
        insertAfterHead(node);

        return node.value;
    }


    public void put(int key, int value) {

        // if key exists
        if (map.containsKey(key)) {

            Node existing = map.get(key);

            deleteNode(existing);
            map.remove(key);
        }

        // capacity full
        if (map.size() == capacity) {

            Node lru = tail.prev;

            deleteNode(lru);
            map.remove(lru.key);
        }

        Node newNode = new Node(key, value);

        insertAfterHead(newNode);

        map.put(key, newNode);
    }
}
