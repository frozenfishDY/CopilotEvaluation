/**https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/ */
//There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.
//In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.
//Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.


/**
 * @param {number[][]} piles
 * @param {number} k
 * @return {number}
 */
var maxValueOfCoins = function(piles, k) {
    let n = piles.length;
    let ans = 0;
    piles.sort((a, b) => b[0] - a[0]);
    for(let i = 0; i < n; i++){
        if(i % 2 == 1){
            ans += piles[i][0];
            k--;
        }
        if(k == 0){
            break;
        }
    }
    return ans;
    
};

    