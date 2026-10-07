class Solution {
    public int countArrangement(int n) {
        List<Integer> store = new ArrayList<>();
        for(int i=0; i<=n; i++){
            store.add(i);
        }
        return backtrack(store, new ArrayList<Integer>());
    }

    public int backtrack(List<Integer> store, List<Integer> tempList){
        int curIdx = tempList.size() +1;
        if(curIdx == store.size()){
            return 1;
        }
        int permAtIdx = 0;
        for(int i=1; i<store.size(); i++){
            int curNum = store.get(i);
            if(curNum == 0) continue; // already taken
            if(curNum % curIdx == 0 || curIdx % curNum == 0){
                tempList.add(i);
                store.set(i, 0);
                permAtIdx += backtrack(store, tempList);
                tempList.remove(tempList.size()-1);
                store.set(i, curNum);
            }
        }
        return permAtIdx;
    }
}

