// Author : @AdarshGaur

class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<>> mn;
    
    void addNum(int num) {
        if(!mx.empty() and mx.top() >= num)
            mx.push(num);
        else
            mn.push(num);
        if(mx.size()+1 < mn.size()){
            mx.push(mn.top());
            mn.pop();
        }else if(mn.size()+1 < mx.size()){
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        if(mx.size() == mn.size())
            return (mx.top() + mn.top())/(double)2.0;
        return (mx.size() > mn.size() ? mx.top(): mn.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
