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
 * // This is the master's API interface.
 * // You should not implement it, or speculate about its implementation
 * function Master() {
 *
 *     @param {string} word
 *     @return {integer}
 *     this.guess = function(word) {
 *         ...
 *     };
 * };
 */
/**
 * @param {string[]} words
 * @param {Master} master
 * @return {void}
 */
var findSecretWord = function(words, master) {
    let n = words.length;
    let dp = [];
    for(let i = 0; i < n; i++){
        dp.push([]);
        for(let j = 0; j < n; j++){
            dp[i].push(0);
        }
    }
    for(let i = 0; i < n; i++){
        for(let j = 0; j < n; j++){
            if(i != j){
                let count = 0;
                for(let k = 0; k < 6; k++){
                    if(words[i][k] == words[j][k]){
                        count++;
                    }
                }
                dp[i][j] = count;
            }
        }
    }
    let used = [];
    for(let i = 0; i < n; i++){
        used.push(false);
    }
    for(let i = 0; i < 10; i++){
        let max = 0;
        let index = 0;
        for(let j = 0; j < n; j++){
            if(!used[j]){
                let count = 0;
                for(let k = 0; k < n; k++){
                    if(!used[k]){
                        count += dp[j][k];
                    }
                }
                if(count > max){
                    max = count;
                    index = j;
                }
            }
        }
        let guess = master.guess(words[index]);
        if(guess == 6){
            return;
        }
        used[index] = true;
        for(let j = 0; j < n; j++){
            if(dp[index][j] != guess){
                used[j] = true;
            }
        }
    }
    
};

    