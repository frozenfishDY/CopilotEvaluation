/**https://leetcode.com/problems/vowel-spellchecker/ */
//Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
//For a given query word, the spell checker handles two categories of spelling mistakes:
//Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
//Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
//Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
//Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
//In addition, the spell checker operates under the following precedence rules:
//When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
//When the query matches a word up to capitlization, you should return the first such match in the wordlist.
//When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
//If the query has no matches in the wordlist, you should return the empty string.
//Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** spellchecker(char ** wordlist, int wordlistSize, char ** queries, int queriesSize, int* returnSize){
    *returnSize = queriesSize;
    char** result = (char**)malloc(sizeof(char*) * queriesSize);
    for(int i = 0; i < queriesSize; i++){
        result[i] = (char*)malloc(sizeof(char) * 100);
    }
    for(int i = 0; i < queriesSize; i++){
        int flag = 0;
        for(int j = 0; j < wordlistSize; j++){
            if(strcmp(wordlist[j], queries[i]) == 0){
                strcpy(result[i], wordlist[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        for(int j = 0; j < wordlistSize; j++){
            if(strlen(wordlist[j]) != strlen(queries[i])){
                continue;
            }
            int flag2 = 0;
            for(int k = 0; k < strlen(wordlist[j]); k++){
                if(wordlist[j][k] != queries[i][k]){
                    if(wordlist[j][k] >= 'A' && wordlist[j][k] <= 'Z'){
                        if(wordlist[j][k] + 32 != queries[i][k]){
                            flag2 = 1;
                            break;
                        }
                    }else if(wordlist[j][k] >= 'a' && wordlist[j][k] <= 'z'){
                        if(wordlist[j][k] - 32 != queries[i][k]){
                            flag2 = 1;
                            break;
                        }
                    }else{
                        flag2 = 1;
                        break;
                    }
                }
            }
            if(flag2 == 0){
                strcpy(result[i], wordlist[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            continue;
        }
        for(int j = 0; j < wordlistSize; j++){
            if(strlen(wordlist[j]) != strlen(queries[i])){
                continue;
            }
            int flag2 = 0;
            for(int k = 0; k < strlen(wordlist[j]); k++){
                if(wordlist[j][k] != queries[i][k]){
                    if(wordlist[j][k] == 'a' || wordlist[j][k] == 'e' || wordlist[j][k] == 'i' || wordlist[j][k] == 'o' || wordlist[j][k] == 'u'){
                        if(wordlist[j][k] - 32 != queries[i][k] && wordlist[j][k] + 32 != queries[i][k]){
                            flag2 = 1;
                            break;
                        }
                    }else{
                        flag2 = 1;
                        break;
                    }

                    

}

    