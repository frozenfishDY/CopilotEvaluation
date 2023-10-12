/**https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/ */
//You are given two 2D integer arrays nums1 and nums2.
//	nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
//	nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
//Each array contains unique ids and is sorted in ascending order by id.
//Merge the two arrays into one array that is sorted in ascending order by id, respecting the following conditions:
//	Only ids that appear in at least one of the two arrays should be included in the resulting array.
//	Each id should be included only once and its value should be the sum of the values of this id in the two arrays. If the id does not exist in one of the two arrays then its value in that array is considered to be 0.
//Return the resulting array. The returned array must be sorted in ascending order by id.
// 
//Example 1:
//Input: nums1 = [[1,2],[2,3],[4,5]], nums2 = [[1,4],[3,2],[4,1]]
//Output: [[1,6],[2,3],[3,2],[4,6]]
//Explanation: The resulting array contains the following:
//- id = 1, the value of this id is 2 + 4 = 6.
//- id = 2, the value of this id is 3.
//- id = 3, the value of this id is 2.
//- id = 4, the value of this id is 5 + 1 = 6.
//Example 2:
//Input: nums1 = [[2,4],[3,6],[5,5]], nums2 = [[1,3],[4,3]]
//Output: [[1,3],[2,4],[3,6],[4,3],[5,5]]
//Explanation: There are no common ids, so we just include each id with its value in the resulting list.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 200
//	nums1[i].length == nums2[j].length == 2
//	1 <= idi, vali <= 1000
//	Both arrays contain unique ids.
//	Both arrays are in strictly ascending order by id.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int **res = (int**)calloc(nums1Size + nums2Size, sizeof(int*));
    int *col = (int*)calloc(nums1Size + nums2Size, sizeof(int));
    *returnSize = 0;
    for (i = 0; i < nums1Size; i++) {
        for (j = 0; j < nums2Size; j++) {
            if (nums1[i][0] == nums2[j][0]) {
                nums1[i][1] += nums2[j][1];
                nums2[j][1] = 0;
            }
        }
    }
    for (i = 0; i < nums1Size; i++) {
        if (nums1[i][1] != 0) {
            res[*returnSize] = (int*)calloc(2, sizeof(int));
            col[*returnSize] = 2;
            res[*returnSize][0] = nums1[i][0];
            res[*returnSize][1] = nums1[i][1];
            (*returnSize)++;
        }
    }
    for (i = 0; i < nums2Size; i++) {
        if (nums2[i][1] != 0) {
            res[*returnSize] = (int*)calloc(2, sizeof(int));
            col[*returnSize] = 2;
            res[*returnSize][0] = nums2[i][0];
            res[*returnSize][1] = nums2[i][1];
            (*returnSize)++;
        }
    }
    *returnColumnSizes = col;
    return res;
}