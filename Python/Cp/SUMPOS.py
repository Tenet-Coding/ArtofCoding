'''
Problem: https://www.codechef.com/LTIME92C/problems/SUMPOS

Chef is always trying to find patterns within integers. Today Chef has 3 positive integers and he wonders if any one of them can be written as the sum of the other two integers.

'''


t=int(input())
for i in range(t):
    PositiveInteger=[0]*3
    PositiveInteger[0] ,PositiveInteger[1],PositiveInteger[2] =map(int,input().split())
    PositiveInteger.sort()
    if PositiveInteger[0]+PositiveInteger[1]==PositiveInteger[2]:
        print("YES")
    else:
        print("NO")

'''
Time complexcity : O(n log n)
space complexcity : O(1)

Input:
-->First line will contain the number 5, which is the number of testcases. Then the testcases follow.
-->Each testcase contains a single line of input, with three space-separated positive integers x, y, and z.

Input
5
1 1 2
1 3 2
2 2 2
100 100 201
11 22 33

Output 
YES
YES
NO
NO
YES
'''