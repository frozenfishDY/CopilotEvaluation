/**https://leetcode.com/problems/battleships-in-a-board/ */
//Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.
//Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).
// 
//Example 1:
//Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
//Output: 2
//Example 2:
//Input: board = [["."]]
//Output: 0
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m, n <= 200
//	board[i][j] is either '.' or 'X'.
// 
//Follow up: Could you do it in one-pass, using only O(1) extra memory and without modifying the values board?
class Solution {
    public int countBattleships(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        int result = 0;
        int[][] dirs = {{0, 1}, {1, 0}};
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'X' && !visited[i][0]) {
                result++;
                queue.offer(new int[]{i, 0});
                visited[i][0] = true;
                while (!queue.isEmpty()) {
                    int[] cur = queue.poll();
                    for (int[] dir : dirs) {
                        int x = cur[0] + dir[0];
                        int y = cur[1] + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && board[x][y] == 'X') {
                            queue.offer(new int[]{x, y});
                            visited[x][y] = true;
                        }
                    }
                }
            }
        }
        return result;
    }
}