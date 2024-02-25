/**https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/ */
//You are given a list of strings of the same length words and a string target.
//Your task is to form target using the given words under the following rules:
//target should be formed from left to right.
//To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//Repeat the process until you form the string target.
//Notice that you can use multiple characters from the same string in words provided the conditions above are met.
//Return the number of ways to form target from words. Since the answer may be too large, return it modulo 10^9 + 7.


int numWays(char ** words, int wordsSize, char * target){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*100000);
    for(i=0;i<100000;i++){
        arr[i] = 0;
    }
    int len = strlen(target);
    int* arr2 = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr2[i] = 0;
    }
    for(i=0;i<wordsSize;i++){
        int len2 = strlen(words[i]);
        for(j=0;j<len2;j++){
            if(words[i][j]==target[0]){
                arr[j] = (arr[j] + 1) % 1000000007;
            }
        }
    }
    for(i=1;i<len;i++){
        for(j=0;j<wordsSize;j++){
            int len2 = strlen(words[j]);
            for(k=0;k<len2;k++){
                if(words[j][k]==target[i]){
                    arr2[k] = (arr2[k] + arr[k-1]) % 1000000007;
                }
            }
        }
        for(j=0;j<len2;j++){
            arr[j] = arr2[j];
        }
    }
    int sum = 0;
    for(i=0;i<len2;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    