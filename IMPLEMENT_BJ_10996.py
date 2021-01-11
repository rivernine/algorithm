def printStart(num):
  for i in range(1, num + 1):
    if i % 2 == 0:
      print(" ", end="")
    else:
      print("*", end="")
  if num == 1:
    return
  print()
  for i in range(1, num + 1):
    if i % 2 == 0:
      print("*", end="")
    else:
      print(" ", end="")
  print()

if __name__ == "__main__":
  N = int(input())
  for i in range(1, N + 1):    
    printStart(N)