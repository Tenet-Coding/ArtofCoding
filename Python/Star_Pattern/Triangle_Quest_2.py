"""
For example, a palindromic triangle of size 5 is:

1
121
12321
1234321
123454321

Demlo numbers:

The output requires the sequence of Demlo numbers. For n<=9, the squares of the first few repunits are precisely the Demlo numbers. Example: 1^2=1, 11^2=121, 111^2=12321 and so on.

At first lets see how to get repunits. (10^i - 1) / 9 results in the repunits sequence: 1, 11, 111 etc.

Then calculating square of each repunits, we can get Demlo numbers.

1^2 = 1
11^2 = 121
111^2 = 12321
1111^2 = 1234321
so...

So, the code to perform these operations to generate Demlo numbers is:

"""

for i in range(1, int(input()) + 1):
    print((10 ** i // 9) ** 2)
