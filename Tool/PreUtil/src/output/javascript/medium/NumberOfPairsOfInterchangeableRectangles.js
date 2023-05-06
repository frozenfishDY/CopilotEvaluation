/**https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/ */
//You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
//Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
//Return the number of pairs of interchangeable rectangles in rectangles.


/**
 * @param {number[][]} rectangles
 * @return {number}
 */
var interchangeableRectangles = function(rectangles) {
    let map = new Map();
    let count = 0;
    for (let i = 0; i < rectangles.length; i++) {
        let ratio = rectangles[i][0] / rectangles[i][1];
        if (map.has(ratio)) {
            count += map.get(ratio);
            map.set(ratio, map.get(ratio) + 1);
        } else {
            map.set(ratio, 1);
        }
    }
    return count;
    
};

    