/**https://leetcode.com/problems/number-of-paths-with-max-score/ */
//You are given a square board of characters. You can move on the board starting at the bottom right square marked with the character 'S'._x000D_
//_x000D_
//You need to reach the top left square marked with the character 'E'. The rest of the squares are labeled either with a numeric character 1, 2, ..., 9 or with an obstacle 'X'. In one move you can go up, left or up-left (diagonally) only if there is no obstacle there._x000D_
//_x000D_
//Return a list of two integers: the first integer is the maximum sum of numeric characters you can collect, and the second is the number of such paths that you can take to get that maximum sum, taken modulo 10^9 + 7._x000D_
//_x000D_
//In case there is no path, return [0, 0]._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//Input: board = ["E23","2X2","12S"]_x000D_
//Output: [7,1]_x000D_
//Example 2:_x000D_
//Input: board = ["E12","1X1","21S"]_x000D_
//Output: [4,2]_x000D_
//Example 3:_x000D_
//Input: board = ["E11","XXX","11S"]_x000D_
//Output: [0,0]_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	2 <= board.length == board[i].length <= 100_x000D_


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathsWithMaxScore(char ** board, int boardSize, int* returnSize){

}