import sys
n = int(sys.stdin.readline())
m = list(map(int,sys.stdin.readline().split()))
m.insert(0, 0)
d = [0] * (n + 1) 
d[0] = 0
d[1] = m[1]
for i in range(2, n+1):
    temp = 0
    for j in range(1, i//2 + 1):
        temp = max(temp,d[j] + d[i-j])
    d[i] = max(temp, m[i])
    
print(d[n]) 