/**https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ */
//Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//You must find a solution with a memory complexity better than O(n2).


class KthSmallestElementInASortedMatrix {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while(left < right){
            int mid = left + (right - left) / 2;
            int count = 0;
            int j = n - 1;
            for(int i = 0; i < n; i++){
                while(j >= 0 && matrix[i][j] > mid){
                    j--;
                }
                count += (j + 1);
            }
            if(count < k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
        
        
        
    }
}

    