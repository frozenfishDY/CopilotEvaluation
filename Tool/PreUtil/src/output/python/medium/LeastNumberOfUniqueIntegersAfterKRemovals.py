#https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
#Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.


class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        if k==0:
            return len(set(arr))
        if k>=len(arr):
            return 0
        arr.sort()
        arr.append(None)
        count=1
        for i in range(1,len(arr)):
            if arr[i]==arr[i-1]:
                count+=1
            else:
                if k>=count:
                    k-=count
                    count=1
                else:
                    return len(set(arr))-k
        return len(set(arr))-k
        

    