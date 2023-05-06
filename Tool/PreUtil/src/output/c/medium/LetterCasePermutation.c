/**https://leetcode.com/problems/letter-case-permutation/ */
//Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
//Return a list of all possible strings we could create. Return the output in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCasePermutation(char * s, int* returnSize){
    int length = strlen(s);
    int count = 1;
    for(int i = 0; i < length; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            count *= 2;
        }
    }
    char** answer = (char**)malloc(sizeof(char*) * count);
    for(int i = 0; i < count; i++){
        answer[i] = (char*)malloc(sizeof(char) * (length + 1));
        strcpy(answer[i], s);
    }
    int index = 0;
    for(int i = 0; i < length; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            for(int j = 0; j < count; j++){
                if(j % (int)pow(2, index) == 0){
                    answer[j][i] = s[i] + 32;
                }
            }
            index++;
        }
    }
    *returnSize = count;
    return answer;

}

    