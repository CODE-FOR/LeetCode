import copy


class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []

        def findSubsequences(pos, prefix):
            if pos == len(nums):
                if len(prefix) > 1:
                    res.append(prefix[:])
                return 
            if len(prefix) == 0 or nums[pos] >= prefix[-1]:
                prefix.append(nums[pos])
                findSubsequences(pos + 1, prefix)
                prefix.pop()
            if len(prefix) == 0 or nums[pos] != prefix[-1]:
                findSubsequences(pos + 1, prefix)

        findSubsequences(0, [])
        return res