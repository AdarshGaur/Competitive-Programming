// Author : @AdarshGaur

class Solution {
public:
    
    bool dfs(vector<int>& L, vector<int>& R, int cur, vector<bool>& vis){
        vis[cur] = true;
        
        bool valid = true;
        if(L[cur] != -1){
            if(vis[L[cur]] == true) return false;
            valid = dfs(L, R, L[cur], vis);
        }
        if(!valid) return false;
        
        if(R[cur] != -1){
            if(vis[R[cur]] == true) return false;
            valid = dfs(L, R, R[cur], vis);
        }
        return valid;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // first find the root;
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++){
            if(leftChild[i] != -1)
                indeg[leftChild[i]]++;
            if(rightChild[i] != -1)
                indeg[rightChild[i]]++;
        }
        
        int root = 0;
        for(int i=0; i<n; i++)
            if(indeg[i] == 0)
                root = i;
        
        vector<bool> vis(n, false);
        if( dfs(leftChild, rightChild, root, vis) == false)
            return false;
        
        for(auto i: vis)
            if(!i)
                return false;
        return true;
    }
};
