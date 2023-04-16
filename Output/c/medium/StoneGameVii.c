/**https://leetcode.com/problems/stone-game-vii/ */
//Alice and Bob take turns playing a game, with Alice starting first.
//There are n stones arranged in a row. On each player's turn, they can remove either the leftmost stone or the rightmost stone from the row and receive points equal to the sum of the remaining stones' values in the row. The winner is the one with the higher score when there are no stones left to remove.
//Bob found that he will always lose this game (poor Bob, he always loses), so he decided to minimize the score's difference. Alice's goal is to maximize the difference in the score.
//Given an array of integers stones where stones[i] represents the value of the ith stone from the left, return the difference in Alice and Bob's score if they both play optimally.


int stoneGameVII(int* stones, int stonesSize){
    int* arr = malloc(stonesSize * sizeof(int));
    int sum = 0;
    for(int i = 0; i < stonesSize; i++){
        sum += stones[i];
    }
    int leftSum = 0;
    for(int i = 0; i < stonesSize; i++){
        arr[i] = (stones[i] - leftSum) - (sum - leftSum - stones[i]);
        leftSum += stones[i];
    }
    int max = 0;
    for(int i = 0; i < stonesSize; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}

    