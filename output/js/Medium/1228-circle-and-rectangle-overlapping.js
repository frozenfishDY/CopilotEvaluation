/**https://leetcode.com/problems/circle-and-rectangle-overlapping/ */
//You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.
//Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.


/**
 * @param {number} radius
 * @param {number} xCenter
 * @param {number} yCenter
 * @param {number} x1
 * @param {number} y1
 * @param {number} x2
 * @param {number} y2
 * @return {boolean}
 */
var checkOverlap = function(radius, xCenter, yCenter, x1, y1, x2, y2) {
    let x = Math.max(x1, Math.min(xCenter, x2));
    let y = Math.max(y1, Math.min(yCenter, y2));
    return Math.pow(x - xCenter, 2) + Math.pow(y - yCenter, 2) <= Math.pow(radius, 2);
    
};

    