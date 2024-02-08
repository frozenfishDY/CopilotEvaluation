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
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class GuessTheWord {
    public void findSecretWord(String[] words, Master master) {
        int n = words.length;
        int[][] count = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = 0;
                for (int k = 0; k < 6; k++) {
                    if (words[i].charAt(k) == words[j].charAt(k)) {
                        c++;
                    }
                }
                count[i][j] = c;
                count[j][i] = c;
            }
        }
        int[] match = new int[n];
        for (int i = 0; i < n; i++) {
            match[i] = n;
        }
        for (int i = 0; i < n; i++) {
            int min = Integer.MAX_VALUE;
            int index = -1;
            for (int j = 0; j < n; j++) {
                if (match[j] < min) {
                    min = match[j];
                    index = j;
                }
            }
            int c = master.guess(words[index]);
            if (c == 6) {
                return;
            }
            match[index] = -1;
            for (int j = 0; j < n; j++) {
                if (match[j] != -1 && count[index][j] == c) {
                    match[j]--;
                }
            }
        }
        
    }
}
     
    