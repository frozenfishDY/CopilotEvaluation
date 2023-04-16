#https://leetcode.com/problems/number-of-great-partitions/
#You are given an array nums consisting of positive integers and an integer k.
#Partition the array into two ordered groups such that each element is in exactly one group. A partition is called great if the sum of elements of each group is greater than or equal to k.
#Return the number of distinct great partitions. Since the answer may be too large, return it modulo 109 + 7.
#Two partitions are considered distinct if some element nums[i] is in different groups in the two partitions.


class Solution(object):
    def countPartitions(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """      
        def get_count_without_repetitions(n):
            res = 0
            k = len(n)
            for i in range(1, k):
                res += 9 * get_permutations_without_repetitions(9, i-1)
            used = set()
            for i in range(k):
                for j in range(1 if i else 1, n[i]):
                    if j not in used:
                        res += get_permutations_without_repetitions(9-i, k-i-1)
                if n[i] in used:
                    break
                used.add(n[i])
            else:
                res += 1
            return res
        
        return n - get_count_without_repetitions(get_digits(n))
        
        
        
    