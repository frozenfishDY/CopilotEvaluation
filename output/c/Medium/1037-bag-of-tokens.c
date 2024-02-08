/**https://leetcode.com/problems/bag-of-tokens/ */
//You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
//Your goal is to maximize your total score by potentially playing each token in one of two ways:
//If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
//If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
//Each token may be played at most once and in any order. You do not have to play all the tokens.
//Return the largest possible score you can achieve after playing any number of tokens.


int bagOfTokensScore(int* tokens, int tokensSize, int power){
    int* hash = (int*)malloc(sizeof(int) * tokensSize);
    for(int i = 0; i < tokensSize; i++){
        hash[i] = 0;
    }
    int score = 0;
    int maxScore = 0;
    for(int i = 0; i < tokensSize; i++){
        if(hash[i] == 0 && power >= tokens[i]){
            hash[i] = 1;
            power -= tokens[i];
            score++;
            if(score > maxScore){
                maxScore = score;
            }
        }
    }
    for(int i = 0; i < tokensSize; i++){
        if(hash[i] == 0 && score > 0){
            hash[i] = 1;
            power += tokens[i];
            score--;
        }
    }
    return maxScore;

}

    