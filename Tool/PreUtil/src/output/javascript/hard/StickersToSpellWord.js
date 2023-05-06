/**https://leetcode.com/problems/stickers-to-spell-word/ */
//We are given n different types of stickers. Each sticker has a lowercase English word on it.
//You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
//Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.


/**
 * @param {string[]} stickers
 * @param {string} target
 * @return {number}
 */
var minStickers = function(stickers, target) {
    let n = target.length;
    let dp = [];
    for(let i = 0; i <= n; i++){
        dp.push([]);
        for(let j = 0; j <= n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i <= n; i++){
        dp[i][i] = 1;
    }
    for(let i = 1; i <= n; i++){
        for(let j = i - 1; j >= 0; j--){
            if(s[i - 1] === s[j]){
                dp[i][j] = dp[i - 1][j];
            }else{
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j + 1]) + 1;
            }
        }
    }
    return dp[n][0];
    
};

    