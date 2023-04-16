/**https://leetcode.com/problems/word-ladder/ */
//A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//Every adjacent pair of words differs by a single letter.
//Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.


/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {number}
 */
var ladderLength = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList);
    if(!wordSet.has(endWord)){
        return 0;
    }
    let visited = new Set();
    let queue = [[beginWord, 1]];
    while(queue.length > 0){
        let [word, level] = queue.shift();
        if(word === endWord){
            return level;
        }
        for(let i = 0; i < word.length; i++){
            for(let c = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); c++){
                let newWord = word.slice(0, i) + String.fromCharCode(c) + word.slice(i + 1);
                if(wordSet.has(newWord) && !visited.has(newWord)){
                    queue.push([newWord, level + 1]);
                    visited.add(newWord);
                }
            }
        }
    }
    return 0;
    
};

    