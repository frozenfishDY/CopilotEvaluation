/**https://leetcode.com/problems/allocate-mailboxes/ */
//Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
//Return the minimum total distance between each house and its nearest mailbox.
//The test cases are generated so that the answer fits in a 32-bit integer.


/**
 * @param {number[]} houses
 * @param {number} k
 * @return {number}
 */
var minDistance = function(houses, k) {
    houses.sort((a, b) => a - b);
    let n = houses.length;
    let dp = new Array(n).fill(0).map(() => new Array(n).fill(0));
    for(let i = 0; i < n; i++){
        for(let j = i; j < n; j++){
            let mid = (i + j) >> 1;
            for(let k = i; k <= j; k++){
                dp[i][j] += Math.abs(houses[k] - houses[mid]);
            }
        }
    }
    let dp2 = new Array(n).fill(0).map(() => new Array(k).fill(0));
    for(let i = 0; i < n; i++){
        dp2[i][0] = dp[0][i];
    }
    for(let i = 1; i < n; i++){
        for(let j = 1; j < k; j++){
            dp2[i][j] = Infinity;
            for(let l = 0; l < i; l++){
                dp2[i][j] = Math.min(dp2[i][j], dp2[l][j - 1] + dp[l + 1][i]);
            }
        }
    }
    return dp2[n - 1][k - 1];
    
};

    