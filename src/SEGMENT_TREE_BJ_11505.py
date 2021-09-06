# SEGMENT_TREE_BJ_11505.py
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
  tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD


def query(node, start, end, left, right):
  if left > end or right < start:
    return 1
  if left <= start and right >= end:
    return tree[node]
  mid = (start + end) // 2
  return int(query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % MOD

def init(node, start, end):
  if start == end:
    tree[node] = arr[start]
    return tree[node]
  mid = (start + end) // 2
  tree[node] = int(init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end)) % MOD
  return tree[node]

MOD = 1000000007
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
    if a == 1:
      update(1, 0, n - 1, b - 1, c)
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