/**https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ */
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// 
//Example 1:
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
//Example 2:
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
// 
//Constraints:
//	1 <= haystack.length, needle.length <= 104
//	haystack and needle consist of only lowercase English characters.
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) { 
    if(needle.length == 0) return 0;
    if(haystack.length == 0) return -1;
    let i = 0;
    let j = 0;
    let index = -1;
    while(i < haystack.length && j < needle.length){
        if(haystack[i] == needle[j]){
            if(index == -1) index = i;
            j++;
        }else{
            if(index != -1){
                i = index;
                index = -1;
            }
            j = 0;
        }
        i++;
    }
    if(j == needle.length) return index;
    return -1;
  
};