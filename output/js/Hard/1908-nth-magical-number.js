/**https://leetcode.com/problems/nth-magical-number/ */
//A positive integer is magical if it is divisible by either a or b.
//Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 10^9 + 7.


/**
 * @param {number} n
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var nthMagicalNumber = function(n, a, b) {
    let lcm = a * b / gcd(a, b);
    let left = Math.min(a, b);
    let right = Math.max(a, b) * n;
    while(left < right){
        let mid = Math.floor((left + right) / 2);
        if(Math.floor(mid / a) + Math.floor(mid / b) - Math.floor(mid / lcm) < n){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left % 1000000007;
    
    
};

    