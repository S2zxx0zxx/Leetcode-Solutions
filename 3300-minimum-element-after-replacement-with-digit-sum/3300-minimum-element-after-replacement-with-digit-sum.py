class Solution:
    def minElement(self, nums: list[int]) -> int:
        return min(sum(int(d) for d in str(n)) for n in nums)    