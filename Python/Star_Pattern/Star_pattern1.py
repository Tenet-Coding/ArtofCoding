"""
Print this Pyramid in python
        1
      2 3 2
    3 4 5 4 3
  4 5 6 7 6 5 4
5 6 7 8 9 8 7 6 5

"""
n = 5
num = 1
gap = n - 1

for j in range(1, n + 1):
    num = j
    for i in range(1, gap - 1):
        print(" ", end="")
    gap = gap - 1

    for i in range(1, j + 1):
        print(num, end="")
        num = num + 1

    num = num - 2

    for i in range(1, j):
        print(num, end="")
        num = num - 1

    print()
