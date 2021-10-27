"""
Here: https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

"""


def threeSum(nums):
    result = set()
    for i in range(len(nums)):
        d = {}
        for j in range(i+1, len(nums)):
            diff = 0 - (nums[i] + nums[j])
            if diff in d:
                result.add(tuple(sorted((nums[i], nums[j], diff))))
            d[nums[j]] = (nums[i], diff)
    return result


if __name__ == "__main__":
    # taking the input
    nums = list(map(int, input("Enter the score board: ").split()))
    print(threeSum(nums))


"""


Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

"""
