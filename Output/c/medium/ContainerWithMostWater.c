/**https://leetcode.com/problems/container-with-most-water/ */
//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//Find two lines that together with the x-axis form a container, such that the container contains the most water.
//Return the maximum amount of water a container can store.
//Notice that you may not slant the container.


int maxArea(int* height, int heightSize){
    int i = 0;
    int j = 0;
    int max = 0;
    int area = 0;
    for(i = 0; i < heightSize; i++){
        for(j = i + 1; j < heightSize; j++){
            area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
            if(area > max){
                max = area;
            }
        }
    }
    return max;

}

    