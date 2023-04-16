/**https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ */
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle == ""){
        return 0;
    }
    if(haystack.length < needle.length){
        return -1;
    }
    for(let i = 0; i < haystack.length - needle.length + 1; i++){
        if(haystack[i] == needle[0]){
            let j = 1;
            while(j < needle.length && haystack[i + j] == needle[j]){
                j++;
            }
            if(j == needle.length){
                return i;
            }
        }
    }
    return -1;
    
};

    