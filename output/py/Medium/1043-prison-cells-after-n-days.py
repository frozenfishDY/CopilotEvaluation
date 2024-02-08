#https://leetcode.com/problems/prison-cells-after-n-days/
#There are 8 prison cells in a row and each cell is either occupied or vacant.
#Each day, whether the cell is occupied or vacant changes according to the following rules:
#If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
#Otherwise, it becomes vacant.
#Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
#You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
#Return the state of the prison after n days (i.e., n such changes described above).


class Solution(object):
    def prisonAfterNDays(self, cells, n):
        """
        :type cells: List[int]
        :type n: int
        :rtype: List[int]
        """
        seen = {}
        while n > 0:
            c = tuple(cells)
            if c in seen:
                n %= seen[c] - n
            seen[c] = n
            if n >= 1:
                n -= 1
                cells = [int(i > 0 and i < 7 and cells[i-1] == cells[i+1]) for i in range(8)]
        return cells
        

    