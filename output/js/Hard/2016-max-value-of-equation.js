/**https://leetcode.com/problems/max-value-of-equation/ */
//You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
//Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
//It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.


/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number}
 */
var findMaxValueOfEquation = function(points, k) {
    let n = points.length;
    let ans = -Infinity;
    let pq = new PriorityQueue();
    for(let i = 0; i < n; i++){
        while(pq.length > 0 && points[i][0] - pq.peek()[1] > k){
            pq.pop();
        }
        if(pq.length > 0){
            ans = Math.max(ans, pq.peek()[0] + points[i][1] + points[i][0]);
        }
        pq.push([points[i][1] - points[i][0], points[i][0]]);
    }
    return ans;
    

    
};

    