/**https://leetcode.com/problems/find-palindrome-with-fixed-length/ */
//Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.
//A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.
// 
//Example 1:
//Input: queries = [1,2,3,4,5,90], intLength = 3
//Output: [101,111,121,131,141,999]
//Explanation:
//The first few palindromes of length 3 are:
//101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
//The 90th palindrome of length 3 is 999.
//Example 2:
//Input: queries = [2,4,6], intLength = 4
//Output: [1111,1331,1551]
//Explanation:
//The first six palindromes of length 4 are:
//1001, 1111, 1221, 1331, 1441, and 1551.
// 
//Constraints:
//	1 <= queries.length <= 5 * 104
//	1 <= queries[i] <= 109
//	1 <= intLength <= 15
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* kthPalindrome(int* queries, int queriesSize, int intLength, int* returnSize){
long long* ret = malloc(sizeof(long long)*queriesSize);
    int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    int prev;
    int next;
    int* arr = malloc(sizeof(int)*queriesSize);
    i=0;
    while(i<queriesSize){
        arr[i++]=0;
    }
    i=0;
    while(i<queriesSize){
        arr[i++]=queries[i];
    }
    i=0;
    while(i<queriesSize){
        left=queries[i]-1;
        right=queries[i]+1;
        if(left<0){
            left=0;
        }
        if(right>queriesSize-1){
            right=queriesSize-1;
        }
        count=0;
        for(j=left;j<=right;j++){
            if(arr[j]>0){
                count++;
            }
        }
        ret[i]=count;
        i++;
    }
    *returnSize=queriesSize;
    return ret;
}