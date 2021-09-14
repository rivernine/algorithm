# SORT_BJ_2108.py
import sys
import statistics

if __name__=="__main__":
  arr = []
  freq = {}

  n = int(sys.stdin.readline())
  for i in range(0, n):
    arr.append(int(sys.stdin.readline()))
    if arr[i] in freq:
      freq[arr[i]] += 1
    else:
      freq[arr[i]] = 1
  arr.sort()

  freq_list = sorted(freq.items(), key = lambda x: x[1], reverse=True)
  most_freq_num = [freq_list[0][0]]  
  for idx in range(1, len(freq_list)):
    if freq_list[idx - 1][1] == freq_list[idx][1]:      
      most_freq_num.append(freq_list[idx][0])  

  print(round(statistics.mean(arr)))  
  print(statistics.median(arr))
  if len(most_freq_num) > 1:
    print(sorted(most_freq_num)[1])
  else:
    print(most_freq_num[0])
  print(arr[n - 1] - arr[0])