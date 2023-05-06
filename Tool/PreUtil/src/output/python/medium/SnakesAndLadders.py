#https://leetcode.com/problems/snakes-and-ladders/
#You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
#You start on square 1 of the board. In each move, starting from square curr, do the following:
#Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
#This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
#If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
#The game ends when you reach the square n2.
#A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.
#Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
#For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
#Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.


class Solution(object):
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        n = len(board)
        def get_pos(num):
            quot, rem = divmod(num - 1, n)
            row = n - 1 - quot
            col = rem if row % 2 != n % 2 else n - 1 - rem
            return row, col
        queue = collections.deque([(1, 0)])
        visited = set([1])
        while queue:
            num, moves = queue.popleft()
            if num == n * n: return moves
            for i in range(1, 7):
                if num + i > n * n: break
                r, c = get_pos(num + i)
                next_num = board[r][c] if board[r][c] != -1 else num + i
                if next_num not in visited:
                    visited.add(next_num)
                    queue.append((next_num, moves + 1))
        return -1
        

    