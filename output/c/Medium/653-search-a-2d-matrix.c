/**https://leetcode.com/problems/search-a-2d-matrix/ */
//You are given an m x n integer matrix matrix with the following two properties:
//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
//Given an integer target, return true if target is in matrix or false otherwise.
//You must write a solution in O(log(m * n)) time complexity.


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int left = 0;
    int right = matrixSize * *matrixColSize - 1;
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(matrix[mid / *matrixColSize][mid % *matrixColSize] == target){
            return true;
        }
        else if(matrix[mid / *matrixColSize][mid % *matrixColSize] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;

}

    