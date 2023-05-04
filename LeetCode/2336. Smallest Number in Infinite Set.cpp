// Author: @AdarshGaur

class SmallestInfiniteSet {
public:
    set<int> st;
    int count;

    SmallestInfiniteSet() {
        count = 1;
    }
    
    int popSmallest() {
        int smallest = count;
        if(st.empty()){
            count++;
        }else{
            smallest = *(st.begin());
            st.erase(st.begin());
        }
        return smallest;
    }
    
    void addBack(int num) {
        if(num < count){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

