/**https://leetcode.com/problems/count-vowel-strings-in-ranges/ */
//You are given a 0-indexed array of strings words and a 2D array of integers queries.
//Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
//Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
//Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.


/**
 * @param {string[]} words
 * @param {number[][]} queries
 * @return {number[]}
 */
var vowelStrings = function(words, queries) {
    let result = [];
    for(let i = 0; i < queries.length; i++){
        let count = 0;
        for(let j = queries[i][0]; j <= queries[i][1]; j++){
            if(words[j][0] == 'a' || words[j][0] == 'e' || words[j][0] == 'i' || words[j][0] == 'o' || words[j][0] == 'u'){
                if(words[j][words[j].length - 1] == 'a' || words[j][words[j].length - 1] == 'e' || words[j][words[j].length - 1] == 'i' || words[j][words[j].length - 1] == 'o' || words[j][words[j].length - 1] == 'u'){
                    count++;
                }
            }
        }
        result.push(count);
    }
    return result;
    
};

    