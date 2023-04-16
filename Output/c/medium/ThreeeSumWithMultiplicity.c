/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 10^9 + 7.


int threeSumMulti(int* arr, int arrSize, int target){
    int mod = 1000000007;
    int* count = (int*)malloc(sizeof(int) * 101);
    for(int i = 0; i < arrSize; i++){
        count[arr[i]]++;
    }
    long long res = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = i; j <= 100; j++){
            int k = target - i - j;
            if(k < 0 || k > 100){
                continue;
            }
            if(i == j && j == k){
                res += (long long)count[i] * (count[i] - 1) * (count[i] - 2) / 6;
            }else if(i == j && j != k){
                res += (long long)count[i] * (count[i] - 1) / 2 * count[k];
            }else if(i < j && j < k){
                res += (long long)count[i] * count[j] * count[k];
            }
        }
    }
    return res % mod;

}

    