/**https://leetcode.com/problems/number-of-beautiful-partitions/ */
//You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
//A partition of s is called beautiful if:
//s is partitioned into k non-intersecting substrings.
//Each substring has a length of at least minLength.
//Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
//Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
//A substring is a contiguous sequence of characters within a string.


int beautifulPartitions(char * s, int k, int minLength){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*2);
    for(i=0;i<2;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=0;i<strlen(s);i++){
        if(s[i] == '0'){
            arr[0] = (arr[0] + arr[1])%1000000007;
        }
        else{
            arr[1] = (arr[0] + arr[1])%1000000007;
        }
    }
    return arr[0];

}

    