# SORT_BJ_18870.py
import sys

if __name__=="__main__":
  n = int(sys.stdin.readline())
  arr = [int(x) for x in sys.stdin.readline().split()]

  sorted_arr = sorted(list(set(arr)))
  dic = {}
  for idx, element in enumerate(sorted_arr):
    dic[element] = idx

  for element in arr:
    print(dic[element], end=' ')
