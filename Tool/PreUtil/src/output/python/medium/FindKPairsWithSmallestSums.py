#https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
#You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
#Define a pair (u, v) which consists of one element from the first array and one element from the second array.
#Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        if not nums1 or not nums2:
            return []
        res = []
        heap = [(nums1[0] + nums2[0], 0, 0)]
        while heap and len(res) < k:
            _, i, j = heapq.heappop(heap)
            res.append([nums1[i], nums2[j]])
            if i + 1 < len(nums1) and (i + 1, j) not in heap:
                heapq.heappush(heap, (nums1[i + 1] + nums2[j], i + 1, j))
            if j + 1 < len(nums2) and (i, j + 1) not in heap:
                heapq.heappush(heap, (nums1[i] + nums2[j + 1], i, j + 1))
        return res
        

    