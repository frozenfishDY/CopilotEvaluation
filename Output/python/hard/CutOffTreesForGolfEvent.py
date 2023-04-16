#https://leetcode.com/problems/cut-off-trees-for-golf-event/
#You are asked to cut off all the trees in a forest for a golf event. The forest is represented as an m x n matrix. In this matrix:
#0 means the cell cannot be walked through.
#1 represents an empty cell that can be walked through.
#A number greater than 1 represents a tree in a cell that can be walked through, and this number is the tree's height.
#In one step, you can walk in any of the four directions: north, east, south, and west. If you are standing in a cell with a tree, you can choose whether to cut it off.
#You must cut off the trees in order from shortest to tallest. When you cut off a tree, the value at its cell becomes 1 (an empty cell).
#Starting from the point (0, 0), return the minimum steps you need to walk to cut off all the trees. If you cannot cut off all the trees, return -1.
#Note: The input is generated such that no two trees have the same height, and there is at least one tree needs to be cut off.


class Solution(object):
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """       
        if not forest or not forest[0]:
            return -1
        m, n = len(forest), len(forest[0])
        trees = []
        for i in range(m):
            for j in range(n):
                if forest[i][j] > 1:
                    trees.append((forest[i][j], i, j))
        trees.sort()
        res = 0
        x, y = 0, 0
        for _, i, j in trees:
            step = self.bfs(forest, x, y, i, j)
            if step < 0:
                return -1
            res += step
            x, y = i, j
        return res

        
        
    