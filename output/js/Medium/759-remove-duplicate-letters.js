/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.


/**
 * @param {string} s
 * @return {string}
 */
var removeDuplicateLetters = function(s) {
    let n = s.length;
    let result = [];
    let lastOccurence = new Map();
    for(let i = 0; i < n; i++){
        lastOccurence.set(s[i], i);
    }
    let visited = new Set();
    for(let i = 0; i < n; i++){
        let char = s[i];
        if(!visited.has(char)){
            while(result.length > 0 && result[result.length - 1] > char && lastOccurence.get(result[result.length - 1]) > i){
                visited.delete(result[result.length - 1]);
                result.pop();
            }
            result.push(char);
            visited.add(char);
        }
    }
    return result.join('');
    
};

    