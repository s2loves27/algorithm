import sys
from collections import deque
from itertools import product
from copy import deepcopy
def loader(dir, i , j):
    if dir == 0:
        return (j, i)
    if dir == 1:
        return (i, n-j-1)
    if dir == 2:
        return (n-j-1, i)
    if dir == 3:
        return (i, j)
def return_2048(matrix, p):
    result = 0
    for s in p:
        for i in range(n):
            temp = []
            for j in range(n):
                r, c = loader(s,i,j)
                # print(r, c)
                if matrix[r][c] != 0:
                    temp.append(matrix[r][c])
            m = len(temp)
            # print(m, matrix)
            for j in range(m-1):
                if temp[j] == 0:
                    continue
                if temp[j] == temp[j+1]:
                    temp[j] *= 2 
                    result = max(result, temp[j])
                    temp[j+1] = 0
            # print(temp)
            # matrix = [[0] * n] * n
            ord = 0
            for j in range(m):
                r ,c = loader(s,i,ord)
                if temp[j] == 0:
                    continue
                
                matrix[r][c] = temp[j]
                    # matrix[r][c] = temp[j]
                
                ord += 1
            for j in range(ord, n):
                r, c = loader(s, i , j)
                matrix[r][c] = 0 
            
    # print(matrix)
    return max(map(max,matrix)) 
    
n = int(sys.stdin.readline())
box = []
for i in range(n):
    box.append(list(map(int, sys.stdin.readline().split())))
pd = list(product(range(4), repeat=5))
result = max(map(max,box))
for p in pd:
    temp_matrix = deepcopy(box)
    result = max(result, return_2048(temp_matrix, p))
    
# if result == 0:
#     for i in range(n):
#         for j in range(n):
#             result  = max(result, box[i][j])
print(result)