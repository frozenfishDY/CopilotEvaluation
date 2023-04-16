/**https://leetcode.com/problems/ambiguous-coordinates/ */
//We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)". Then, we removed all commas, decimal points, and spaces and ended up with the string s.
//For example, "(1, 3)" becomes s = "(13)" and "(2, 0.5)" becomes s = "(205)".
//Return a list of strings representing all possibilities for what our original coordinates could have been.
//Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with fewer digits. Also, a decimal point within a number never occurs without at least one digit occurring before it, so we never started with numbers like ".1".
//The final answer list can be returned in any order. All coordinates in the final answer have exactly one space between them (occurring after the comma.)


/**
 * @param {string} s
 * @return {string[]}
 */
var ambiguousCoordinates = function(s) {
    let n = s.length;
    let result = [];
    for(let i = 1; i < n - 1; i++){
        let left = generate(s.substring(1, i + 1));
        let right = generate(s.substring(i + 1, n - 1));
        for(let j = 0; j < left.length; j++){
            for(let k = 0; k < right.length; k++){
                result.push('(' + left[j] + ', ' + right[k] + ')');
            }
        }
    }
    return result;
    
};

    