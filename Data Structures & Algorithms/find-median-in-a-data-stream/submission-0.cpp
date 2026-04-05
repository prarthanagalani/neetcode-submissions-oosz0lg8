class MedianFinder {
public:

   priority_queue<int,vector<int>>maxheap;
   priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxheap.size() == 0 || maxheap.top() >= num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }

        if(maxheap.size() > minheap.size()+1){
            int x = maxheap.top();
            maxheap.pop();
            minheap.push(x);
        }
        else if(minheap.size() > maxheap.size()){
            int x = minheap.top();
            minheap.pop();
            maxheap.push(x);
        }
        
    }
    
    double findMedian() {

        double x = maxheap.top();

        if(maxheap.size() == minheap.size()){
            double y = minheap.top();

            return (double)(x+y)/2;
        }
        else{
            return x;
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */