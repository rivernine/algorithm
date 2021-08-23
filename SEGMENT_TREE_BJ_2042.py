# SEGMENT_TREE_BJ_2042.py

arr = []
seg = []

def init(node, start, end):
  print(node, start, end)
  if start == end:
    seg[node] = arr[start]
    print("seg["+ str(node) +"] = " + str(arr[start]))
    return seg[node]
  mid = (start + end) // 2
  seg[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end)
  print("seg[" + str(node) + "] = " + str(seg[node]))
  return seg[node]

if __name__=="__main__":
  # N, M, K = map(int, input().split())
  # for i in range(0, N):
  #   arr.append(input())
  # for i in range(0, M + K):
    # a, b, c = map(int, input().split())
  N, M, K = 5, 2, 2
  arr = [1, 2, 3, 4, 5]


  seg = [0 for i in range(0, len(arr)*2)]
  init(1, 0, len(arr) - 1)
  print(seg)
  
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