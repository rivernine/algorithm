if __name__ == "__main__":
  N, M = map(int, input().split())
  numList = list(map(int, input().split()))

  answer = 0
  for i in range(0, len(numList)):
    tmpSum = 0
    for j in range(i, len(numList)):
      tmpSum += numList[j]
      if tmpSum > M:
        break
      elif tmpSum == M:
        answer += 1
        break

  print(answer)