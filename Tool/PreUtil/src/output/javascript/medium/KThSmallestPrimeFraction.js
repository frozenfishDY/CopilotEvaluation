/**https://leetcode.com/problems/k-th-smallest-prime-fraction/ */
//You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
//For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
//Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var kthSmallestPrimeFraction = function(arr, k) {
    let n = arr.length;
    let left = 0;
    let right = 1;
    let result = [];
    while(left < right){
        let mid = left + (right - left) / 2;
        let count = 0;
        let max = 0;
        let maxIndex = 0;
        let j = 1;
        for(let i = 0; i < n - 1; i++){
            while(j < n && arr[i] > mid * arr[j]){
                j++;
            }
            count += n - j;
            if(j < n && max < arr[i] / arr[j]){
                max = arr[i] / arr[j];
                maxIndex = i;
            }
        }
        if(count == k){
            result.push(arr[maxIndex]);
            result.push(arr[j]);
            break;
        }else if(count > k){
            right = mid;
        }else{
            left = mid;
        }
    }
    return result;
    
    
};

    