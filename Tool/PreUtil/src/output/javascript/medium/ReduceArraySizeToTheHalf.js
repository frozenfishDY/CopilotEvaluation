/**https://leetcode.com/problems/reduce-array-size-to-the-half/ */
//You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
//Return the minimum size of the set so that at least half of the integers of the array are removed.


/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
    let map = new Map();
    for(let i = 0; i < arr.length; i++){
        if(map.has(arr[i])){
            map.set(arr[i], map.get(arr[i]) + 1);
        }else{
            map.set(arr[i], 1);
        }
    }
    let values = Array.from(map.values());
    values.sort((a, b) => b - a);
    let result = 0;
    let sum = 0;
    for(let i = 0; i < values.length; i++){
        sum += values[i];
        result++;
        if(sum >= arr.length / 2){
            break;
        }
    }
    return result;
    
};

    