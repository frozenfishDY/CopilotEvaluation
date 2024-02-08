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
/**
 * @param {string} target
 * @return {string}
 */
var alphabetBoardPath = function(target) {
    var ans = '';
	var cur = [0, 0];
	var board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"];
	var getPos = function(c) {
		for (var i = 0; i < board.length; i++) {
			for (var j = 0; j < board[i].length; j++) {
				if (board[i][j] == c) {
					return [i, j];
				}
			}
		}
		return [-1, -1];
	};
	var getMove = function(c) {
		var pos = getPos(c);
		var ans = '';
		var x = pos[0] - cur[0];
		var y = pos[1] - cur[1];
		if (x > 0) {
			ans += 'D'.repeat(x);
		} else {
			ans += 'U'.repeat(-x);
		}
		if (y > 0) {
			ans += 'R'.repeat(y);
		} else {
			ans += 'L'.repeat(-y);
		}
		cur = pos;
		return ans;
	};
	for (var i = 0; i < target.length; i++) {
		ans += getMove(target[i]);
		ans += '!';
	}
	return ans;
};