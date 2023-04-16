/**https://leetcode.com/problems/push-dominoes/ */
//There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//You are given a string dominoes representing the initial state where:
//dominoes[i] = 'L', if the ith domino has been pushed to the left,
//dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//dominoes[i] = '.', if the ith domino has not been pushed.
//Return a string representing the final state.


/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    let n = dominoes.length;
    let result = new Array(n).fill('.');
    let left = -1;
    let right = -1;
    for(let i = 0; i < n; i++){
        if(dominoes[i] == 'R'){
            right = i;
            result[i] = 'R';
        }
        else if(dominoes[i] == 'L'){
            if(right == -1){
                for(let j = left + 1; j < i; j++){
                    result[j] = 'L';
                }
            }
            else{
                let j = right + 1;
                let k = i - 1;
                while(j < k){
                    result[j] = 'R';
                    result[k] = 'L';
                    j++;
                    k--;
                }
                if(j == k){
                    result[j] = '.';
                }
                right = -1;
            }
            left = i;
        }
    }
    if(right != -1){
        for(let j = right + 1; j < n; j++){
            result[j] = 'R';
        }
    }
    return result.join('');    
};

    