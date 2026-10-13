class Solution {
    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        backtrack(new ArrayList<>(), n, k, 1);
        return res;
    }

    private void backtrack(List<Integer> tempList, int n, int k, int start) {
        if (tempList.size() == k) {
            res.add(new ArrayList<>(tempList));
            return;
        }
        for (int i = start; i <= n; i++) {
            tempList.add(i);
            backtrack(tempList, n, k, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}
