/**https://leetcode.com/problems/camelcase-matching/ */
//Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.
//A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    bool* result = (bool*)malloc(sizeof(bool) * queriesSize);
    int length = strlen(pattern);
    int* index = (int*)malloc(sizeof(int) * queriesSize);
    for(int i = 0; i < queriesSize; i++){
        index[i] = 0;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < queriesSize; j++){
            if(index[j] == -1){
                continue;
            }
            if(pattern[i] == queries[j][index[j]]){
                index[j]++;
            }
            else{
                while(queries[j][index[j]] != '\0' && queries[j][index[j]] >= 'a' && queries[j][index[j]] <= 'z'){
                    index[j]++;
                }
                if(queries[j][index[j]] == '\0'){
                    index[j] = -1;
                }
                else if(queries[j][index[j]] == pattern[i]){
                    index[j]++;
                }
                else{
                    index[j] = -1;
                }
            }
        }
    }
    for(int j = 0; j < queriesSize; j++){
        if(index[j] == -1){
            result[j] = false;
        }
        else{
            while(queries[j][index[j]] != '\0' && queries[j][index[j]] >= 'a' && queries[j][index[j]] <= 'z'){
                index[j]++;
            }
            if(queries[j][index[j]] == '\0'){
                result[j] = true;
            }
            else{
                result[j] = false;
            }
        }
    }
    *returnSize = queriesSize;
    return result;

}

    