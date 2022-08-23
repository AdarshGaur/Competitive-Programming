// Author : @AdarshGaur

class Solution {
public:
    int c2i[26];
    char i2c[10];
    
    bool backtrack(vector<string>& words, string& result, int digit, int indx ,int sum){
        if(digit == result.size())
            return sum == 0;
        
        if(indx == words.size()){
            if(c2i[result[digit]-'A'] != -1){
                
                if(c2i[result[digit] - 'A'] == sum%10)
                       return backtrack(words, result, digit+1, 0, sum/10);
                return false;
                
            }else if(i2c[sum %10] == '\0'){
                
                if(digit == result.size()-1 and sum%10 == 0)
                    return false;
                c2i[result[digit] - 'A'] = sum %10;
                i2c[sum %10] = result[digit];
                
                if(backtrack(words, result, digit+1, 0, sum/10))
                    return true;
                
                c2i[result[digit] - 'A'] = -1;
                i2c[sum %10] = '\0';
            }
            return false;
        }
        
        if(digit >= words[indx].size())
            return backtrack(words, result, digit, indx+1, sum);
        
        if(c2i[words[indx][digit] - 'A'] != -1)
            if(digit != words[indx].size()-1 or c2i[words[indx][digit]-'A'] != 0)
                return backtrack(words, result, digit, indx+1, sum + c2i[words[indx][digit]-'A']);
            else
                return false;

        
        for(int i=0; i<10; i++){
            
            if(i2c[i] != '\0') continue;
            if(i == 0 and digit == words[indx].size()-1 and words[indx].size() > 1) continue;
            
            c2i[words[indx][digit] - 'A'] = i;
            i2c[i] = words[indx][digit];
            if(backtrack(words, result, digit, indx+1, sum +i))
                return true;
            c2i[words[indx][digit] - 'A'] = -1;
            i2c[i] = '\0';
        }
        return false;
    }
    
    bool isSolvable(vector<string>& words, string result) {
        for(auto &c: words){
            if(c.size() > result.size())
                return false;
            reverse(c.begin(), c.end());
        }
        reverse(result.begin(), result.end());
        memset(c2i, -1, sizeof(c2i));
        memset(i2c, '\0', sizeof(i2c));
        return backtrack(words, result, 0, 0, 0);
    }
};
