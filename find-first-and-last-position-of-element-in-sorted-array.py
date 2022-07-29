class Solution:
    def searchRange(self, nums, target):
        def binarySearch(n, check):  # usually use
            left, right = 0, n-1  # search in [0, n-1], return n if not found
            while left <= right:
                mid = left + (right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left
        # Find the first idx where nums[idx] >= target
        left = binarySearch(len(nums), lambda i: nums[i] >= target)
        if left == len(nums) or nums[left] != target:
            return [-1, -1]
        # Find the first idx where nums[idx] > target
        right = binarySearch(len(nums), lambda i: nums[i] > target)
        return [left, right-1]

        