#https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
#Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
#It is guaranteed that there will be a rectangle with a sum no larger than k.


class Solution(object):
    def maxSumSubmatrix(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        # initialize the maximum sum
        max_sum = float('-inf')
        # iterate over the rows
        for i in range(len(matrix)):
            # initialize the row sums
            row_sums = [0] * len(matrix[0])
            # iterate over the rows starting at the current row
            for j in range(i, len(matrix)):
                # iterate over the columns
                for c in range(len(matrix[0])):
                    # add the current value to the row sums
                    row_sums[c] += matrix[j][c]
                # initialize the current sum
                current_sum = 0
                # initialize the set of sums
                sums = set()
                # iterate over the row sums
                for s in row_sums:
                    # add the current sum to the set of sums
                    sums.add(current_sum)
                    # add the current value to the current sum
                    current_sum += s
                    # if the current sum minus k is in the set of sums
                    if current_sum - k in sums:
                        # set the maximum sum to the maximum of the maximum sum and the current sum minus k
                        max_sum = max(max_sum, current_sum - k)
        # return the maximum sum
        return max_sum
        
        
    