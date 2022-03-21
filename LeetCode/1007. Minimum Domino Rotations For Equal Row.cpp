// Author : AdarshGaur

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int tp = 0, bt = 0, n = tops.size();
        bool ok1 = true, ok2 = true;
        for(int i=0; i<tops.size(); i++){
            if(tops[i] == bottoms[i]){
                if(tops[i] != tops[0]) ok1 = false;
                if(tops[i] != bottoms[0]) ok2 = false;
                n--;
                continue;
            }
            if(tops[i] == bottoms[0]) bt++;
            if(bottoms[i] == tops[0]) tp++;
            if(tops[0] != tops[i] and tops[0]!= bottoms[i]) ok1 = false;
            if(bottoms[0] != tops[i] and bottoms[0]!= bottoms[i]) ok2 = false;
            if(!ok1 && !ok2) return -1;
        }
        if(!ok1 and !ok2) return -1;
        if(!ok1) return min(bt, n-bt);
        if(!ok2) return min(tp, n-tp);
        return min(bt, tp);
    }
};

static const auto speedup = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
