#https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
#You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
#The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
#Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.


class Solution(object):
    def minimumHammingDistance(self, source, target, allowedSwaps):
        """
        :type source: List[int]
        :type target: List[int]
        :type allowedSwaps: List[List[int]]
        :rtype: int
        """       
        result = 0
        for i in range(len(source)):
            if source[i] != target[i]:
                for j in range(i+1, len(source)):
                    if source[j] == target[i]:
                        source[i], source[j] = source[j], source[i]
                        result += 1
                        break
        return result

        

    