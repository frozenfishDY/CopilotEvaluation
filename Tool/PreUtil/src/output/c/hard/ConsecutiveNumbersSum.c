/**https://leetcode.com/problems/consecutive-numbers-sum/ */
//Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.


int consecutiveNumbersSum(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = i; j <= n; j++){
            sum += j;
            if(sum == n){
                count++;
                break;
            }else if(sum > n){
                break;
            }
        }
    }
    return count;

}

    