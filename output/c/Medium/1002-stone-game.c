/**https://leetcode.com/problems/stone-game/ */
//Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
//The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.
//Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
//Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.


bool stoneGame(int* piles, int pilesSize){
    int* dp = (int*)malloc(sizeof(int) * pilesSize);
    for(int i = 0; i < pilesSize; i++){
        dp[i] = piles[i];
    }
    for(int i = 1; i < pilesSize; i++){
        for(int j = 0; j < pilesSize - i; j++){
            dp[j] = fmax(piles[j] - dp[j + 1], piles[j + i] - dp[j]);
        }
    }
    return dp[0] > 0;

}

    