/**https://leetcode.com/problems/replace-non-coprime-numbers-in-array/ */
//You are given an array of integers nums. Perform the following steps:
//Find any two adjacent numbers in nums that are non-coprime.
//If no such numbers are found, stop the process.
//Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
//Repeat this process as long as you keep finding two adjacent non-coprime numbers.
//Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.
//The test cases are generated such that the values in the final array are less than or equal to 108.
//Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
var replaceNonCoprimes = function(nums) {
    let n = nums.length;
    let max = 0;
    for(let i = 0; i < n; i++){
        max = Math.max(max, nums[i]);
    }
    let prime = new Array(max + 1).fill(true);
    prime[0] = false;
    prime[1] = false;
    for(let i = 2; i * i <= max; i++){
        if(prime[i]){
            for(let j = i * i; j <= max; j += i){
                prime[j] = false;
            }
        }
    }
    let primeFactors = new Array(max + 1).fill(0);
    for(let i = 2; i <= max; i++){
        if(prime[i]){
            for(let j = i; j <= max; j += i){
                primeFactors[j]++;
            }
        }
    }
    let ans = new Array(n).fill(0);
    for(let i = 0; i < n; i++){
        if(primeFactors[nums[i]] == 1){
            ans[i] = nums[i];
        }
    }
    for(let i = 0; i < n; i++){
        if(ans[i] == 0){
            let j = i + 1;
            while(j < n && ans[j] == 0){
                j++;
            }
            if(j < n){
                let lcm = nums[i] * nums[j] / gcd(nums[i], nums[j]);
                for(let k = i; k < j; k++){
                    ans[k] = lcm;
                }
            }
            i = j;
        }
    }
    return ans;
    
    
};

    