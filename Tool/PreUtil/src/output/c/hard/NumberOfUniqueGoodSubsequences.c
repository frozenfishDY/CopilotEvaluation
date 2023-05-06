/**https://leetcode.com/problems/number-of-unique-good-subsequences/ */
//You are given a binary string binary. A subsequence of binary is considered good if it is not empty and has no leading zeros (with the exception of "0").
//Find the number of unique good subsequences of binary.
//For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1". Note that subsequences "00", "01", and "001" are not good because they have leading zeros.
//Return the number of unique good subsequences of binary. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


int numberOfUniqueGoodSubsequences(char * binary){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*2);
    for(i=0;i<2;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=0;i<strlen(binary);i++){
        if(binary[i] == '0'){
            arr[0] = (arr[0] + arr[1])%1000000007;
        }
        else{
            arr[1] = (arr[0] + arr[1])%1000000007;
        }
    }
    return arr[0];

}

    