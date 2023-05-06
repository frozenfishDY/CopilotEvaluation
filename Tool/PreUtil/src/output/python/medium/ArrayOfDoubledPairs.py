#https://leetcode.com/problems/array-of-doubled-pairs/
#Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.


class Solution(object):
    def canReorderDoubled(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        arr.sort()
        count = collections.Counter(arr)
        for x in arr:
            if count[x] == 0:
                continue
            if x < 0 and x % 2 != 0:
                return False
            count[x] -= 1
            count[2 * x] -= 1
        return all(v == 0 for v in count.values())
        

    