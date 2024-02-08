/**https://leetcode.com/problems/largest-rectangle-in-histogram/ */
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
    let stack = [];
    let max = 0;
    for(let i = 0; i <= heights.length; i++){
        let current = i === heights.length ? -1 : heights[i];
        while(stack.length > 0 && current <= heights[stack[stack.length - 1]]){
            let h = heights[stack.pop()];
            let w = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
            max = Math.max(max, h * w);
        }
        stack.push(i);
    }
    return max;
    
};

    