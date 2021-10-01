import sys
import heapq
n, k = map(int,sys.stdin.readline().split())
m = sys.stdin.readline().split()[0]
m = [int(m[i]) for i in range(len(m))]
h = []
temp = -1
result = []
for i in range(k):
    heapq.heappush(h,(-m[i], i))
index = k
while index < n:
    heapq.heappush(h,(-m[index], index))
    while True:
        value, idx = heapq.heappop(h)
        if temp < idx:
            temp = idx
            result.append(-value)
            break
        else:
            pass
    index += 1
print(*result, sep='')