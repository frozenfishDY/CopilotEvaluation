/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.


int numDupDigitsAtMostN(int n){
    int ans = 0;
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*10);
    for(i=0;i<10;i++){
        arr[i] = 0;
    }
    int temp = n;
    int count = 0;
    while(temp>0){
        arr[temp%10]++;
        temp = temp/10;
        count++;
    }
    for(i=0;i<10;i++){
        if(arr[i]>1){
            ans = ans + 1;
        }
    }
    int* arr2 = (int*)malloc(sizeof(int)*10);
    for(i=0;i<10;i++){
        arr2[i] = 0;
    }
    int temp2 = n;
    int count2 = 0;
    while(temp2>0){
        arr2[temp2%10]++;
        temp2 = temp2/10;
        count2++;
    }
    for(i=0;i<10;i++){
        if(arr2[i]>1){
            ans = ans + 1;
        }
    }
    return ans;

}

    