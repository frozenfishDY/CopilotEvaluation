/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let ans = "";
    let i = 0;
    while(i < s.length){
        let j = i;
        while(j < s.length && s[j] != " "){
            j++;
        }
        ans += reverse(s.substring(i, j));
        if(j < s.length){
            ans += " ";
        }
        i = j + 1;
    }
    return ans;
    
    
};

    