// Author : @AdarshGaur

class MyCircularQueue {
public:
    vector<int> q;
    int front = -1, rear = -1, sz, count = 0;
    
    MyCircularQueue(int k) {
        q.resize(k);
        sz = k;
    }
    
    bool enQueue(int value) {
        if(count == sz)
            return false;
        count++;
        rear = (rear+1) %sz;
        q[rear] = value;
        if(front == -1)
            front = rear;
        return true;
    }
    
    bool deQueue() {
        if(count == 0)
            return false;
        count--;
        front = (front+1) % sz;
        return true;
    }
    
    int Front() {
        if(count == 0)
            return -1;
        return q[front];
    }
    
    int Rear() {
        if(count == 0)
            return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
