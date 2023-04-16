/**https://leetcode.com/problems/reorder-data-in-log-files/ */
//You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
//There are two types of logs:
//Letter-logs: All words (except the identifier) consist of lowercase English letters.
//Digit-logs: All words (except the identifier) consist of digits.
//Reorder these logs so that:
//The letter-logs come before all digit-logs.
//The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
//The digit-logs maintain their relative ordering.
//Return the final order of the logs.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * logsSize);
    for(int i = 0; i < logsSize; i++){
        result[i] = (char*)malloc(sizeof(char) * 100);
    }
    *returnSize = logsSize;
    int index = 0;
    for(int i = 0; i < logsSize; i++){
        int length = strlen(logs[i]);
        int j = 0;
        for(j = 0; j < length; j++){
            if(logs[i][j] == ' '){
                break;
            }
        }
        if(logs[i][j + 1] >= '0' && logs[i][j + 1] <= '9'){
            strcpy(result[index], logs[i]);
            index++;
        }
    }
    for(int i = 0; i < logsSize; i++){
        int length = strlen(logs[i]);
        int j = 0;
        for(j = 0; j < length; j++){
            if(logs[i][j] == ' '){
                break;
            }
        }
        if(logs[i][j + 1] >= 'a' && logs[i][j + 1] <= 'z'){
            strcpy(result[index], logs[i]);
            index++;
        }
    }
    for(int i = 0; i < logsSize; i++){
        int length = strlen(result[i]);
        int j = 0;
        for(j = 0; j < length; j++){
            if(result[i][j] == ' '){
                break;
            }
        }
        int k = j + 1;
        for(k = j + 1; k < length; k++){
            if(result[i][k] == ' '){
                break;
            }
        }
        int l = k + 1;
        for(l = k + 1; l < length; l++){
            if(result[i][l] == ' '){
                break;
            }
        }
        int m = l + 1;
        for(m = l + 1; m < length; m++){
            if(result[i][m] == ' '){
                break;
            }
        }
        int n = m + 1;
        for(n = m + 1; n < length; n++){
            if(result[i][n] == ' '){
                break;
            }
            

}

    