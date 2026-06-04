class Solution {
    public int totalWaviness(int num1, int num2) {
        int totalWaviness = 0;
        for(int i=num1; i <= num2; i++){
            totalWaviness += NumberWaviness(i);
        }
        return totalWaviness;
    }

    public int NumberWaviness(int num){
        int waviness = 0;
        while(num > 100){
            int range = num % 1000;         /// 531, 101,  10
            int right = range % 10;         //    1,   1,   0
            int mid = range / 10 % 10;      //   3 ,  0 ,  1
            int left = range / 100 % 10;    //  5  , 1  , 0
            
            if(left < mid && mid > right){
                waviness++;
            } else if(left > mid && mid < right){
                waviness++;
            }

            num /= 10;
        }
        return waviness;
    }
}

