/**https://leetcode.com/problems/split-message-based-on-limit/ */
//You are given a string, message, and a positive integer, limit.
//You must split message into one or more parts based on limit. Each resulting part should have the suffix "<a/b>", where "b" is to be replaced with the total number of parts and "a" is to be replaced with the index of the part, starting from 1 and going up to b. Additionally, the length of each resulting part (including its suffix) should be equal to limit, except for the last part whose length can be at most limit.
//The resulting parts should be formed such that when their suffixes are removed and they are all concatenated in order, they should be equal to message. Also, the result should contain as few parts as possible.
//Return the parts message would be split into as an array of strings. If it is impossible to split message as required, return an empty array.


/**
 * @param {string} message
 * @param {number} limit
 * @return {string[]}
 */
var splitMessage = function(message, limit) {
    let n = message.length;
    let dp = new Array(n + 1).fill(0);
    let par = new Array(n + 1).fill(0);
    for(let i = 1; i <= n; i++){
        dp[i] = 1e9;
        for(let j = 1; j <= i; j++){
            let len = i - j + 1;
            if(len > limit){
                break;
            }
            let cost = len + 1;
            if(dp[i] > dp[j - 1] + cost){
                dp[i] = dp[j - 1] + cost;
                par[i] = j;
            }
        }
    }
    let ans = [];
    let idx = n;
    while(idx > 0){
        let len = idx - par[idx] + 1;
        let part = message.substring(par[idx] - 1, idx);
        let suffix = "/" + (n / len) + ")";
        let rem = limit - len;
        let prefix = "(" + (n / len) + "/";
        let total = prefix + part + suffix;
        if(rem > 0){
            total = total + " ".repeat(rem);
        }
        ans.push(total);
        idx = par[idx] - 1;
    }
    ans.reverse();
    return ans;
    
};

    