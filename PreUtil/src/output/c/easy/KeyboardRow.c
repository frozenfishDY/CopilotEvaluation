/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//In the American keyboard:
//the first row consists of the characters "qwertyuiop",
//the second row consists of the characters "asdfghjkl", and
//the third row consists of the characters "zxcvbnm".


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
    char* row1 = "qwertyuiop";
    char* row2 = "asdfghjkl";
    char* row3 = "zxcvbnm";
    char** ans = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    for(int i = 0; i < wordsSize; i++){
        int j = 0;
        int row = 0;
        while(words[i][j] != '\0'){
            if(strchr(row1, tolower(words[i][j])) != NULL){
                if(row == 0){
                    row = 1;
                }else if(row != 1){
                    break;
                }
            }else if(strchr(row2, tolower(words[i][j])) != NULL){
                if(row == 0){
                    row = 2;
                }else if(row != 2){
                    break;
                }
            }else if(strchr(row3, tolower(words[i][j])) != NULL){
                if(row == 0){
                    row = 3;
                }else if(row != 3){
                    break;
                }
            }
            j++;
        }
        if(words[i][j] == '\0'){
            ans[*returnSize] = (char*)malloc((j + 1) * sizeof(char));
            strcpy(ans[*returnSize], words[i]);
            (*returnSize)++;
        }
    }
    return ans;

}

    