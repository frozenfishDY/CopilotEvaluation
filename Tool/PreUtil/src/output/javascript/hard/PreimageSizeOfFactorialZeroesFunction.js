/**https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/ */
//Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.
//For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
//Given an integer k, return the number of non-negative integers x have the property that f(x) = k.


/**
 * @param {number} k
 * @return {number}
 */
var preimageSizeFZF = function(k) {
    let low = 0;
    let high = 5 * (k + 1);
    while(low < high){
        let mid = Math.floor((low + high) / 2);
        let count = countZero(mid);
        if(count == k){
            return 5;
        }else if(count < k){
            low = mid + 1;
        }else{
            high = mid;
        }
    }
    return 0;
    
    
};

    