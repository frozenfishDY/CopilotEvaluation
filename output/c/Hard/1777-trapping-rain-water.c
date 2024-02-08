/**https://leetcode.com/problems/trapping-rain-water/ */
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


int trap(int* height, int heightSize){
    int i = 0;
    int j = 0;
    int maxLeft = 0;
    int maxRight = 0;
    int sum = 0;
    for(i = 1; i < heightSize - 1; i++){
        maxLeft = 0;
        maxRight = 0;
        for(j = i; j >= 0; j--){
            if(height[j] > maxLeft){
                maxLeft = height[j];
            }
        }
        for(j = i; j < heightSize; j++){
            if(height[j] > maxRight){
                maxRight = height[j];
            }
        }
        if(maxLeft > height[i] && maxRight > height[i]){
            sum += (maxLeft < maxRight ? maxLeft : maxRight) - height[i];
        }
    }
    return sum;

}

    