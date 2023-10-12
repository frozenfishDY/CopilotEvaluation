/**https://leetcode.com/problems/stone-game-viii/ */
//Alice and Bob take turns playing a game, with Alice starting first._x000D_
//_x000D_
//There are n stones arranged in a row. On each player's turn, while the number of stones is more than one, they will do the following:_x000D_
//_x000D_
//_x000D_
//	Choose an integer x > 1, and remove the leftmost x stones from the row._x000D_
//	Add the sum of the removed stones' values to the player's score._x000D_
//	Place a new stone, whose value is equal to that sum, on the left side of the row._x000D_
//_x000D_
//_x000D_
//The game stops when only one stone is left in the row._x000D_
//_x000D_
//The score difference between Alice and Bob is (Alice's score - Bob's score). Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference._x000D_
//_x000D_
//Given an integer array stones of length n where stones[i] represents the value of the ith stone from the left, return the score difference between Alice and Bob if they both play optimally._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: stones = [-1,2,-3,4,-5]_x000D_
//Output: 5_x000D_
//Explanation:_x000D_
//- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of_x000D_
//  value 2 on the left. stones = [2,-5]._x000D_
//- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on_x000D_
//  the left. stones = [-3]._x000D_
//The difference between their scores is 2 - (-3) = 5._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: stones = [7,-6,5,10,5,-2,-6]_x000D_
//Output: 13_x000D_
//Explanation:_x000D_
//- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a_x000D_
//  stone of value 13 on the left. stones = [13]._x000D_
//The difference between their scores is 13 - 0 = 13._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: stones = [-10,-12]_x000D_
//Output: -22_x000D_
//Explanation:_x000D_
//- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her_x000D_
//  score and places a stone of value -22 on the left. stones = [-22]._x000D_
//The difference between their scores is (-22) - 0 = -22._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	n == stones.length_x000D_
//	2 <= n <= 105_x000D_
//	-104 <= stones[i] <= 104_x000D_


int stoneGameVIII(int* stones, int stonesSize){

}