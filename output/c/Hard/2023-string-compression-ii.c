/**https://leetcode.com/problems/string-compression-ii/ */
//Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".
//Notice that in this problem, we are not adding '1' after single characters.
//Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.
//Find the minimum length of the run-length encoded version of s after deleting at most k characters.


int getLengthOfOptimalCompression(char * s, int k){
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

    