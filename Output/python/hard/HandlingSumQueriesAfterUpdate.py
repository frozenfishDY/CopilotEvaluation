#https://leetcode.com/problems/handling-sum-queries-after-update/
#You are given two 0-indexed arrays nums1 and nums2 and a 2D array queries of queries. There are three types of queries:
#For a query of type 1, queries[i] = [1, l, r]. Flip the values from 0 to 1 and from 1 to 0 in nums1 from index l to index r. Both l and r are 0-indexed.
#For a query of type 2, queries[i] = [2, p, 0]. For every index 0 <= i < n, set nums2[i] = nums2[i] + nums1[i] * p.
#For a query of type 3, queries[i] = [3, 0, 0]. Find the sum of the elements in nums2.
#Return an array containing all the answers to the third type queries.


class Solution(object):
    def handleQuery(self, nums1, nums2, queries):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """      
        if not queries:
            return []
        result = []
        for query in queries:
            if query[0] == 1:
                for i in range(query[1],query[2]+1):
                    nums1[i] = 1 - nums1[i]
            elif query[0] == 2:
                for i in range(len(nums2)):
                    nums2[i] += nums1[i] * query[1]
            else:
                result.append(sum(nums2))
        return result

        
        
    