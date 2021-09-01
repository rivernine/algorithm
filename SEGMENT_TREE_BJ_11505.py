# SEGMENT_TREE_BJ_11505.py
import sys
import math

def update(node, start, end, index, diff):
  if index < start or index > end:
    return
  tree[node] = int(tree[node] * diff) % 1000000007
  if start != end:
    mid = (start + end) // 2
    update(node * 2, start, mid, index, diff)
    update(node * 2 + 1, mid + 1, end, index, diff)

def query(node, start, end, left, right):
  if left > end or right < start:
    return 1
  if left <= start and right >= end:
    return tree[node]
  mid = (start + end) // 2
  return int(query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % 1000000007

def init(node, start, end):
  if start == end:
    tree[node] = arr[start]
    return tree[node]
  mid = (start + end) // 2
  tree[node] = int(init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % 1000000007
  return tree[node]

arr, tree = [], []

if __name__=="__main__":
  n, m, k = [int(x) for x in sys.stdin.readline().split()]
  for i in range(0, n):
    arr.append(int(sys.stdin.readline()))
  h = math.ceil(math.log2(n))
  treesize = 2 ** (h + 1)
  tree = [0] * treesize
  init(1, 0, n - 1)

  for i in range(0, m + k):
    a, b, c = [int(x) for x in sys.stdin.readline().split()]
    diff = c / arr[b - 1]
    arr[b - 1] = c
    if a == 1:
      update(1, 0, n - 1, b - 1, diff)
    else:
      print(query(1, 0, n - 1, b - 1, c - 1))

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