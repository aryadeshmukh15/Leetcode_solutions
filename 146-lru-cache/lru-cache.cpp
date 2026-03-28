class LRUCache {
public:

    // Node structure
    class Node {
    public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int capacity;

    // hashmap
    unordered_map<int, Node*> map;

    // dummy nodes
    Node* head;
    Node* tail;


    // Constructor
    LRUCache(int capacity) {

        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }


    // delete node
    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }


    // insert at front
    void insertAfterHead(Node* node) {

        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }


    int get(int key) {

        // key not present
        if (map.find(key) == map.end()) {
            return -1;
        }

        Node* node = map[key];

        // move to front
        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }


    void put(int key, int value) {

        // key already exists
        if (map.find(key) != map.end()) {

            Node* existing = map[key];

            deleteNode(existing);
            map.erase(key);
        }

        // capacity full
        if (map.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);
            map.erase(lru->key);
        }

        Node* newNode = new Node(key, value);

        insertAfterHead(newNode);

        map[key] = newNode;
    }
};