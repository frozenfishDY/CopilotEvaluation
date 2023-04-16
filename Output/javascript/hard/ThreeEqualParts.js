/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//arr[0], arr[1], ..., arr[i] is the first part,
//arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.


/**
 * @param {number[]} arr
 * @return {number[]}
 */
var threeEqualParts = function(arr) {
    let dp = [];
    for(let i = 0; i <= arr.length; i++){
        dp.push([]);
        for(let j = 0; j <= arr.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= arr.length; i++){
        dp[i][0] = 1;
    }
    for(let i = 1; i <= arr.length; i++){
        for(let j = 1; j <= arr.length; j++){
            if(i > j){
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    let ans = [];
    for(let i = 1; i <= arr.length; i++){
        ans.push(dp[arr.length][i] - dp[arr.length][i - 1]);
    }
    return ans;
    
};

    