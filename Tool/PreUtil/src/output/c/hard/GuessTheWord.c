/**https://leetcode.com/problems/guess-the-word/ */
//You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word.
//You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns:
//-1 if word is not from words, or
//an integer representing the number of exact matches (value and position) of your guess to the secret word.
//There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word).
//For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:
//"Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or
//"You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.
//The test cases are generated such that you can guess the secret word with a reasonable strategy (other than using the bruteforce method).


/**
 * *********************************************************************
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int guess(Master *, char *word);
 */
void findSecretWord(char** words, int wordsSize, Master* master) {
    int* queue = (int*)malloc(sizeof(int) * wordsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < wordsSize; i++) queue[tail++] = i;
    while(head < tail){
        int index = queue[head++];
        int match = guess(master, words[index]);
        if(match == 6) return;
        int* newQueue = (int*)malloc(sizeof(int) * wordsSize);
        int newHead = 0, newTail = 0;
        for(int i = 0; i < tail; i++){
            int j = queue[i];
            if(match == 0){
                if(words[index][0] != words[j][0] || words[index][1] != words[j][1] || words[index][2] != words[j][2] || words[index][3] != words[j][3] || words[index][4] != words[j][4] || words[index][5] != words[j][5]) newQueue[newTail++] = j;
            }else if(match == 1){
                if(words[index][0] == words[j][0] || words[index][1] == words[j][1] || words[index][2] == words[j][2] || words[index][3] == words[j][3] || words[index][4] == words[j][4] || words[index][5] == words[j][5]) newQueue[newTail++] = j;
            }else if(match == 2){
                if(words[index][0] == words[j][0] && words[index][1] == words[j][1] || words[index][0] == words[j][0] && words[index][2] == words[j][2] || words[index][0] == words[j][0] && words[index][3] == words[j][3] || words[index][0] == words[j][0] && words[index][4] == words[j][4] || words[index][0] == words[j][0] && words[index][5] == words[j][5] || words[index][1] == words[j][1] && words[index][2] == words[j][2] || words[index][1] == words[j][1] && words[index][3] == words[j][3] || words[index][1] == words
    
}

    