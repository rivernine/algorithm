# SEGMENT_TREE_BJ_6549.py
import sys
import math

def query(node, start, end, left, right):
  if left > end or right < start:
    return sys.maxsize
  if left <= start and right >= end:
    return tree[node]
  mid = (start + end) // 2
  return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right))

def init(node, start, end):
  if start == end:
    tree[node] = arr[start]
    return tree[node]
  mid = (start + end) // 2
  tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end))
  return tree[node]

arr, tree = [], []

if __name__=="__main__":
  while True:
    testcase = [int(x) for x in sys.stdin.readline().split()]
    if testcase[0] == 0:
      break
    arr = testcase[1:]
    leaf = len(arr)
    h = math.ceil(math.log2(leaf))
    treesize = 2 ** (h + 1)

    result = 0
    tree = [0] * treesize
    init(1, 0, leaf - 1)

    for window in range(1, leaf + 1):
      for i in range(0, leaf - window + 1):
        result = max(result, query(1, 0, leaf - 1, i, i + window - 1) * window)
    print(result)

# 7 2 1 4 5 1 3 3
# 4 1000 1000 1000 1000
# 0