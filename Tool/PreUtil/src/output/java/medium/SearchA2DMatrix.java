/**https://leetcode.com/problems/search-a-2d-matrix/ */
//You are given an m x n integer matrix matrix with the following two properties:
//Each row is sorted in non-decreasing order.
//The first integer of each row is greater than the last integer of the previous row.
//Given an integer target, return true if target is in matrix or false otherwise.
//You must write a solution in O(log(m * n)) time complexity.


class SearchA2DMatrix {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int left = 0;
        int right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target){
                return true;
            }
            if(matrix[row][col] < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
        
    }
}

    