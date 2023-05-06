/**https://leetcode.com/problems/count-vowels-permutation/ */
//Given an integer n, your task is to count how many strings of length n can be formed under the following rules:
//Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
//Each vowel 'a' may only be followed by an 'e'.
//Each vowel 'e' may only be followed by an 'a' or an 'i'.
//Each vowel 'i' may not be followed by another 'i'.
//Each vowel 'o' may only be followed by an 'i' or a 'u'.
//Each vowel 'u' may only be followed by an 'a'.
//Since the answer may be too large, return it modulo 10^9 + 7.


int countVowelPermutation(int n){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*5);
    for(i=0;i<5;i++){
        arr[i] = 1;
    }
    int* arr2 = (int*)malloc(sizeof(int)*5);
    for(i=0;i<5;i++){
        arr2[i] = 0;
    }
    for(i=1;i<n;i++){
        arr2[0] = (arr[1] + arr[2] + arr[4])%1000000007;
        arr2[1] = (arr[0] + arr[2])%1000000007;
        arr2[2] = (arr[1] + arr[3])%1000000007;
        arr2[3] = (arr[2])%1000000007;
        arr2[4] = (arr[2] + arr[3])%1000000007;
        for(j=0;j<5;j++){
            arr[j] = arr2[j];
        }
    }
    int ans = 0;
    for(i=0;i<5;i++){
        ans = (ans + arr[i])%1000000007;
    }
    return ans;

}

    