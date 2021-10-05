import sys
from collections import deque
R, C = map(int,sys.stdin.readline().split())
m = []
for i in range(R):
    m.append(list(sys.stdin.readline().split()[0]))


alpabet = [0] * 26
visited = [[0 for i in range(C)] for i in range(R)]

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

result = 0

alpabet[ord(m[0][0]) - ord('A')] = 1
visited[0][0] = 1
# print(visited)
def back(r, c, count):
    
    global result 
    temp = 0
    result = max(result, count)
    # print(r,c,count)
    
    for i in range(4):
        cr = r + dr[i]
        cc = c + dc[i]

        if (0 <= cr < R) and (0 <= cc < C) and (visited[cr][cc] == 0):
            index = ord(m[cr][cc]) - ord('A')
            if alpabet[index] == 0:
                visited[cr][cc] = 1
                alpabet[index] = 1
                temp = back(cr,cc,count+1)
                alpabet[index] = 0
                visited[cr][cc] = 0
    
    # result = max(result, count)
    # return max(temp, count)

back(0,0,1)
print(result)