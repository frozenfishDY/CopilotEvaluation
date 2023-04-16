/**https://leetcode.com/problems/repeated-dna-sequences/ */
//The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
//For example, "ACGAATTCCG" is a DNA sequence.
//When studying DNA, it is useful to identify repeated sequences within the DNA.
//Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.


/**
 * @param {string} s
 * @return {string[]}
 */
var findRepeatedDnaSequences = function(s) {
    let result = [];
    let map = new Map();
    for(let i = 0; i < s.length - 9; i++){
        let current = s.substring(i, i + 10);
        if(map.has(current)){
            let count = map.get(current);
            if(count == 1){
                result.push(current);
            }
            map.set(current, count + 1);
        }else{
            map.set(current, 1);
        }
    }
    return result;
    
};

    