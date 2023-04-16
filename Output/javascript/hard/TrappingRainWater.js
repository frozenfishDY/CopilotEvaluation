/**https://leetcode.com/problems/trapping-rain-water/ */
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let len = height.length;
    let left = 0;
    let right = len - 1;
    let leftMax = 0;
    let rightMax = 0;
    let res = 0;
    while(left < right){
        if(height[left] < height[right]){
            if(height[left] >= leftMax){
                leftMax = height[left];
            }else{
                res += leftMax - height[left];
            }
            left++;
        }else{
            if(height[right] >= rightMax){
                rightMax = height[right];
            }else{
                res += rightMax - height[right];
            }
            right--;
        }
    }
    return res;
    
};

    