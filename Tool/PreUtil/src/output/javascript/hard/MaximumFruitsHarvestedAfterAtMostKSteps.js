/**https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/ */
//Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.
//You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.
//Return the maximum total number of fruits you can harvest.


/**
 * @param {number[][]} fruits
 * @param {number} startPos
 * @param {number} k
 * @return {number}
 */
var maxTotalFruits = function(fruits, startPos, k) {
    let n = fruits.length;
    let ans = 0;
    let dfs = (i, j, k, curr) => {
        if(k < 0){
            return;
        }
        if(i < 0 || j >= n){
            return;
        }
        if(fruits[i][0] == fruits[j][0]){
            ans = Math.max(ans, curr + fruits[i][1]);
            dfs(i - 1, j, k - 1, curr + fruits[i][1]);
            dfs(i, j + 1, k - 1, curr + fruits[j][1]);
        }else{
            ans = Math.max(ans, curr + fruits[i][1] + fruits[j][1]);
            dfs(i - 1, j, k - 1, curr + fruits[i][1]);
            dfs(i, j + 1, k - 1, curr + fruits[j][1]);
        }
    }
    dfs(startPos, startPos, k, 0);
    return ans;
    
};

    