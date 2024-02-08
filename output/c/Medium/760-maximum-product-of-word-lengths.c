/**https://leetcode.com/problems/maximum-product-of-word-lengths/ */
//Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.


int maxProduct(char ** words, int wordsSize){
    int* result = (int*)malloc(sizeof(int) * wordsSize);
    for(int i = 0; i < wordsSize; i++){
        result[i] = 0;
    }
    for(int i = 0; i < wordsSize; i++){
        for(int j = 0; j < strlen(words[i]); j++){
            result[i] |= 1 << (words[i][j] - 'a');
        }
    }
    int max = 0;
    for(int i = 0; i < wordsSize; i++){
        for(int j = i + 1; j < wordsSize; j++){
            if((result[i] & result[j]) == 0){
                int temp = strlen(words[i]) * strlen(words[j]);
                if(temp > max){
                    max = temp;
                }
            }
        }
    }
    return max;

}

    