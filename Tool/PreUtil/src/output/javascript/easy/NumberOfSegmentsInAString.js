/**https://leetcode.com/problems/number-of-segments-in-a-string/ */
//Given a string s, return the number of segments in the string.
//A segment is defined to be a contiguous sequence of non-space characters.


/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    let count = 0;
    for(let i = 0; i < s.length; i++){
        if(s[i] != " " && (i == 0 || s[i-1] == " ")){
            count++;
        }
    }
    return count;
    
};

    