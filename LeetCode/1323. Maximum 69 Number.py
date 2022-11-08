#Author: @AdarshGaur

class Solution:
    def maximum69Number (self, num: int) -> int:
        char_list = list(str(num))
        for i, c in enumerate(char_list):
            if c == '6':
                char_list[i] = '9'
                break
        return int(''.join(char_list))
