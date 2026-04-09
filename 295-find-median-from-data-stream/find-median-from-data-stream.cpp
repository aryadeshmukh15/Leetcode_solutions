class MedianFinder {
public:

    // Max heap -> stores smaller half
    priority_queue<int> maxHeap;

    // Min heap -> stores larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Constructor
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // Step 1: push into maxHeap
        maxHeap.push(num);

        // Step 2: move largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: balance heaps
        if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        // If equal size → even number of elements
        if(maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // If odd → maxHeap has extra element
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */