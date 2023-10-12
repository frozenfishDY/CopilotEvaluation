#https://leetcode.com/problems/rotating-the-box/
#You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:_x000D_
#_x000D_
#_x000D_
#	A stone '#'_x000D_
#	A stationary obstacle '*'_x000D_
#	Empty '.'_x000D_
#_x000D_
#_x000D_
#The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions._x000D_
#_x000D_
#It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box._x000D_
#_x000D_
#Return an n x m matrix representing the box after the rotation described above._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#_x000D_
#_x000D_
#_x000D_
#_x000D_
#Input: box = [["#",".","#"]]_x000D_
#Output: [["."],_x000D_
#         ["#"],_x000D_
#         ["#"]]_x000D_
#_x000D_
#_x000D_
#Example 2:_x000D_
#_x000D_
#_x000D_
#_x000D_
#_x000D_
#Input: box = [["#",".","*","."],_x000D_
#              ["#","#","*","."]]_x000D_
#Output: [["#","."],_x000D_
#         ["#","#"],_x000D_
#         ["*","*"],_x000D_
#         [".","."]]_x000D_
#_x000D_
#_x000D_
#Example 3:_x000D_
#_x000D_
#_x000D_
#_x000D_
#_x000D_
#Input: box = [["#","#","*",".","*","."],_x000D_
#              ["#","#","#","*",".","."],_x000D_
#              ["#","#","#",".","#","."]]_x000D_
#Output: [[".","#","#"],_x000D_
#         [".","#","#"],_x000D_
#         ["#","#","*"],_x000D_
#         ["#","*","."],_x000D_
#         ["#",".","*"],_x000D_
#         ["#",".","."]]_x000D_
#_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	m == box.length_x000D_
#	n == box[i].length_x000D_
#	1 <= m, n <= 500_x000D_
#	box[i][j] is either '#', '*', or '.'._x000D_
class Solution(object):
    def rotateTheBox(self, box):
        """
        :type box: List[List[str]]
        :rtype: List[List[str]]
        """
        m, n = len(box), len(box[0])
        res = [['.'] * m for _ in range(n)]
        for i in range(m):
            k = n - 1
            for j in range(n-1, -1, -1):
                if box[i][j] == '*':
                    k = j - 1
                elif box[i][j] == '#':
                    res[k][m-1-i] = '#'
                    k -= 1
        return res