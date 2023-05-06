/**https://leetcode.com/problems/maximum-number-of-coins-you-can-get/ */
//There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:
//In each step, you will choose any 3 piles of coins (not necessarily consecutive).
//Of your choice, Alice will pick the pile with the maximum number of coins.
//You will pick the next pile with the maximum number of coins.
//Your friend Bob will pick the last pile.
//Repeat until there are no more piles of coins.
//Given an array of integers piles where piles[i] is the number of coins in the ith pile.
//Return the maximum number of coins that you can have.


int maxCoins(int* piles, int pilesSize){
    int i, j, k, count = 0;
    int len = pilesSize / 3;
    int temp;
    for(i = 0; i < pilesSize - 1; i++){
        for(j = i + 1; j < pilesSize; j++){
            if(piles[i] < piles[j]){
                temp = piles[i];
                piles[i] = piles[j];
                piles[j] = temp;
            }
        }
    }
    for(i = 1; i < pilesSize; i += 2){
        count += piles[i];
    }
    return count;

}

    