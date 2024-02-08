/**https://leetcode.com/problems/maximum-swap/ */
//You are given an integer num. You can swap two digits at most once to get the maximum valued number.
//Return the maximum valued number you can get.


/**
 * @param {number} num
 * @return {number}
 */
var maximumSwap = function(num) {
    let arr = num.toString().split('');
    let n = arr.length;
    let max = arr[n - 1];
    let maxIndex = n - 1;
    let swapIndex = -1;
    for(let i = n - 2; i >= 0; i--){
        if(arr[i] < max){
            swapIndex = i;
        }else if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    if(swapIndex != -1){
        let temp = arr[swapIndex];
        arr[swapIndex] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
    return parseInt(arr.join(''));
    
};

    