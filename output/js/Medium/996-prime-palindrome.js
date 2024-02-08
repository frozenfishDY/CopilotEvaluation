/**https://leetcode.com/problems/prime-palindrome/ */
//Given an integer n, return the smallest prime palindrome greater than or equal to n.
//An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
//For example, 2, 3, 5, 7, 11, and 13 are all primes.
//An integer is a palindrome if it reads the same from left to right as it does from right to left.
//For example, 101 and 12321 are palindromes.
//The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].


/**
 * @param {number} n
 * @return {number}
 */
var primePalindrome = function(n) {
    let isPrime = function(n){
        if(n < 2){
            return false;
        }
        let m = Math.floor(Math.sqrt(n));
        for(let i = 2; i <= m; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    };
    let isPalindrome = function(n){
        let str = n.toString();
        let left = 0;
        let right = str.length - 1;
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    };
    if(n <= 2){
        return 2;
    }
    if(n <= 3){
        return 3;
    }
    if(n <= 5){
        return 5;
    }
    if(n <= 7){
        return 7;
    }
    if(n <= 11){
        return 11;
    }
    let left = Math.floor(n / 100);
    let right = left + 1;
    while(true){
        let leftStr = left.toString();
        let rightStr = right.toString();
        let leftPalindrome = parseInt(leftStr + leftStr.split("").reverse().join(""));
        let rightPalindrome = parseInt(rightStr + rightStr.split("").reverse().join(""));
        if(leftPalindrome >= n && isPrime(leftPalindrome)){
            return leftPalindrome;
        }
        if(rightPalindrome >= n && isPrime(rightPalindrome)){
            return rightPalindrome;
        }
        left++;
        right++;
    }
    
};

    