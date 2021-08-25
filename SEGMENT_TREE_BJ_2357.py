# SEGMENT_TREE_BJ_2357.py

arr = []
seg = []

if __name__=="__main__":
  N, M = map(int, input().split())
  for i in range(0, N):
    arr.append(int(input()))    
  tree = [0] * 200000
  init(1, 0, N - 1)
  for _ in range(0, M):
    a, b, c = map(int, input().split())
    if a == 1:
      diff = c - arr[b - 1]
      arr[b - 1] = c      
      update(1, 0, N - 1, b - 1, diff)
    else:
      print(query(1, 0, N - 1, b - 1, c - 1))
# 5 2 2
# 1
# 2
# 3
# 4
# 5
# 1 3 6
# 2 2 5
# 1 5 2
# 2 3 5