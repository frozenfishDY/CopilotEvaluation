/**https://leetcode.com/problems/prime-arrangements/ */
//Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)
//(Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)
//Since the answer may be large, return the answer modulo 10^9 + 7.
// 
//Example 1:
//Input: n = 5
//Output: 12
//Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
//Example 2:
//Input: n = 100
//Output: 682289015
// 
//Constraints:
//	1 <= n <= 100
int numPrimeArrangements(int n){
int i,j,count=0;
    long long int sum=1;
    for(i=2;i<=n;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i){
            count++;
        }
    }
    for(i=1;i<=count;i++){
        sum=sum*i%1000000007;
    }
    for(i=1;i<=n-count;i++){
        sum=sum*i%1000000007;
    }
    return sum;
}