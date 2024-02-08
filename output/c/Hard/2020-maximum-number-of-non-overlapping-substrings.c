/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** maxNumOfSubstrings(char * s, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*26);
    for(i=0;i<26;i++){
        arr

}

    