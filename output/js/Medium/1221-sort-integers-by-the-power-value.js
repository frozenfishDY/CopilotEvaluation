/**https://leetcode.com/problems/sort-integers-by-the-power-value/ */
//The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
//if x is even then x = x / 2
//if x is odd then x = 3 * x + 1
//For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
//Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.
//Return the kth integer in the range [lo, hi] sorted by the power value.
//Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.


/**
 * @param {number} lo
 * @param {number} hi
 * @param {number} k
 * @return {number}
 */
var getKth = function(lo, hi, k) {
    let map = new Map();
    for (let i = lo; i <= hi; i++) {
        let count = 0;
        let j = i;
        while (j !== 1) {
            if (j % 2 === 0) {
                j /= 2;
            } else {
                j = 3 * j + 1;
            }
            count++;
        }
        map.set(i, count);
    }
    let arr = [];
    for (let i = lo; i <= hi; i++) {
        arr.push(i);
    }
    arr.sort((a, b) => {
        if (map.get(a) === map.get(b)) {
            return a - b;
        } else {
            return map.get(a) - map.get(b);
        }
    });
    return arr[k - 1];
    
};

    