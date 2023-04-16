/**https://leetcode.com/problems/container-with-most-water/ */
//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//Find two lines that together with the x-axis form a container, such that the container contains the most water.
//Return the maximum amount of water a container can store.
//Notice that you may not slant the container.


class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int max = 0;
        int i = 0;
        int j = height.length - 1;
        while(i < j){
            int area = Math.min(height[i], height[j]) * (j - i);
            max = Math.max(max, area);
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return max;
        
    }
}

    