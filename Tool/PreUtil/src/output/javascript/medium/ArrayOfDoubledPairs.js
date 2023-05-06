/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.


/**
 * @param {number[]} arr
 * @return {boolean}
 */
var canReorderDoubled = function(arr) {
    let count = new Array(20001).fill(0);
    for(let i = 0; i < arr.length; i++){
        count[arr[i] + 10000]++;
    }
    for(let i = 0; i < 20001; i++){
        if(count[i] > count[2 * i] || count[2 * i] > count[i] && count[i] > 0){
            return false;
        }
        count[2 * i] -= count[i];
    }
    return true;
    
};

    