/**https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/ */
//Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//You must find a solution with a memory complexity better than O(n2).


/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    let n = matrix.length;
    let minHeap = new MinHeap();
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            minHeap.insert(matrix[i][j]);
        }
    }
    let result = 0;
    while(k > 0 && minHeap.size() > 0){
        result = minHeap.remove();
        k--;
    }
    return result;
    
    
    
};

    