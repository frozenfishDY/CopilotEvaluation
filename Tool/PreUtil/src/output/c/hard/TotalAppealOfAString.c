/**https://leetcode.com/problems/total-appeal-of-a-string/ */
//The appeal of a string is the number of distinct characters found in the string.
//For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
//Given a string s, return the total appeal of all of its substrings.
//A substring is a contiguous sequence of characters within a string.


long long appealSum(char * s){
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

    