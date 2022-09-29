# Author : @AdarshGaur

# class Solution:
#     def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
#         if not matrix:
#             return []
#         return [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1])

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        spiral = []
        left , right = 0, len(matrix[0]) -1
        top , bottom = 0, len(matrix) -1
        
        while left < right and top < bottom:
            
            # top row
            for j in range(left, right):
                spiral.append(matrix[top][j])
            
            # right column
            for i in range(top, bottom):
                spiral.append(matrix[i][right])
            
            # bottom row
            for j in range(right, left, -1):
                spiral.append(matrix[bottom][j])
            
            # left column
            for i in range(bottom, top, -1):
                spiral.append(matrix[i][left])
            
            left += 1
            right -= 1
            top += 1
            bottom -= 1
        
        # end of while
        
        if top == bottom:
            for j in range(left, right+1):
                spiral.append(matrix[top][j])
        elif left == right:
            for i in range(top, bottom+1):
                spiral.append(matrix[i][left])
        
        return spiral
