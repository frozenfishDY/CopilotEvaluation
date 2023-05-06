/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.


/**
 * @param {number[][]} envelopes
 * @return {number}
 */
var maxEnvelopes = function(envelopes) {
    let n = envelopes.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push(1);
    }
    envelopes.sort((a, b) => a[0] - b[0]);
    for(let i = 1; i <= n; i++){
        for(let j = 1; j < i; j++){
            if(envelopes[i - 1][0] > envelopes[j - 1][0] && envelopes[i - 1][1] > envelopes[j - 1][1]){
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }
    let result = 0;
    for(let i = 1; i <= n; i++){
        result = Math.max(result, dp[i]);
    }
    return result;
    
};

    