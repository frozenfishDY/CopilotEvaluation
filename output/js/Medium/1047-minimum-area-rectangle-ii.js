/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.


/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaFreeRect = function(points) {
    let n = points.length;
    let result = 100000000000000000;
    let set = new Set();
    for(let i = 0; i < n; i++){
        set.add(points[i][0] + "," + points[i][1]);
    }
    for(let i = 0; i < n; i++){
        for(let j = i + 1; j < n; j++){
            for(let k = j + 1; k < n; k++){
                let x1 = points[i][0];
                let y1 = points[i][1];
                let x2 = points[j][0];
                let y2 = points[j][1];
                let x3 = points[k][0];
                let y3 = points[k][1];
                let x4 = x1 + x2 - x3;
                let y4 = y1 + y2 - y3;
                if(set.has(x4 + "," + y4)){
                    let a = Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                    let b = Math.sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
                    result = Math.min(result, a * b);
                }
            }
        }
    }
    if(result == 100000000000000000){
        return 0;
    }
    return result;
    
};

    