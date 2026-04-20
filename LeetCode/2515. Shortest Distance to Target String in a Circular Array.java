class Solution {
    public int closestTarget(String[] words, String target, int startIndex) {
        if(areSame(words[startIndex], target))
            return 0;

        int totalLength = words.length;
        int leftMovingIdx = handleMod(startIndex, -1, totalLength);
        int rightMovingIdx = handleMod(startIndex, 1, totalLength);
        int steps = 1;

        while(steps < totalLength){
            if(areSame(words[leftMovingIdx], target))
                return steps;
            
            if(areSame(words[rightMovingIdx], target))
                return steps;
            
            leftMovingIdx = handleMod(leftMovingIdx, -1, totalLength);
            rightMovingIdx = handleMod(rightMovingIdx, 1, totalLength);
            steps++;
        }
        return -1;
    }

    private int handleMod(int firstNumber, int secondNumber, int Mod){
        return (firstNumber + secondNumber + Mod) % Mod;
    }

    private boolean areSame(String source, String target){
        int sourceLength = source.length();
        int targetLength = target.length();
        
        if(sourceLength != targetLength)
            return false;
        
        for(int idx = 0; idx < targetLength; idx++){
            if(source.charAt(idx) != target.charAt(idx))
                return false;
        }

        return true;
    }
}
