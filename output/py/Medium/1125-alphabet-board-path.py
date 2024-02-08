#https://leetcode.com/problems/alphabet-board-path/
#On an alphabet board, we start at position (0, 0), corresponding to character board[0][0]._x000D_
#_x000D_
#Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below._x000D_
#_x000D_
#_x000D_
#_x000D_
#We may make the following moves:_x000D_
#_x000D_
#_x000D_
#	'U' moves our position up one row, if the position exists on the board;_x000D_
#	'D' moves our position down one row, if the position exists on the board;_x000D_
#	'L' moves our position left one column, if the position exists on the board;_x000D_
#	'R' moves our position right one column, if the position exists on the board;_x000D_
#	'!' adds the character board[r][c] at our current position (r, c) to the answer._x000D_
#_x000D_
#_x000D_
#(Here, the only positions that exist on the board are positions with letters on them.)_x000D_
#_x000D_
#Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so._x000D_
#_x000D_
# _x000D_
#Example 1:_x000D_
#Input: target = "leet"_x000D_
#Output: "DDR!UURRR!!DDD!"_x000D_
#Example 2:_x000D_
#Input: target = "code"_x000D_
#Output: "RR!DDRR!UUL!R!"_x000D_
#_x000D_
# _x000D_
#Constraints:_x000D_
#_x000D_
#_x000D_
#	1 <= target.length <= 100_x000D_
#	target consists only of English lowercase letters._x000D_
class Solution(object):
    def alphabetBoardPath(self, target):
        """
        :type target: str
        :rtype: str
        """
        # Approach 1: Straightforward
        # Time Complexity: O(N)
        # Space Complexity: O(N)
        # Runtime: 16 ms, faster than 85.46% of Python online submissions for Alphabet Board Path.
        # Memory Usage: 13.7 MB, less than 5.42% of Python online submissions for Alphabet Board Path.
        ans = ''
        x, y = 0, 0
        for c in target:
            nx, ny = divmod(ord(c) - ord('a'), 5)
            dx, dy = nx - x, ny - y
            if dy < 0:
                ans += 'L' * abs(dy)
            if dx < 0:
                ans += 'U' * abs(dx)
            if dx > 0:
                ans += 'D' * dx
            if dy > 0:
                ans += 'R' * dy
            ans += '!'
            x, y = nx, ny
        return ans