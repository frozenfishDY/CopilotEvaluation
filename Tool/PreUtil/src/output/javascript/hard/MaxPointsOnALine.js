/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    let n = points.length;
    if(n < 3){
        return n;
    }
    let max = 0;
    for(let i = 0; i < n; i++){
        let map = new Map();
        let same = 1;
        for(let j = i + 1; j < n; j++){
            if(points[i][0] === points[j][0] && points[i][1] === points[j][1]){
                same++;
                continue;
            }
            let slope = getSlope(points[i], points[j]);
            if(map.has(slope)){
                map.set(slope, map.get(slope) + 1);
            }else{
                map.set(slope, 2);
            }
        }
        let localMax = 0;
        for(let [key, value] of map){
            localMax = Math.max(localMax, value);
        }
        max = Math.max(max, localMax + same);
    }
    return max;
    
    
};

    