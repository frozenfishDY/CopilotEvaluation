#https://leetcode.com/problems/odd-even-jump/
#You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.
#You may jump forward from index i to index j (with i < j) in the following way:
#During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
#During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
#It may be the case that for some index i, there are no legal jumps.
#A starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times (possibly 0 or more than once).
#Return the number of good starting indices.


class Solution(object):
    def oddEvenJumps(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """      
        if not arr:
            return 0
        if len(arr)==1:
            return 1
        if len(arr)==2:
            return 2
        odd = [0]*len(arr)
        even = [0]*len(arr)
        odd[-1] = 1
        even[-1] = 1
        result = 1
        for i in range(len(arr)-2,-1,-1):
            odd[i] = even[self.find_next(arr,odd,i)]
            even[i] = odd[self.find_next(arr,even,i)]
            result += odd[i]
        return result


         

        
        
    