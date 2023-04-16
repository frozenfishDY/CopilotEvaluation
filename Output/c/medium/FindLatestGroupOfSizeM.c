/**https://leetcode.com/problems/find-latest-group-of-size-m/ */
//Given an array arr that represents a permutation of numbers from 1 to n.
//You have a binary string of size n that initially has all its bits set to zero. At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.
//You are also given an integer m. Find the latest step at which there exists a group of ones of length m. A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.
//Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.


int findLatestStep(int* arr, int arrSize, int m){
    int i, j, k, l, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* arr2 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int) * arrSize);
    for(i = 0; i < arrSize; i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int) * arrSize);

}

    