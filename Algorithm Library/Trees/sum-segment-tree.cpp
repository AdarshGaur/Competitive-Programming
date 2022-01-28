// Segment Tree
// Simple Sum Segment Tree
// Time Complexity lies in O(N)
// Space Complexity is O(4*N)

const int N = 1e5 +5;
int n;
int tree[4*N];
int arr[N];

// - O(n)
void build(int node, int start, int end){
	// initialize the seg tree nodes
	if(start > end){
		return;
	}
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	int lchild = node << 1;
	int rchild = left+1;
	build(lchild, start, mid);
	build(rchild, mid+1, end);
	tree[node] = tree[lchild] + tree[rchild];
}


// - O(logn)
int sum(int node, int start, int end, int left, int right){
	// return the sum of the range [left, right]
	if(left > right or start > end){
		return 0;
	}
	if(start==left and end==right){
		return tree[node];
	}
	int mid = (start + end) >> 1;
	int lchild = node << 1;
	int rchild = left+1;
	return sum(lchild, start, mid, left, min(right,mid))
			+ sum(rchild, mid+1, end, max(left, mid+1), right);
}



//- O(logn)
void update(int node, int start, int end, int indx, int new_value){
	// update the seg tree values corresponding to the arr[pos](update it too)!
	if(start == end){
		tree[node] = new_value;
		arr[pos] = new_value;
		return;
	}
	int mid = (start + end) >>1;
	int lchild = node << 1;
	int rchild = left +1;
	if(indx <= mid){
		update(lchild, start, mid, indx, new_value);
	}else{
		update(rchild, mid+1, end, indx, new_value);
	}
	tree[node] = tree[lchild] + tree[rchild];
}


// - O(n);
void update_range(int node, int start, int end, int left, int right, int new_value){
	// updates the seg tree values for range from [left, right]
	if(start > end or start > right or end < left){
		return;
	}
	if(start == end){
		tree[node] = new_value;
		arr[start] = new_value;
		return;
	}
	int mid = (start + end) >> 1;
	int lchild = node << 1;
	int rchild = left +1;
	update_range(lchild, start, mid, left, right, new_value);
	update_range(rchild, mid+1, left, right, new_value);
	tree[node] = tree[lchild] + tree[rchild];
}
