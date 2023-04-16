#https://leetcode.com/problems/reduce-array-size-to-the-half/
#You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
#Return the minimum size of the set so that at least half of the integers of the array are removed.


class Solution(object):
    def minSetSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """ 
        count = collections.Counter(arr)
        res = 0
        for i in sorted(count.values(), reverse=True):
            res += 1
            arrSize -= i
            if arrSize <= len(arr) / 2:
                return res
        return res
        
        

    