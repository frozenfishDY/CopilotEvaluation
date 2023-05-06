/**https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/ */
//You are given a 2D integer array rectangles where rectangles[i] = [li, hi] indicates that ith rectangle has a length of li and a height of hi. You are also given a 2D integer array points where points[j] = [xj, yj] is a point with coordinates (xj, yj).
//The ith rectangle has its bottom-left corner point at the coordinates (0, 0) and its top-right corner point at (li, hi).
//Return an integer array count of length points.length where count[j] is the number of rectangles that contain the jth point.
//The ith rectangle contains the jth point if 0 <= xj <= li and 0 <= yj <= hi. Note that points that lie on the edges of a rectangle are also considered to be contained by that rectangle.


/**
 * @param {number[][]} rectangles
 * @param {number[][]} points
 * @return {number[]}
 */
var countRectangles = function(rectangles, points) {
    let count = [];
    for (let i = 0; i < points.length; i++) {
        let x = points[i][0];
        let y = points[i][1];
        let c = 0;
        for (let j = 0; j < rectangles.length; j++) {
            let l = rectangles[j][0];
            let h = rectangles[j][1];
            if (x <= l && y <= h) {
                c++;
            }
        }
        count.push(c);
    }
    return count;
    
    

};

    