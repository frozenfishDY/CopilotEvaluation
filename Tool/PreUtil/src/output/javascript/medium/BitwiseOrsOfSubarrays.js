/**https://leetcode.com/problems/bitwise-ors-of-subarrays/ */
//Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
//The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
//A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} arr
 * @return {number}
 */
var subarrayBitwiseORs = function(arr) {
    let n = arr.length;
    let set = new Set();
    let prev = new Set();
    for(let i = 0; i < n; i++){
        let curr = new Set();
        curr.add(arr[i]);
        for(let x of prev){
            curr.add(x | arr[i]);
        }
        for(let x of curr){
            set.add(x);
        }
        prev = curr;
    }
    return set.size;
    
};

    