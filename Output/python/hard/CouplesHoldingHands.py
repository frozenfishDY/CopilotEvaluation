#https://leetcode.com/problems/couples-holding-hands/
#There are n couples sitting in 2n seats arranged in a row and want to hold hands.
#The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
#Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.


class Solution(object):
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """     
        if not row:
            return 0
        if len(row)==2:
            return 1
        if len(row)==4:
            return 2
        result = []
        for i in range(len(row)-2):
            result.append(row[i:i+2])
        return min(result)

        
        
    