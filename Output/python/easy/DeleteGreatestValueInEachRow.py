#https://leetcode.com/problems/delete-greatest-value-in-each-row/
#You are given an m x n matrix grid consisting of positive integers.
#Perform the following operation until grid becomes empty:
#Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
#Add the maximum of deleted elements to the answer.
#Note that the number of columns decreases by one after each operation.
#Return the answer after performing the operations described above.


class Solution(object):
    def deleteGreatestValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """       
        result=0
        while len(grid[0])>0:
            max_value=0
            for i in range(len(grid)):
                max_value=max(max_value,grid[i][0])
            result+=max_value
            for i in range(len(grid)):
                grid[i].pop(0)
        return result
        

    