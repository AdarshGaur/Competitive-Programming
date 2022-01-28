// Simple Factorization with Trial Division method
// stores all the prime factors as with the number of occurences

// Time Complexity - O(sqrt(n));

// n must be more than 1
vector<int> FindFactors(int n){
	vector<int> factors;
	for(int i=2; i*i<=n; i++){
		while(n%i ==0){
			factors.push_back(i);
			n/=i;
		}
	}
	if(n>1){
		factors.push_back(n);
	}
	return factors;
}