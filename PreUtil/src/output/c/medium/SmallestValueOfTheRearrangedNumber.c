/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.


long long smallestNumber(long long num){
    int i, j;
    int count = 0;
    int mod = 1000000007;
    int arr[10] = {0};
    while(num > 0){
        arr[count] = num % 10;
        num = num / 10;
        count++;
    }
    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    long long sum = 0;
    for(i = 0; i < count; i++){
        sum = (sum * 10 + arr[i]) % mod;
    }
    return sum;

}

    