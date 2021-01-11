if __name__=="__main__":
  N = int(input())
  for i in range(1, 2 * N):
    if i <= N:
      for j in range(1, i + 1):
        print('*', end="")
      print()
    else:
      for j in range(1, N - (i - N) + 1):
        print('*', end="")
      print()