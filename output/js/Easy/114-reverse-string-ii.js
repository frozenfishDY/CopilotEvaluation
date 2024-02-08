/**https://leetcode.com/problems/reverse-string-ii/ */
//Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
//If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.


/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function(s, k) {
    let ans = "";
    let i = 0;
    while(i < s.length){
        if(i + k < s.length){
            ans += reverse(s.substring(i, i + k));
        }else{
            ans += reverse(s.substring(i));
        }
        i += k;
        if(i + k < s.length){
            ans += s.substring(i, i + k);
        }else{
            ans += s.substring(i);
        }
        i += k;
    }
    return ans;
    
    
};

    