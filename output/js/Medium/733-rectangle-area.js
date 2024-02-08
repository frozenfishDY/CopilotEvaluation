/**https://leetcode.com/problems/rectangle-area/ */
//Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two rectangles.
//The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
//The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).


/**
 * @param {number} ax1
 * @param {number} ay1
 * @param {number} ax2
 * @param {number} ay2
 * @param {number} bx1
 * @param {number} by1
 * @param {number} bx2
 * @param {number} by2
 * @return {number}
 */
var computeArea = function(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {
    let area1 = (ax2 - ax1) * (ay2 - ay1);
    let area2 = (bx2 - bx1) * (by2 - by1);
    let overlap = 0;
    if(ax1 < bx2 && ax2 > bx1 && ay1 < by2 && ay2 > by1){
        let x = Math.min(ax2, bx2) - Math.max(ax1, bx1);
        let y = Math.min(ay2, by2) - Math.max(ay1, by1);
        overlap = x * y;
    }
    return area1 + area2 - overlap;
    
};

    