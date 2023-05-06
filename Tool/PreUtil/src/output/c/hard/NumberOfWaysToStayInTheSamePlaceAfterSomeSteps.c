/**https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/ */
//You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).
//Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 10^9 + 7.


int numWays(int steps, int arrLen){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*arrLen);
    for(i=0;i<arrLen;i++){
        arr[i] = 1;
    }
    int* arr2 = (int*)malloc(sizeof(int)*arrLen);
    for(i=0;i<arrLen;i++){
        arr2[i] = 0;
    }
    for(i=1;i<steps;i++){
        for(j=0;j<arrLen;j++){
            if(j==0){
                arr2[j] = (arr[j] + arr[j+1])%1000000007;
            }
            else if(j==arrLen-1){
                arr2[j] = (arr[j] + arr[j-1])%1000000007;
            }
            else{
                arr2[j] = (arr[j] + arr[j-1] + arr[j+1])%1000000007;
            }
        }
        for(j=0;j<arrLen;j++){
            arr[j] = arr2[j];
        }
    }
    return arr[0];

}

    