/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.


char * decodeString(char * s){
    int length = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (length + 1));
    int resultSize = 0;
    int* count = (int*)malloc(sizeof(int) * length);
    int countSize = 0;
    for(int i = 0; i < length; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            int start = i;
            while(s[i] >= '0' && s[i] <= '9'){
                i++;
            }
            char* temp = (char*)malloc(sizeof(char) * (i - start + 1));
            strncpy(temp, s + start, i - start);
            temp[i - start] = '\0';
            count[countSize++] = atoi(temp);
            free(temp);
        }
        if(s[i] == '['){
            continue;
        }
        if(s[i] == ']'){
            int tempSize = 0;
            char* temp = (char*)malloc(sizeof(char) * (resultSize + 1));
            while(resultSize > 0 && result[resultSize - 1] != '['){
                temp[tempSize++] = result[--resultSize];
            }
            resultSize--;
            int tempCount = count[--countSize];
            for(int j = 0; j < tempCount; j++){
                for(int k = tempSize - 1; k >= 0; k--){
                    result[resultSize++] = temp[k];
                }
            }
            free(temp);
        }else{
            result[resultSize++] = s[i];
        }
    }
    result[resultSize] = '\0';
    return result;

}

    