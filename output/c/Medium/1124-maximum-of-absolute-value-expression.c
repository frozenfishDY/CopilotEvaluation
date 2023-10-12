/**https://leetcode.com/problems/maximum-of-absolute-value-expression/ */
//Given two arrays of integers with equal lengths, return the maximum value of:_x000D_
//_x000D_
//|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|_x000D_
//_x000D_
//where the maximum is taken over all 0 <= i, j < arr1.length._x000D_
// 
//Example 1:
//Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
//Output: 13
//Example 2:
//Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
//Output: 20
// 
//Constraints:
//	2 <= arr1.length == arr2.length <= 40000
//	-10^6 <= arr1[i], arr2[i] <= 10^6
int maxAbsValExpr(int* arr1, int arr1Size, int* arr2, int arr2Size){
int *A = (int *)malloc(sizeof(int) * arr1Size);
    int *B = (int *)malloc(sizeof(int) * arr1Size);
    int *C = (int *)malloc(sizeof(int) * arr1Size);
    int *D = (int *)malloc(sizeof(int) * arr1Size);
    for (int i = 0; i < arr1Size; ++i) {
        A[i] = arr1[i] + arr2[i] + i;
        B[i] = arr1[i] - arr2[i] + i;
        C[i] = arr1[i] + arr2[i] - i;
        D[i] = arr1[i] - arr2[i] - i;
    }
    int res = 0;
    int minA = A[0], maxA = A[0];
    int minB = B[0], maxB = B[0];
    int minC = C[0], maxC = C[0];
    int minD = D[0], maxD = D[0];
    for (int i = 1; i < arr1Size; ++i) {
        res = fmax(res, A[i] - minA);
        res = fmax(res, maxA - A[i]);
        res = fmax(res, B[i] - minB);
        res = fmax(res, maxB - B[i]);
        res = fmax(res, C[i] - minC);
        res = fmax(res, maxC - C[i]);
        res = fmax(res, D[i] - minD);
        res = fmax(res, maxD - D[i]);
        minA = fmin(minA, A[i]);
        maxA = fmax(maxA, A[i]);
        minB = fmin(minB, B[i]);
        maxB = fmax(maxB, B[i]);
        minC = fmin(minC, C[i]);
        maxC = fmax(maxC, C[i]);
        minD = fmin(minD, D[i]);
        maxD = fmax(maxD, D[i]);
    }
    return res;
}