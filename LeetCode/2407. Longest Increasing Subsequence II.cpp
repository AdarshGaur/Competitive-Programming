// Author : @AdarshGaur

class Solution {
public:
    int getMid(int s, int e){
        return s + (e - s) / 2;
    }

    int MaxUtil(int* st, int ss, int se, int l, int r, int node){
        if (l <= ss && r >= se)
            return st[node];
        if (se < l || ss > r)
            return -1;
        int mid = getMid(ss, se);
        return max(MaxUtil(st, ss, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, se, l, r, 2 * node + 2));
    }

    void updateValue(int arr[], int* st, int ss, int se, int index, int value, int node){
        if (index < ss || index > se){
            cout << "Invalid Input" << endl;
            return;
        }

        if (ss == se){
            arr[index] = value;
            st[node] = value;
        }else {
                int mid = getMid(ss, se);
                if (index >= ss && index <= mid)
                    updateValue(arr, st, ss, mid, index, value, 2 * node + 1);
                else
                    updateValue(arr, st, mid + 1, se, index, value, 2 * node + 2);
                st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        }
        return;
    }

    int getMax(int* st, int n, int l, int r){
        if (l < 0 || r > n - 1 || l > r){
            printf("Invalid Input");
            return -1;
        } 
        return MaxUtil(st, 0, n - 1, l, r, 0);
    }


    int constructSTUtil(int arr[], int ss, int se, int* st, int si){
        if (ss == se){
            st[si] = arr[ss];
            return arr[ss];
        }

        int mid = getMid(ss, se);     
        st[si] = max(constructSTUtil(arr, ss, mid, st, si * 2 + 1), constructSTUtil(arr, mid + 1, se, st, si * 2 + 2));
        return st[si];
    }

    int* constructST(int arr[], int n){
        int x = (int)(ceil(log2(n)));
        int max_size = 2 * (int)pow(2, x) - 1;
        int* st = new int[max_size];
        constructSTUtil(arr, 0, n - 1, st, 0);
        return st;
    }
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int N = 1e5 +7;
        int a[N];
        memset(a, 0, sizeof(a));
        
        int* st = constructST(a, N);
        
        int ans = 0;
        for(int &i: nums){
            int get = getMax(st, N, max(0, i-k), max(0, i-1));
            ans = max(ans, get+1);
            if(getMax(st, N, i, i) < get+1)
                updateValue(a, st, 0, N-1, i, get+1, 0);
        }
        return ans;
    }
};
