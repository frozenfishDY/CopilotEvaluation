/**https://leetcode.com/problems/alphabet-board-path/ */
//On an alphabet board, we start at position (0, 0), corresponding to character board[0][0]._x000D_
//_x000D_
//Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], as shown in the diagram below._x000D_
//_x000D_
//_x000D_
//_x000D_
//We may make the following moves:_x000D_
//_x000D_
//_x000D_
//	'U' moves our position up one row, if the position exists on the board;_x000D_
//	'D' moves our position down one row, if the position exists on the board;_x000D_
//	'L' moves our position left one column, if the position exists on the board;_x000D_
//	'R' moves our position right one column, if the position exists on the board;_x000D_
//	'!' adds the character board[r][c] at our current position (r, c) to the answer._x000D_
//_x000D_
//_x000D_
//(Here, the only positions that exist on the board are positions with letters on them.)_x000D_
//_x000D_
//Return a sequence of moves that makes our answer equal to target in the minimum number of moves.  You may return any path that does so._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//Input: target = "leet"_x000D_
//Output: "DDR!UURRR!!DDD!"_x000D_
//Example 2:_x000D_
//Input: target = "code"_x000D_
//Output: "RR!DDRR!UUL!R!"_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= target.length <= 100_x000D_
//	target consists only of English lowercase letters._x000D_
class Solution {
    public String alphabetBoardPath(String target) {
        // 1. create a hashmap to store the coordinates of each character
		// 2. create a string to store the result
		// 3. create two variables to store the current row and column
		// 4. create a for loop to iterate through the target string
		// 4.1 get the coordinates of the current character
		// 4.2 if the current character is z, move up to the current row
		// 4.3 if the current character is not z, move down to the current row
		// 4.4 if the current character is z, move left to the current column
		// 4.5 if the current character is not z, move right to the current column
		// 4.6 if the current character is not z, add '!' to the result
		// 5. return the result
        Map<Character, int[]> map = new HashMap<>();
        int row = 0;
        int col = 0;
        for(int i = 0; i < 26; i++) {
            map.put((char)('a'+i), new int[]{i/5, i%5});
        }
        StringBuilder sb = new StringBuilder();
        for(char c: target.toCharArray()) {
            int[] cur = map.get(c);
            while(row > cur[0]) {
                sb.append('U');
                row--;
            }
            while(col < cur[1]) {
                sb.append('R');
                col++;
            }
            while(col > cur[1]) {
                sb.append('L');
                col--;
            }
            while(row < cur[0]) {
                sb.append('D');
                row++;
            }
            sb.append('!');
        }
        return sb.toString();
    }
}