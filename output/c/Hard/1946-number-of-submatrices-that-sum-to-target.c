/**https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/ */
//Given a matrix and a target, return the number of non-empty submatrices that sum to target.
//A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
//Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
// 
//Example 1:
//Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
//Output: 4
//Explanation: The four 1x1 submatrices that only contain 0.
//Example 2:
//Input: matrix = [[1,-1],[-1,1]], target = 0
//Output: 5
//Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.
//Example 3:
//Input: matrix = [[904]], target = 0
//Output: 0
// 
//Constraints:
//	1 <= matrix.length <= 100
//	1 <= matrix[0].length <= 100
//	-1000 <= matrix[i] <= 1000
//	-10^8 <= target <= 10^8
int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target){
int res = 0;
    for (int i = 0; i < matrixSize; i++) {
        int *sum = (int *)malloc(sizeof(int) * matrixColSize[0]);
        memset(sum, 0, sizeof(int) * matrixColSize[0]);
        for (int j = i; j < matrixSize; j++) {
            for (int k = 0; k < matrixColSize[0]; k++) {
                sum[k] += matrix[j][k];
            }
            res += subarraySum(sum, matrixColSize[0], target);
        }
    }
    return res;
}
int subarraySum(int *nums, int numsSize, int k) {
    int *map = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(map, 0, sizeof(int) * (numsSize + 1));
    map[0] = 1;
    int pre = 0, res = 0;
    for (int i = 0; i < numsSize; i++) {
        pre += nums[i];
        if (map[pre - k]) res += map[pre - k];
        map[pre]++;
    }
    return res;
}