/**https://leetcode.com/problems/bag-of-tokens/ */
//You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).
//Your goal is to maximize your total score by potentially playing each token in one of two ways:
//If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
//If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
//Each token may be played at most once and in any order. You do not have to play all the tokens.
//Return the largest possible score you can achieve after playing any number of tokens.


/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    let n = tokens.length;
    let result = 0;
    let score = 0;
    tokens.sort((a, b) => a - b);
    let i = 0;
    let j = n - 1;
    while(i <= j){
        if(power >= tokens[i]){
            power -= tokens[i];
            score++;
            result = Math.max(result, score);
            i++;
        }else if(score > 0){
            power += tokens[j];
            score--;
            j--;
        }else{
            break;
        }
    }
    return result;
    
};

    