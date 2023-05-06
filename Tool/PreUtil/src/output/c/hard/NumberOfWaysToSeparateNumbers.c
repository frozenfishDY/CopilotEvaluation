/**https://leetcode.com/problems/number-of-ways-to-separate-numbers/ */
//You wrote down many positive integers in a string called num. However, you realized that you forgot to add commas to seperate the different numbers. You remember that the list of integers was non-decreasing and that no integer had leading zeros.
//Return the number of possible lists of integers that you could have written down to get the string num. Since the answer may be large, return it modulo 109 + 7.


int numberOfCombinations(char * num){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*2);
    for(i=0;i<2;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=0;i<strlen(num);i++){
        for(j=0;j<2;j++){
            if(num[i] == '0'){
                arr[j] = 0;
            }
            else{
                arr[j] = (arr[j] + arr[j-1])%1000000007;
            }
        }
    }
    return arr[1];

}

    