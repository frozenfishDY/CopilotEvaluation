/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".


/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var repeatedStringMatch = function(a, b) {
    let result = 1;
    let temp = a;
    while(temp.length < b.length){
        temp += a;
        result++;
    }
    if(temp.includes(b)){
        return result;
    }
    temp += a;
    result++;
    if(temp.includes(b)){
        return result;
    }
    return -1;
    
    
};

    