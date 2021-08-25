# SEGMENT_TREE_BJ_2042.py

arr = []
seg = []

def update(node, start, end, index, diff):
  if index < start or index > end:
    return
  seg[node] += diff
  if start != end:
    mid = (start + end) // 2
    update(node * 2, start, mid, index, diff)
    update(node * 2 + 1, mid + 1, end, index, diff)

def query(node, start, end, left, right):
  if left > end or right < start:
    return 0
  if left <= start and right >= end:
    return seg[node]
  mid = (start + end) // 2
  return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)

def init(node, start, end):
  if start == end:
    seg[node] = arr[start]
    return seg[node]
  mid = (start + end) // 2
  seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end)
  return seg[node]

if __name__=="__main__":
  N, M, K = map(int, input().split())
  for i in range(0, N):
    arr.append(int(input()))    
  seg = [0] * 3000000
  init(1, 0, N - 1)
  for _ in range(0, M + K):
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