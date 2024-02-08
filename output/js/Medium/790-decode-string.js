/**https://leetcode.com/problems/decode-string/ */
//Given an encoded string, return its decoded string.
//The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//The test cases are generated so that the length of the output will never exceed 105.


/**
 * @param {string} s
 * @return {string}
 */
var decodeString = function(s) {
    let n = s.length;
    let stack = [];
    let num = 0;
    let result = "";
    for(let i = 0; i < n; i++){
        if(!isNaN(s[i])){
            num = num * 10 + parseInt(s[i]);
        }else if(s[i] == "["){
            stack.push(result);
            stack.push(num);
            result = "";
            num = 0;
        }else if(s[i] == "]"){
            let count = stack.pop();
            let prev = stack.pop();
            result = prev + result.repeat(count);
        }else{
            result += s[i];
        }
    }
    return result;
    
};

    