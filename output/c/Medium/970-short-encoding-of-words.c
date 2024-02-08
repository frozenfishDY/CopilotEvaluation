/**https://leetcode.com/problems/short-encoding-of-words/ */
//A valid encoding of an array of words is any reference string s and array of indices indices such that:
//words.length == indices.length
//The reference string s ends with the '#' character.
//For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
//Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.


int minimumLengthEncoding(char ** words, int wordsSize){
    int count = 0;
    int length = strlen(s);
    int* index = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        index[i] = 0;
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < wordsSize; j++){
            if(index[j] == -1){
                continue;
            }
            if(s[i] == words[j][index[j]]){
                index[j]++;
            }
            if(words[j][index[j]] == '\0'){
                count++;
                index[j] = -1;
            }
        }
    }
    return count;

}

    