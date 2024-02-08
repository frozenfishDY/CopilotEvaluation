/**https://leetcode.com/problems/largest-palindromic-number/ */
//You are given a string num consisting of digits only.
//Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.
//Notes:
//	You do not need to use all the digits of num, but you must use at least one digit.
//	The digits can be reordered.
// 
//Example 1:
//Input: num = "444947137"
//Output: "7449447"
//Explanation: 
//Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
//It can be shown that "7449447" is the largest palindromic integer that can be formed.
//Example 2:
//Input: num = "00009"
//Output: "9"
//Explanation: 
//It can be shown that "9" is the largest palindromic integer that can be formed.
//Note that the integer returned should not contain leading zeroes.
// 
//Constraints:
//	1 <= num.length <= 105
//	num consists of digits.
/**
 * @param {string} num
 * @return {string}
 */
var largestPalindromic = function(num) {
    let n = num.length;
    let arr = new Array(10).fill(0);
    for (let i = 0; i < n; i++) {
        arr[num[i].charCodeAt() - 48]++;
    }
    let res = "";
    let i = 9;
    while (i >= 0) {
        while (arr[i] > 0) {
            res += i;
            arr[i]--;
        }
        i--;
    }
    let l = 0;
    let r = res.length - 1;
    while (l < r) {
        if (res[l] === res[r]) {
            l++;
            r--;
        } else {
            break;
        }
    }
    if (l >= r) return res;
    let arr2 = [...res];
    let arr3 = [...res];
    let l2 = l;
    let r2 = r;
    while (l2 < r2) {
        if (res[l2] === res[r2]) {
            l2++;
            r2--;
        } else if (res[l2] < res[r2]) {
            while (l < r) {
                if (res[l] === res[r]) {
                    l++;
                    r--;
                } else {
                    arr2[r] = res[l];
                    break;
                }
            }
            break;
        } else {
            while (l < r) {
                if (res[l] === res[r]) {
                    l++;
                    r--;
                } else {
                    arr3[l] = res[r];
                    break;
                }
            }
            break;
        }
    }
    return arr2.join("") > arr3.join("") ? arr2.join("") : arr3.join("");

};