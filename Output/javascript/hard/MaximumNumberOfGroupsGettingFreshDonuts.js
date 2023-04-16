/**https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/ */
//There is a donuts shop that bakes donuts in batches of batchSize. They have a rule where they must serve all of the donuts of a batch before serving any donuts of the next batch. You are given an integer batchSize and an integer array groups, where groups[i] denotes that there is a group of groups[i] customers that will visit the shop. Each customer will get exactly one donut.
//When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.
//You can freely rearrange the ordering of the groups. Return the maximum possible number of happy groups after rearranging the groups.


/**
 * @param {number} batchSize
 * @param {number[]} groups
 * @return {number}
 */
var maxHappyGroups = function(batchSize, groups) {
    let dp = new Array(batchSize).fill(0);
    let result = 0;
    for (let i = 0; i < groups.length; i++) {
        if (groups[i] % batchSize == 0) {
            result++;
            groups[i] = -1;
        }
    }
    for (let i = 0; i < groups.length; i++) {
        if (groups[i] != -1) {
            let remain = groups[i] % batchSize;
            dp[remain]++;
        }
    }
    for (let i = 1; i < batchSize; i++) {
        let j = batchSize - i;
        if (i == j) {
            result += Math.floor(dp[i] / 2);
        } else {
            result += Math.min(dp[i], dp[j]);
        }
    }
    return result;
    
};

    