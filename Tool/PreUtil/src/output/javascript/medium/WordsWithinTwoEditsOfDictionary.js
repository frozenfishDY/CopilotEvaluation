/**https://leetcode.com/problems/words-within-two-edits-of-dictionary/ */
//You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
//In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
//Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.


/**
 * @param {string[]} queries
 * @param {string[]} dictionary
 * @return {string[]}
 */
var twoEditWords = function(queries, dictionary) {
    let set = new Set(dictionary);
    let result = [];
    for (let i = 0; i < queries.length; i++) {
        let query = queries[i];
        if (set.has(query)) {
            result.push(query);
        } else {
            if (oneEdit(query, set)) {
                result.push(query);
            }
        }
    }
    return result;
    
    
    
};

    