'''
Problem: https://www.codechef.com/LTIME92C/problems/INTRVS

Ashishgup wants to conduct interviews to hire people to work for him. He decided to automate the interview process to save time. The server asks N problems to the interviewee and stores the amount of time a candidate takes to solve each problem. More formally, the data is stored as an array A, where the i-th integer Ai denotes the time (in seconds) the candidate took to solve the i-th problem.
Note that Ai = −1 denotes that the candidate was not able to solve the i-th problem at all. Can you help Ashish automate the process by writing a code to find the verdict of the interview?

'''
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    time_candidate_takes=[]*n
    Rejected=0
    bot=0
    too_slow=0
    time_candidate_takes=input().split()
    for f in range(n):
        time_candidate_takes[f]=int(time_candidate_takes[f])
    for p in range(n):
        if time_candidate_takes[p]==-1:
            Rejected+=1
        elif time_candidate_takes[p]>k:
            too_slow+=1
        elif time_candidate_takes[p]==0 or time_candidate_takes[p]==1:
            bot+=1
    if Rejected>n/2:
        print("Rejected")
    elif bot==n:
        print("Bot")
    elif too_slow!=0:
        print("Too Slow")
    else:
        print("Accepted")

'''
Time complexcity : O(n)
space complexcity : O(1)

Input
--> The first line of the  input contains a single 
-->integer T denoting the number of test cases. The description of T test cases follows.
-->The first line of each test case contains two space separated integers - N and K respectively.
-->The second line of each test case contains N space separated integers - A1,A2,…,AN.

Input:
5
7 30
-1 0 4 -1 -1 40 -1
6 30
1 0 1 1 1 0
6 44
1 1 1 1 -1 0
7 31
2 3 42 -1 -1 -1 4
6 60
1 -1 0 60 -1 -1

Output:
Rejected
Bot
Accepted
Too Slow
Accepted
'''
