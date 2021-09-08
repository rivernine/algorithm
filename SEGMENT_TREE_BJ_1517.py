# SEGMENT_TREE_BJ_1517.py
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

tree, arr = [], []

if __name__=="__main__":
  n = int(sys.stdin.readline())    
  arr = [int(x) for x in sys.stdin.readline().split()]
  sorted_arr = sorted(arr)
  mp = {}

  h = math.ceil(math.log2(n))
  treesize = 2 ** (h + 1)
  tree = [0] * treesize

  result = 0
  for i, s in enumerate(sorted_arr):
    mp[s] = i
  for a in arr:
    update(1, 0, n - 1, mp[a], 1)
    result += query(1, 0, n - 1, mp[a] + 1, n - 1)
  print(result)