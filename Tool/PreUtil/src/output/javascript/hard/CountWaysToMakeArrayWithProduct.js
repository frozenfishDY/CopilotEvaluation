/**https://leetcode.com/problems/count-ways-to-make-array-with-product/ */
//You are given a 2D integer array, queries. For each queries[i], where queries[i] = [ni, ki], find the number of different ways you can place positive integers into an array of size ni such that the product of the integers is ki. As the number of ways may be too large, the answer to the ith query is the number of ways modulo 109 + 7.
//Return an integer array answer where answer.length == queries.length, and answer[i] is the answer to the ith query.


/**
 * @param {number[][]} queries
 * @return {number[]}
 */
var waysToFillArray = function(queries) {
    let n = queries.length;
    let res = new Array(n).fill(0);
    let mod = 1000000007;
    for(let i = 0; i < n; i++){
        let [n, k] = queries[i];
        let factors = new Map();
        let j = 2;
        while(j * j <= k){
            if(k % j == 0){
                let cnt = 0;
                while(k % j == 0){
                    k /= j;
                    cnt++;
                }
                factors.set(j, cnt);
            }
            j++;
        }
        if(k > 1){
            factors.set(k, 1);
        }
        let ans = 1;
        for(let [_, cnt] of factors){
            ans = ans * C(n + cnt - 1, cnt) % mod;
        }
        res[i] = ans;
    }
    return res;
    
    
};

    