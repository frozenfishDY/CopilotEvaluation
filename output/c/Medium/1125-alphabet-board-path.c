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


char * alphabetBoardPath(char * target){
int len = strlen(target);
    char *res = (char *)malloc(sizeof(char) * (len * 5 + 1));
    int size = 0;
    int curX = 0, curY = 0;
    for (int i = 0; i < len; ++i) {
        int targetX = (target[i] - 'a') % 5;
        int targetY = (target[i] - 'a') / 5;
        if (curX < targetX) {
            for (int j = 0; j < targetX - curX; ++j) {
                res[size++] = 'R';
            }
        } else if (curX > targetX) {
            for (int j = 0; j < curX - targetX; ++j) {
                res[size++] = 'L';
            }
        }
        if (curY < targetY) {
            for (int j = 0; j < targetY - curY; ++j) {
                res[size++] = 'D';
            }
        } else if (curY > targetY) {
            for (int j = 0; j < curY - targetY; ++j) {
                res[size++] = 'U';
            }
        }
        curX = targetX;
        curY = targetY;
        res[size++] = '!';
    }
    res[size] = '\0';
    return res;
}