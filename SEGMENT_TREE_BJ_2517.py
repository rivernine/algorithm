# SEGMENT_TREE_BJ_2517.py
import sys
import math

def update(node, start, end, target, value):
  if start == end:
    tree[node] = value
    return
  mid = (start + end) // 2
  if target <= mid:
    update(node * 2, start, mid, target, value)
  else:
    update(node * 2 + 1, mid + 1, end, target, value)
  tree[node] = tree[node * 2] + tree[node * 2 + 1]

def query(node, start, end, left, right):
  if left > end or right < start:
    return 0
  if left <= start and right >= end:
    return tree[node]
  mid = (start + end) // 2
  return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)

arr, tree = [], []

if __name__=="__main__":
  n = int(sys.stdin.readline())
  mp = {}
  for i in range(0, n):
    arr.append(int(sys.stdin.readline()))
  for idx, num in enumerate(sorted(arr)):
    mp[num] = idx

  h = math.ceil(math.log2(n))
  treesize = 2 ** (h + 1)
  tree = [0] * treesize

  for i in arr:
    tmp = mp[i]
    print(query(1, 0, n - 1, tmp + 1, n - 1) + 1)
    update(1, 0, n - 1, mp[i], 1)

# 8
# 2
# 8
# 10
# 7
# 1
# 9
# 4
# 15