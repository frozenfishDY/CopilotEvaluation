/**https://leetcode.com/problems/top-k-frequent-words/ */
//Given an array of strings words and an integer k, return the k most frequent strings.
//Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** topKFrequent(char ** words, int wordsSize, int k, int* returnSize){
    int* count = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        count[i] = 0;
    }
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; j < wordsSize; j++){
            if(strcmp(words[i], words[j]) == 0){
                count[i]++;
            }
        }
    }
    int* index = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        index[i] = i;
    }
    for(int i = 0; i < wordsSize; i++){
        for(int j = i + 1; j < wordsSize; j++){
            if(count[i] < count[j]){
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }else if(count[i] == count[j]){
                if(strcmp(words[index[i]], words[index[j]]) > 0){
                    int temp = count[i];
                    count[i] = count[j];
                    count[j] = temp;
                    temp = index[i];
                    index[i] = index[j];
                    index[j] = temp;
                }
            }
        }
    }
    char** answer = (char**)malloc(sizeof(char*) * k);
    for(int i = 0; i < k; i++){
        answer[i] = (char*)malloc(sizeof(char) * 11);
        strcpy(answer[i], words[index[i]]);
    }
    *returnSize = k;
    return answer;

}

    