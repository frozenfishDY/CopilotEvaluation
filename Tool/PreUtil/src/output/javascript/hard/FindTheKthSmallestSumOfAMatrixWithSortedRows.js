/**https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/ */
//You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.
//You are allowed to choose exactly one element from each row to form an array.
//Return the kth smallest array sum among all possible arrays.


/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(mat, k) {
    let m = mat.length;
    let n = mat[0].length;
    let pq = new PriorityQueue();
    let sum = 0;
    for(let i = 0; i < m; i++){
        sum += mat[i][0];
    }
    pq.push(sum);
    let visited = new Set();
    visited.add(sum);
    let ans = 0;
    while(k > 0){
        let cur = pq.pop();
        ans = cur;
        for(let i = 0; i < m; i++){
            for(let j = 0; j < n; j++){
                let next = cur - mat[i][0] + mat[i][j];
                if(!visited.has(next)){
                    pq.push(next);
                    visited.add(next);
                }
            }
        }
        k--;
    }
    return ans;
    
};

    