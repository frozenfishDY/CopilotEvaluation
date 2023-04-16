/**https://leetcode.com/problems/circular-sentence/ */
//A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
//For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
//Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.
//A sentence is circular if:
//The last character of a word is equal to the first character of the next word.
//The last character of the last word is equal to the first character of the first word.
//For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.
//Given a string sentence, return true if it is circular. Otherwise, return false.


/**
 * @param {string} sentence
 * @return {boolean}
 */
var isCircularSentence = function(sentence) {
    let words = sentence.split(" ");
    for(let i = 0; i < words.length - 1; i++){
        if(words[i][words[i].length - 1] != words[i + 1][0]){
            return false;
        }
    }
    if(words[words.length - 1][words[words.length - 1].length - 1] != words[0][0]){
        return false;
    }
    return true;
    
};

    