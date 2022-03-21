// Author : AdarshGaur

class FreqStack {
    unordered_map<int, int> freq;
    vector<vector<int>> v;
public:
    void push(int val) {
        if(freq[val] == v.size())v.push_back(vector<int>());
        v[freq[val]].push_back(val);
        freq[val]++;
    }
    
    int pop() {
        int p = v.back().back();
        v.back().pop_back();
        if(v.back().size() == 0)v.pop_back();
        freq[p]--;
        return p;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

