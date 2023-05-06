/**https://leetcode.com/problems/maximum-score-words-formed-by-letters/ */
//Given a list of words, list of  single letters (might be repeating) and score of every character.
//Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
//It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.


/**
 * @param {string[]} words
 * @param {character[]} letters
 * @param {number[]} score
 * @return {number}
 */
var maxScoreWords = function(words, letters, score) {
    let freq = new Map();
    for(let i = 0; i < letters.length; i++){
        let c = freq.get(letters[i]) || 0;
        freq.set(letters[i], c + 1);
    }
    let ans = 0;
    let dfs = function(i, freq, score){
        if(i == words.length){
            return 0;
        }
        let f = new Map(freq);
        let s = 0;
        for(let j = 0; j < words[i].length; j++){
            let c = f.get(words[i][j]) || 0;
            if(c == 0){
                return dfs(i + 1, freq, score);
            }
            f.set(words[i][j], c - 1);
            s += score[words[i].charCodeAt(j) - 97];
        }
        return Math.max(s + dfs(i + 1, f, score), dfs(i + 1, freq, score));
    }
    return dfs(0, freq, score);
    
};

    