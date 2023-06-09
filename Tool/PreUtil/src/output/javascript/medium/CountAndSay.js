/**https://leetcode.com/problems/count-and-say/ */
//The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//countAndSay(1) = "1"
//countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
//To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
//For example, the saying and conversion for digit string "3322251":
// 


/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    let result = "1";
    for(let i = 1; i < n; i++){
        let current = result[0];
        let count = 1;
        let temp = "";
        for(let j = 1; j < result.length; j++){
            if(result[j] == current){
                count++;
            }else{
                temp += count + current;
                current = result[j];
                count = 1;
            }
        }
        temp += count + current;
        result = temp;
    }
    return result;
    
};

    