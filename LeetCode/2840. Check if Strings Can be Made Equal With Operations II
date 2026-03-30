class Solution {
    public boolean checkStrings(String s1, String s2) {
        int[] charAtOddIdx = new int[26];
        int[] charAtEvenIdx = new int[26];
        int n = s1.length();
        for(int i=0; i<n; i++){
            if(i % 2 == 1){
                charAtOddIdx[s1.charAt(i) - 'a']++;
                charAtOddIdx[s2.charAt(i) - 'a']--;
            }else{
                charAtEvenIdx[s1.charAt(i) - 'a']++;
                charAtEvenIdx[s2.charAt(i) - 'a']--;
            }
        }

        boolean areSame = true;
        for(int i=0; i<26; i++){
            if(charAtOddIdx[i] != 0 || charAtEvenIdx[i]!= 0){
                areSame = false;
                break;
            }
        }
        return areSame;
    }
}

