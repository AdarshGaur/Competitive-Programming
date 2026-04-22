class Solution {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        List<String> almostEqualStrings = new ArrayList<>();
        for(String source: queries){
            for(String target: dictionary){
                if(areAlmostSame(source, target)){
                    almostEqualStrings.add(source);
                    break;
                }
            }
        }
        return almostEqualStrings;
    }

    public boolean areAlmostSame(String source, String target){
        if(source.length() != target.length())
            return false;
        int nonEqualPos = 0;
        for(int i=0; i<source.length(); i++){
            if(source.charAt(i) != target.charAt(i))
                nonEqualPos++;
            if(nonEqualPos > 2)
                return false;
        }
        return true;
    }
}
