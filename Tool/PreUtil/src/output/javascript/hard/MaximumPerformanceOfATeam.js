/**https://leetcode.com/problems/maximum-performance-of-a-team/ */
//You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
//Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
//The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
//Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.


/**
 * @param {number} n
 * @param {number[]} speed
 * @param {number[]} efficiency
 * @param {number} k
 * @return {number}
 */
var maxPerformance = function(n, speed, efficiency, k) {
    let mod = 1000000007;
    let arr = [];
    for(let i = 0; i < n; i++){
        arr.push([speed[i], efficiency[i]]);
    }
    arr.sort((a, b) => b[1] - a[1]);
    let pq = new PriorityQueue();
    let sum = 0;
    let ans = 0;
    for(let i = 0; i < n; i++){
        pq.push(arr[i][0]);
        sum += arr[i][0];
        if(pq.size() > k){
            sum -= pq.pop();
        }
        ans = Math.max(ans, sum * arr[i][1]);
    }
    return ans % mod;
    
    
};

    