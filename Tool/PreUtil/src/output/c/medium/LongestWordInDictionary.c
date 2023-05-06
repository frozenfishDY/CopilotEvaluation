/**https://leetcode.com/problems/longest-word-in-dictionary/ */
//Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
//If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
//Note that the word should be built from left to right with each additional character being added to the end of a previous word. 


char * longestWord(char ** words, int wordsSize){
    char* answer = (char*)malloc(sizeof(char) * 31);
    strcpy(answer, "");
    for(int i = 0; i < wordsSize; i++){
        int j = 0;
        int k = 0;
        int flag = 1;
        while(words[i][j] != '\0'){
            char temp = words[i][j];
            words[i][j] = '\0';
            while(k < wordsSize){
                if(strcmp(words[i], words[k]) == 0){
                    break;
                }
                k++;
            }
            if(k == wordsSize){
                flag = 0;
                break;
            }
            words[i][j] = temp;
            j++;
            k = 0;
        }
        if(flag == 1){
            if(strlen(words[i]) > strlen(answer)){
                strcpy(answer, words[i]);
            }else if(strlen(words[i]) == strlen(answer)){
                if(strcmp(words[i], answer) < 0){
                    strcpy(answer, words[i]);
                }
            }
        }
    }
    return answer;

}

    