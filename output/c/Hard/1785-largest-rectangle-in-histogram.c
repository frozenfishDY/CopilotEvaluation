/**https://leetcode.com/problems/largest-rectangle-in-histogram/ */
//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


int largestRectangleArea(int* heights, int heightsSize){
    int max = 0;
    int *stack = (int*)malloc(sizeof(int) * heightsSize);
    int top = -1;
    int i = 0;
    int cur = 0;
    int width = 0;
    while(i < heightsSize){
        if(top == -1 || heights[stack[top]] <= heights[i]){
            stack[++top] = i++;
        }else{
            cur = stack[top--];
            width = top == -1 ? i : i - stack[top] - 1;
            if(heights[cur] * width > max) max = heights[cur] * width;
        }
    }
    while(top != -1){
        cur = stack[top--];
        width = top == -1 ? i : i - stack[top] - 1;
        if(heights[cur] * width > max) max = heights[cur] * width;
    }
    return max;
    

}

    