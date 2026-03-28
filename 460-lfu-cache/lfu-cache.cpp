class LFUCache {
public:

    class Node {
    public:
        int key, value, freq;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
            prev = next = NULL;
        }
    };

    class DLL {
    public:
        Node* head;
        Node* tail;
        int size;

        DLL() {
            head = new Node(0,0);
            tail = new Node(0,0);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void add(Node* node) {

            Node* temp = head->next;

            head->next = node;
            node->prev = head;

            node->next = temp;
            temp->prev = node;

            size++;
        }

        void remove(Node* node) {

            node->prev->next = node->next;
            node->next->prev = node->prev;

            size--;
        }

        Node* removeLast() {

            if(size > 0){
                Node* node = tail->prev;
                remove(node);
                return node;
            }

            return NULL;
        }
    };

    int capacity;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, DLL*> freqMap;


    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }


    int get(int key) {

        if(keyMap.find(key) == keyMap.end()){
            return -1;
        }

        Node* node = keyMap[key];

        update(node);

        return node->value;
    }


    void put(int key, int value) {

        if(capacity == 0) return;

        if(keyMap.find(key) != keyMap.end()){

            Node* node = keyMap[key];
            node->value = value;

            update(node);
        }
        else{

            if(keyMap.size() == capacity){

                DLL* list = freqMap[minFreq];
                Node* remove = list->removeLast();

                keyMap.erase(remove->key);
            }

            Node* node = new Node(key,value);

            minFreq = 1;

            if(freqMap.find(1) == freqMap.end()){
                freqMap[1] = new DLL();
            }

            freqMap[1]->add(node);
            keyMap[key] = node;
        }
    }


    void update(Node* node){

        int freq = node->freq;

        DLL* list = freqMap[freq];

        list->remove(node);

        if(freq == minFreq && list->size == 0){
            minFreq++;
        }

        node->freq++;

        if(freqMap.find(node->freq) == freqMap.end()){
            freqMap[node->freq] = new DLL();
        }

        freqMap[node->freq]->add(node);
    }
};