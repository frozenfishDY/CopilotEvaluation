/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.


/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaRect = function(points) {
    let n = points.length;
    let result = 100000000000000000;
    let set = new Set();
    for(let i = 0; i < n; i++){
        set.add(points[i][0] + "," + points[i][1]);
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            if(points[i][0] != points[j][0] && points[i][1] != points[j][1]){
                if(set.has(points[i][0] + "," + points[j][1]) && set.has(points[j][0] + "," + points[i][1])){
                    result = Math.min(result, Math.abs(points[i][0] - points[j][0]) * Math.abs(points[i][1] - points[j][1]));
                }
            }
        }
    }
    if(result == 100000000000000000){
        return 0;
    }
    return result;
    
};

    