'''
Problem: https://www.codechef.com/LTIME92C/problems/EVENDIFF

'''
# cook your dish here
t=int(input())
for i in range(t):
    n=int(input())
    l=[]*n
    lst=input().split()
    even=0
    odd=0
    for p in range(n):
        if int(lst[p])%2==0:
            even+=1
        else:
            odd+=1
    if odd==n or even==n:
        print(0)
    elif(even>odd):
        print(odd)
    else:
        print(even)

'''
Time complexcity : O(n)
space complexcity : O(1)
Input
--> The first line contains a single integer T — the number of test cases. The description of each test case is as follows.
--->The first line of each test case contains a single integer N — the length of the array.
-->The second line of each test case contains N integers, a1,a2...aN — the integers in the array.

Input:
2
2
2 4
3
4 1 2


Output:
0
1
'''
