/**https://leetcode.com/problems/construct-the-rectangle/ */
//A web developer needs to know how to design a web page's size. So, given a specific rectangular web page��s area, your job by now is to design a rectangular web page, whose length L and width W satisfy the following requirements:
//The area of the rectangular web page you designed must equal to the given target area.
//The width W should not be larger than the length L, which means L >= W.
//The difference between length L and width W should be as small as possible.
//Return an array [L, W] where L and W are the length and width of the web page you designed in sequence.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * 2);
    int i = 1;
    int j = area;
    while(i <= j){
        if(i * j == area){
            result[0] = j;
            result[1] = i;
            break;
        }else if(i * j > area){
            j--;
        }else{
            i++;
        }
    }
    *returnSize = 2;
    return result;

}

    