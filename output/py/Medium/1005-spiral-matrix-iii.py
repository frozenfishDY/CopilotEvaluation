#https://leetcode.com/problems/spiral-matrix-iii/
#You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
#You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
#Return an array of coordinates representing the positions of the grid in the order you visited them.


class Solution(object):
    def spiralMatrixIII(self, rows, cols, rStart, cStart):
        """
        :type rows: int
        :type cols: int
        :type rStart: int
        :type cStart: int
        :rtype: List[List[int]]
        """
        res = []
        res.append([rStart, cStart])
        r, c = rStart, cStart
        d = 0
        n = 1
        while len(res) < rows * cols:
            for i in range(n):
                if d == 0:
                    c += 1
                elif d == 1:
                    r += 1
                elif d == 2:
                    c -= 1
                else:
                    r -= 1
                if 0 <= r < rows and 0 <= c < cols:
                    res.append([r, c])
            d = (d + 1) % 4
            if d % 2 == 0:
                n += 1
        return res
        

    