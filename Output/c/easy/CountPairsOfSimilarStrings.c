/**https://leetcode.com/problems/count-pairs-of-similar-strings/ */
//You are given a 0-indexed string array words.
//Two strings are similar if they consist of the same characters.
//For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
//However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
//Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.


int similarPairs(char ** words, int wordsSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int arr[26] = {0};
    int arr1[26] = {0};
    for(i = 0; i < wordsSize; i++){
        for(j = 0; j < 26; j++){
            arr[j] = 0;
            arr1[j] = 0;
        }
        for(j = 0; j < strlen(words[i]); j++){
            arr[words[i][j] - 'a']++;
        }
        for(j = i + 1; j < wordsSize; j++){
            for(k = 0; k < strlen(words[j]); k++){
                arr1[words[j][k] - 'a']++;
            }
            for(k = 0; k < 26; k++){
                if(arr[k] != arr1[k]){
                    break;
                }
            }
            if(k == 26){
                count++;
            }
        }
    }
    return count;

}

    