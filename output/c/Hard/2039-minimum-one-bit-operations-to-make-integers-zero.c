/**https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/ */
//Given an integer n, you must transform it into 0 using the following operations any number of times:
//Change the rightmost (0th) bit in the binary representation of n.
//Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
//Return the minimum number of operations to transform n into 0.


int minimumOneBitOperations(int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<n;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[n-1];

}

    