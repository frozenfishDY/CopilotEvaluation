#https://leetcode.com/problems/distant-barcodes/
#In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
#Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
# 
#Example 1:
#Input: barcodes = [1,1,1,2,2,2]
#Output: [2,1,2,1,2,1]
#Example 2:
#Input: barcodes = [1,1,1,1,2,2,3,3]
#Output: [1,3,1,3,1,2,1,2]
# 
#Constraints:
#	1 <= barcodes.length <= 10000
#	1 <= barcodes[i] <= 10000
class Solution(object):
    def rearrangeBarcodes(self, barcodes):
        """
        :type barcodes: List[int]
        :rtype: List[int]
        """
        ret = []
        for i in range(len(barcodes)):
            for j in range(len(barcodes[i])):
                if barcodes[i][j] == 1:
                    if self.check(barcodes, i, j):
                        ret += 1
        return ret