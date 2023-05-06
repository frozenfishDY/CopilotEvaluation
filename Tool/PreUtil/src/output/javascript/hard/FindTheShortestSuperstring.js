/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.


/**
 * @param {string[]} words
 * @return {string}
 */
var shortestSuperstring = function(words) {
    let dp = [];
    for(let i = 0; i < words.length; i++){
        dp.push([]);
        for(let j = 0; j < words.length; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i < words.length; i++){
        for(let j = 0; j < words.length; j++){
            if(i == j){
                continue;
            }
            let min = Math.min(words[i].length, words[j].length);
            for(let k = min; k >= 0; k--){
                if(words[i].endsWith(words[j].substring(0, k))){
                    dp[i][j] = k;
                    break;
                }
            }
        }
    }
    let memo = [];
    for(let i = 0; i < words.length; i++){
        memo.push([]);
        for(let j = 0; j < (1 << words.length); j++){
            memo[i].push(-1);
        }
    }
    let ans = Number.MAX_SAFE_INTEGER;
    let ansIndex = -1;
    for(let i = 0; i < words.length; i++){
        let temp = dfs(i, 1 << i, words, dp, memo);
        if(temp < ans){
            ans = temp;
            ansIndex = i;
        }
    }
    let result = words[ansIndex];
    let used = 1 << ansIndex;
    while(used != (1 << words.length) - 1){
        for(let i = 0; i < words.length; i++){
            if((used & (1 << i)) == 0){
                let temp = dfs(i, used | (1 << i), words, dp, memo);
                if(temp == ans - words[i].length + dp[ansIndex][i]){
                    ans = temp;
                    ansIndex = i;
                    used |= (1 << i);
                    result += words[i].substring(dp[ansIndex][i]);
                    break;
                }
            }
        }
    }
    return result;
    
    
};

    