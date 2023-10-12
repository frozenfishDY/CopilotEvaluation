/**https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/ */
//You are given two 0-indexed integer arrays player1 and player2, that represent the number of pins that player 1 and player 2 hit in a bowling game, respectively.
//The bowling game consists of n turns, and the number of pins in each turn is exactly 10.
//Assume a player hit xi pins in the ith turn. The value of the ith turn for the player is:
//	2xi if the player hit 10 pins in any of the previous two turns.
//	Otherwise, It is xi.
//The score of the player is the sum of the values of their n turns.
//Return
//	1 if the score of player 1 is more than the score of player 2,
//	2 if the score of player 2 is more than the score of player 1, and
//	0 in case of a draw.
// 
//Example 1:
//Input: player1 = [4,10,7,9], player2 = [6,5,2,3]
//Output: 1
//Explanation: The score of player1 is 4 + 10 + 2*7 + 2*9 = 46.
//The score of player2 is 6 + 5 + 2 + 3 = 16.
//Score of player1 is more than the score of player2, so, player1 is the winner, and the answer is 1.
//Example 2:
//Input: player1 = [3,5,7,6], player2 = [8,10,10,2]
//Output: 2
//Explanation: The score of player1 is 3 + 5 + 7 + 6 = 21.
//The score of player2 is 8 + 10 + 2*10 + 2*2 = 42.
//Score of player2 is more than the score of player1, so, player2 is the winner, and the answer is 2.
//Example 3:
//Input: player1 = [2,3], player2 = [4,1]
//Output: 0
//Explanation: The score of player1 is 2 + 3 = 5
//The score of player2 is 4 + 1 = 5
//The score of player1 equals to the score of player2, so, there is a draw, and the answer is 0.
// 
//Constraints:
//	n == player1.length == player2.length
//	1 <= n <= 1000
//	0 <= player1[i], player2[i] <= 10
int isWinner(int* player1, int player1Size, int* player2, int player2Size){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    for (i = 0; i < player1Size; i++) {
        if (i >= 2 && player1[i] == 10 && player1[i - 1] == 10) {
            k += 2 * player1[i];
        } else if (i >= 1 && player1[i] == 10 && player1[i - 1] == 10) {
            k += 2 * player1[i];
        } else {
            k += player1[i];
        }
    }
    for (i = 0; i < player2Size; i++) {
        if (i >= 2 && player2[i] == 10 && player2[i - 1] == 10) {
            l += 2 * player2[i];
        } else if (i >= 1 && player2[i] == 10 && player2[i - 1] == 10) {
            l += 2 * player2[i];
        } else {
            l += player2[i];
        }
    }
    if (k > l) {
        return 1;
    } else if (k < l) {
        return 2;
    } else {
        return 0;
    }
}