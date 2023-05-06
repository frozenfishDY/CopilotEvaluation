/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//Each character is decoded as one digit (0 - 9).
//No two characters can map to the same digit.
//Each words[i] and result are decoded as one number without leading zeros.
//Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.


/**
 * @param {string[]} words
 * @param {string} result
 * @return {boolean}
 */
var isSolvable = function(words, result) {
    let n = words.length;
    let m = result.length;
    let max = Math.max(n, m);
    let dp = new Array(max);
    for(let i = 0; i < dp.length; i++){
        dp[i] = new Array(10).fill(false);
    }
    let used = new Array(10).fill(false);
    let dfs = (index, carry) => {
        if(index == max){
            return carry == 0;
        }
        let i = n - 1 - index;
        let j = m - 1 - index;
        let sum = carry;
        if(i >= 0){
            sum += words[i].length - 1 - index;
        }
        if(j >= 0){
            sum -= result[j].length - 1 - index;
        }
        if(sum < 0){
            return false;
        }
        if(dp[index][sum]){
            return false;
        }
        for(let k = 0; k < 10; k++){
            if(used[k]){
                continue;
            }
            used[k] = true;
            if(i >= 0 && words[i][index] == k){
                if(dfs(index + 1, carry)){
                    return true;
                }
            }
            else if(j >= 0 && result[j][index] == k){
                if(dfs(index + 1, carry + 1)){
                    return true;
                }
            }
            else if(i < 0 || j < 0 || words[i][index] != k && result[j][index] != k){
                if(dfs(index + 1, carry)){
                    return true;
                }
            }
            used[k] = false;
        }
        dp[index][sum] = true;
        return false;
    }
    return dfs(0, 0);
    
};

    