/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.


/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var minInteger = function(num, k) {
    let arr = num.split('');
    let n = arr.length;
    let res = '';
    let i = 0;
    while(i < n){
        let min = arr[i];
        let minIndex = i;
        for(let j = i + 1; j < n && j <= i + k; j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        res += min;
        k -= minIndex - i;
        for(let j = minIndex; j > i; j--){
            arr[j] = arr[j - 1];
        }
        i++;
    }
    return res;
    
    
};

    