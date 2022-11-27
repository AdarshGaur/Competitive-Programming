// Author : @AdarshGaur

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int overlap;
        int len = min(ax2, bx2) - max(ax1, bx1);
        int height = min(ay2, by2) - max(ay1, by1);
        if(len <= 0 or height <= 0) overlap = 0;
        else overlap = len * height;
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) -overlap;
    }
};
