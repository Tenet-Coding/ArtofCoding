"""
Here: https://leetcode.com/problems/4sum/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
"""


def fourSum(nums, target):
    ans, n = [], len(nums)
    nums.sort()
    for a in range(n):
        for b in range(a+1, n):
            c = b+1
            d = n-1
            while c < d:
                sums = nums[a]+nums[b]+nums[c]+nums[d]
                if sums < target:
                    c += 1
                elif sums > target:
                    d -= 1
                else:
                    to_append = [nums[a], nums[b], nums[c], nums[d]]
                    if to_append not in ans:
                        ans.append(to_append)
                    c += 1
                    d -= 1
    return ans


if __name__ == "__main__":
    # taking the input
    target = int(input("target: "))
    nums = list(map(int, input("Enter the array ").split()))
    print(fourSum(nums, target))

"""

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

"""
