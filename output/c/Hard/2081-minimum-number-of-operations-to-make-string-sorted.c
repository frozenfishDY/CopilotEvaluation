/**https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/ */
//You are given a string s (0-indexed) you are asked to perform the following operation on s until you get a sorted string:
//Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
//Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
//Swap the two characters at indices i - 1 and j.
//Reverse the suffix starting at index i.
//Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 10^9 + 7.


int makeStringSorted(char * s){
    int i,j,k;
    int len = strlen(s);
    int* arr = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr[i] = 0;
    }
    for(i=0;i<len;i++){
        int num = 0;
        for(j=i;j<len;j++){
            num = num*10 + (s[j]-'0');
            if(num<=100000){
                if(i==0){
                    arr[j] = 1;
                }
                else{
                    arr[j] = (arr[j] + arr2[i-1]) % 1000000007;
                }
            }
            else{
                break;
            }
        }
        for(j=0;j<len;j++){
            arr2[j] = arr[j];
        }
    }
    return arr[len-1];

}

    