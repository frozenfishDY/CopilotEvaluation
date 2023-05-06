/**https://leetcode.com/problems/word-ladder-ii/ */
//A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
//Every adjacent pair of words differs by a single letter.
//Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
//sk == endWord
//Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].


/**
 * @param {string} beginWord
 * @param {string} endWord
 * @param {string[]} wordList
 * @return {string[][]}
 */
var findLadders = function(beginWord, endWord, wordList) {
    let wordSet = new Set(wordList);
    if(!wordSet.has(endWord)){
        return [];
    }
    let ans = [];
    let visited = new Set();
    let queue = [[beginWord]];
    let found = false;
    while(queue.length > 0){
        let size = queue.length;
        let nextVisited = new Set();
        for(let i = 0; i < size; i++){
            let path = queue.shift();
            let word = path[path.length - 1];
            if(word === endWord){
                ans.push(path);
                found = true;
            }
            if(found){
                continue;
            }
            for(let j = 0; j < word.length; j++){
                for(let c = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); c++){
                    let newWord = word.slice(0, j) + String.fromCharCode(c) + word.slice(j + 1);
                    if(wordSet.has(newWord) && !visited.has(newWord)){
                        queue.push([...path, newWord]);
                        nextVisited.add(newWord);
                    }
                }
            }
        }
        visited = nextVisited;
    }
    return ans;
    
};

    