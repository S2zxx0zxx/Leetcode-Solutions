class Solution:
    def check(self, nums: list[bool]) -> bool:
        drops = sum(nums[i] > nums[i+1] for i in range(len(nums)-1))
        drops += nums[-1] > nums[0]
        return drops <= 1