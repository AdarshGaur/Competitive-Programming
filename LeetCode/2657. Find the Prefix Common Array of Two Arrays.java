class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] c = new int[n];
        HashSet<Integer> set = new HashSet<>();
        for(int i=1; i<=n; i++){
            set.add(i);
        }

        // reverse iterate over the array and remove the numbers as per occurence
        for(int i=n-1; i>=0; i--){
            c[i] = set.size();

            set.remove(A[i]);
            set.remove(B[i]);
        }

        return c;
    }
}

