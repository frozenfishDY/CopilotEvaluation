/**https://leetcode.com/problems/to-lower-case/ */
//Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.


/**
 * @param {string} s
 * @return {string}
 */
var toLowerCase = function(s) {
    let str = "";
    for(let i = 0; i < s.length; i++){
        if(s.charCodeAt(i) >= 65 && s.charCodeAt(i) <= 90){
            str += String.fromCharCode(s.charCodeAt(i) + 32);
        }else{
            str += s[i];
        }
    }
    return str;
};

    