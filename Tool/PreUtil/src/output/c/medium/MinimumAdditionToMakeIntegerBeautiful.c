/**https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/ */
//You are given two positive integers n and target.
//An integer is considered beautiful if the sum of its digits is less than or equal to target.
//Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.


long long makeIntegerBeautiful(long long n, int target){
    int i;
    int sum = 0;
    int mod = 1000000007;
    int count = 0;
    int arr[10] = {0};
    while(n > 0){
        arr[count] = n % 10;
        n = n / 10;
        count++;
    }
    for(i = 0; i < count; i++){
        sum += arr[i];
    }
    if(sum > target){
        return 0;
    }
    else{
        return target - sum;
    }

}

    