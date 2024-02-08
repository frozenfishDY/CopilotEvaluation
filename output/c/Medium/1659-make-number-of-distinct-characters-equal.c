/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.


bool isItPossible(char * word1, char * word2){
    int* hash1 = (int*)calloc(26, sizeof(int));
    int* hash2 = (int*)calloc(26, sizeof(int));
    for(int i = 0; i < strlen(word1); i++){
        hash1[word1[i] - 'a']++;
    }
    for(int i = 0; i < strlen(word2); i++){
        hash2[word2[i] - 'a']++;
    }
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 26; i++){
        if(hash1[i] > 0){
            count1++;
        }
        if(hash2[i] > 0){
            count2++;
        }
    }
    if(count1 == count2){
        return true;
    }
    if(count1 > count2){
        for(int i = 0; i < 26; i++){
            if(hash1[i] > 0 && hash2[i] == 0){
                return true;
            }
        }
    }
    if(count1 < count2){
        for(int i = 0; i < 26; i++){
            if(hash2[i] > 0 && hash1[i] == 0){
                return true;
            }
        }
    }
    return false;

}

    