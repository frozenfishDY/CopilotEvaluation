/**https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/ */
//You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
//	horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
//	verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
//Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
// 
//Example 1:
//Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
//Output: 4 
//Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
//Example 2:
//Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
//Output: 6
//Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
//Example 3:
//Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
//Output: 9
// 
//Constraints:
//	2 <= h, w <= 109
//	1 <= horizontalCuts.length <= min(h - 1, 105)
//	1 <= verticalCuts.length <= min(w - 1, 105)
//	1 <= horizontalCuts[i] < h
//	1 <= verticalCuts[i] < w
//	All the elements in horizontalCuts are distinct.
//	All the elements in verticalCuts are distinct.
int maxArea(int h, int w, int* horizontalCuts, int horizontalCutsSize, int* verticalCuts, int verticalCutsSize){
int *hArr = calloc(horizontalCutsSize + 1, sizeof(int));
    int *vArr = calloc(verticalCutsSize + 1, sizeof(int));
    for (int i = 0; i < horizontalCutsSize; i++) {
        hArr[i] = horizontalCuts[i];
    }
    for (int i = 0; i < verticalCutsSize; i++) {
        vArr[i] = verticalCuts[i];
    }
    hArr[horizontalCutsSize] = h;
    vArr[verticalCutsSize] = w;
    qsort(hArr, horizontalCutsSize + 1, sizeof(int), cmp);
    qsort(vArr, verticalCutsSize + 1, sizeof(int), cmp);
    int maxH = 0;
    for (int i = 0; i < horizontalCutsSize + 1; i++) {
        if (hArr[i] - hArr[i - 1] > maxH) {
            maxH = hArr[i] - hArr[i - 1];
        }
    }
    int maxV = 0;
    for (int i = 0; i < verticalCutsSize + 1; i++) {
        if (vArr[i] - vArr[i - 1] > maxV) {
            maxV = vArr[i] - vArr[i - 1];
        }
    }
    free(hArr);
    free(vArr);
    return (int)((long)maxH * maxV % 1000000007);

}