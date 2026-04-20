class Solution {
    public int maxDistance(int[] colors) {
        int dis=Integer.MIN_VALUE;
        for(int i=0;i<colors.length;i++){
            int col=colors[i];
            int j=colors.length-1;
            while(j>=0){
                if(colors[j]!=col){
                     dis=Math.max(dis,Math.abs(j-i));
                     break;
                }
                else j--;
            }
        }
        return dis;
    }
}
