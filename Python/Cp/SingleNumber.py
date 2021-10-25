# class Solution:
def singleNumber(nums):
    result = nums[0]
    for i in range(1, len(nums)):
        result ^= nums[i]
    return result


if __name__ == "__main__":
    # taking the input
    nums = list(map(int, input("Enter the array ").split()))
    print(singleNumber(nums))


"""
Time complexcity : O(N)
Space Complexcity : O(1)

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
"""
