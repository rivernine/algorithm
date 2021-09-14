# TOPOLOGY_SORT_BJ_2252.py
import sys
from collections import deque 

def find(n):
  for i in range(1, n + 1):
    flag = True
    for j in range(1, n + 1):
      if grafh[j][i] == True:
        flag = False
        break
    if flag and not visited[i]:      
      return i
  return -1

def BFS(n):
  deq = deque()
  deq.append(find(n))
  while len(deq):
    # print(len(deq))
    fnt = deq.popleft()
    visited[fnt] = True
    print(fnt, end=' ')
    # print('append' + str(fnt))
    # result.append(fnt)
    for i in range(1, n + 1):
      grafh[fnt][i] = False
      grafh[i][fnt] = False
    node = find(n)  
    # print(node)
    if node != -1:
      deq.append(node)

result, grafh, visited = [], [], []

if __name__=="__main__":
  n, m = [int(x) for x in sys.stdin.readline().split()]
  grafh = [[False for _ in range(0, n + 1)] for _ in range(0, n + 1)]
  visited = [False] * (n + 1)
  for i in range(0, m):
    a, b = [int(x) for x in sys.stdin.readline().split()]
    grafh[a][b] = True
  BFS(n)
  
  # for n in result:
  #   print(n, end=' ')

# 3 2
# 1 3
# 2 3