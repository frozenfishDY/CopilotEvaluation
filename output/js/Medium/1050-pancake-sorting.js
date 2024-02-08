/**https://leetcode.com/problems/pancake-sorting/ */
//Given an array of integers arr, sort the array by performing a series of pancake flips.
//In one pancake flip we do the following steps:
//Choose an integer k where 1 <= k <= arr.length.
//Reverse the sub-array arr[0...k-1] (0-indexed).
//For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.
//Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.


/**
 * @param {number[]} arr
 * @return {number[]}
 */
var pancakeSort = function(arr) {
    let result = [];
    let n = arr.length;
    let index = new Array(n + 1).fill(0);
    for(let i = 0; i < n; i++){
        index[arr[i]] = i;
    }
    for(let i = n; i >= 1; i--){
        let j = index[i];
        if(j == i - 1){
            continue;
        }
        if(j != 0){
            result.push(j + 1);
            reverse(arr, j + 1);
        }
        result.push(i);
        reverse(arr, i);
    }
    return result;
    
    
};

    