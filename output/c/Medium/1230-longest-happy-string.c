/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//s only contains the letters 'a', 'b', and 'c'.
//s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//s contains at most a occurrences of the letter 'a'.
//s contains at most b occurrences of the letter 'b'.
//s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.


char * longestDiverseString(int a, int b, int c){
    int i, j, k, count = 0, max = 0, maxIndex = 0;
    char *str = (char*)malloc(100000 * sizeof(char));
    int *arr = (int*)malloc(3 * sizeof(int));
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    for(i = 0; i < 100000; i++){
        str[i] = '\0';
    }
    for(i = 0; i < 3; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    if(maxIndex == 0){
        for(i = 0; i < max; i++){
            str[count++] = 'a';
        }
        arr[0] = 0;
    }
    else if(maxIndex == 1){
        for(i = 0; i < max; i++){
            str[count++] = 'b';
        }
        arr[1] = 0;
    }
    else{
        for(i = 0; i < max; i++){
            str[count++] = 'c';
        }
        arr[2] = 0;
    }
    for(i = 0; i < 3; i++){
        if(arr[i] > 0){
            if(i == 0){
                for(j = 0; j < arr[i]; j++){
                    str[count++] = 'a';
                }
            }
            else if(i == 1){
                for(j = 0; j < arr[i]; j++){
                    str[count++] = 'b';
                }
            }
            else{
                for(j = 0; j < arr[i]; j++){
                    str[count++] = 'c';
                }
            }
        }
    }
    return str;

}

    