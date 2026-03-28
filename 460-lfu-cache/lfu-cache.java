import java.util.*;

class LFUCache {

    // Node class
    // stores key, value and frequency
    class Node {
        int key;
        int value;
        int freq;
        Node prev;
        Node next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1; // initial frequency is 1
        }
    }

    // Doubly Linked List class
    class DLL {

        Node head;
        Node tail;
        int size;

        DLL() {

            // dummy nodes
            head = new Node(0, 0);
            tail = new Node(0, 0);

            head.next = tail;
            tail.prev = head;

            size = 0;
        }

        // add node after head (Most recent)
        void add(Node node) {

            Node temp = head.next;

            head.next = node;
            node.prev = head;

            node.next = temp;
            temp.prev = node;

            size++;
        }

        // remove node
        void remove(Node node) {

            node.prev.next = node.next;
            node.next.prev = node.prev;

            size--;
        }

        // remove least recently used node
        Node removeLast() {

            if (size > 0) {
                Node node = tail.prev;
                remove(node);
                return node;
            }

            return null;
        }
    }

    int capacity;
    int minFreq;

    // key -> node
    HashMap<Integer, Node> keyMap;

    // freq -> doubly linked list
    HashMap<Integer, DLL> freqMap;


    // Constructor
    public LFUCache(int capacity) {

        this.capacity = capacity;

        keyMap = new HashMap<>();
        freqMap = new HashMap<>();

        minFreq = 0;
    }


    // GET function
    public int get(int key) {

        // key not present
        if (!keyMap.containsKey(key)) {
            return -1;
        }

        Node node = keyMap.get(key);

        // update frequency
        update(node);

        return node.value;
    }


    // PUT function
    public void put(int key, int value) {

        if (capacity == 0) return;

        // key already present
        if (keyMap.containsKey(key)) {

            Node node = keyMap.get(key);

            node.value = value;

            // update frequency
            update(node);
        }
        else {

            // cache full
            if (keyMap.size() == capacity) {

                // get LFU list
                DLL list = freqMap.get(minFreq);

                // remove LRU from LFU
                Node remove = list.removeLast();

                keyMap.remove(remove.key);
            }

            // create new node
            Node node = new Node(key, value);

            // reset min frequency
            minFreq = 1;

            // add into freqMap
            DLL list = freqMap.getOrDefault(1, new DLL());

            list.add(node);

            freqMap.put(1, list);

            keyMap.put(key, node);
        }
    }


    // update frequency
    private void update(Node node) {

        int freq = node.freq;

        DLL list = freqMap.get(freq);

        // remove from old freq list
        list.remove(node);

        // update minFreq
        if (freq == minFreq && list.size == 0) {
            minFreq++;
        }

        node.freq++;

        // move to new freq list
        DLL newList = freqMap.getOrDefault(node.freq, new DLL());

        newList.add(node);

        freqMap.put(node.freq, newList);
    }
}