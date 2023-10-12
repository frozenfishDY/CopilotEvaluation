/**https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/ */
//You are given an m x n matrix board, representing the current state of a crossword puzzle. The crossword contains lowercase English letters (from solved words), ' ' to represent any empty cells, and '#' to represent any blocked cells.
//A word can be placed horizontally (left to right or right to left) or vertically (top to bottom or bottom to top) in the board if:
//	It does not occupy a cell containing the character '#'.
//	The cell each letter is placed in must either be ' ' (empty) or match the letter already on the board.
//	There must not be any empty cells ' ' or other lowercase letters directly left or right of the word if the word was placed horizontally.
//	There must not be any empty cells ' ' or other lowercase letters directly above or below the word if the word was placed vertically.
//Given a string word, return true if word can be placed in board, or false otherwise.
// 
//Example 1:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", "c", " "]], word = "abc"
//Output: true
//Explanation: The word "abc" can be placed as shown above (top to bottom).
//Example 2:
//Input: board = [[" ", "#", "a"], [" ", "#", "c"], [" ", "#", "a"]], word = "ac"
//Output: false
//Explanation: It is impossible to place the word because there will always be a space/letter above or below it.
//Example 3:
//Input: board = [["#", " ", "#"], [" ", " ", "#"], ["#", " ", "c"]], word = "ca"
//Output: true
//Explanation: The word "ca" can be placed as shown above (right to left). 
// 
//Constraints:
//	m == board.length
//	n == board[i].length
//	1 <= m * n <= 2 * 105
//	board[i][j] will be ' ', '#', or a lowercase English letter.
//	1 <= word.length <= max(m, n)
//	word will contain only lowercase English letters.
class Solution {
    public boolean placeWordInCrossword(char[][] board, String word) {
           int m = board.length, n = board[0].length;
        char[] w = word.toCharArray();
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n) {
                if (board[i][j] == '#') {
                    j++;
                    continue;
                }
                int start = j;
                while (j < n && board[i][j] != '#') {
                    j++;
                }
                int end = j - 1;
                if (end - start + 1 == w.length) {
                    boolean match = true;
                    for (int k = 0; k < w.length; k++) {
                        if (board[i][start + k] != ' ' && board[i][start + k] != w[k]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        return true;
                    }
                    match = true;
                    for (int k = 0; k < w.length; k++) {
                        if (board[i][end - k] != ' ' && board[i][end - k] != w[k]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        return true;
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int i = 0;
            while (i < m) {
                if (board[i][j] == '#') {
                    i++;
                    continue;
                }
                int start = i;
                while (i < m && board[i][j] != '#') {
                    i++;
                }
                int end = i - 1;
                if (end - start + 1 == w.length) {
                    boolean match = true;
                    for (int k = 0; k < w.length; k++) {
                        if (board[start + k][j] != ' ' && board[start + k][j] != w[k]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        return true;
                    }
                    match = true;
                    for (int k = 0; k < w.length; k++) {
                        if (board[end - k][j] != ' ' && board[end - k][j] != w[k]) {
                            match = false;
                            break;
                        }
    }
}