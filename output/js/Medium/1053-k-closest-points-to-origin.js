/**https://leetcode.com/problems/k-closest-points-to-origin/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance (i.e., ��(x1 - x2)2 + (y1 - y2)2).
//You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) {
    let n = points.length;
    let result = [];
    let map = new Map();
    for(let i = 0; i < n; i++){
        let dist = Math.sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        if(map.has(dist)){
            map.get(dist).push(points[i]);
        }else{
            map.set(dist, [points[i]]);
        }
    }
    let sorted = Array.from(map.keys()).sort((a, b) => a - b);
    for(let i = 0; i < sorted.length; i++){
        let arr = map.get(sorted[i]);
        for(let j = 0; j < arr.length; j++){
            result.push(arr[j]);
            if(result.length == k){
                return result;
            }
        }
    }
    return result;
    
};

    