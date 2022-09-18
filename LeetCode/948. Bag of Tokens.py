# Author : @AdarshGaur

class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        score, size = 0, len(tokens)
        tokens.sort()
        i , j = 0, size -1
        while i <= j:
            if power >= tokens[i]:
                power -= tokens[i]
                score += 1
                i += 1
            else:
                if i == j or score == 0:
                    break
                power += tokens[j]
                score -= 1
                j -= 1
        return score
