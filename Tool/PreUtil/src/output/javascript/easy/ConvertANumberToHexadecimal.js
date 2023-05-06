/**https://leetcode.com/problems/convert-a-number-to-hexadecimal/ */
//Given an integer num, return a string representing its hexadecimal representation. For negative integers, two��s complement method is used.
//All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
//Note: You are not allowed to use any built-in library method to directly solve this problem.


/**
 * @param {number} num
 * @return {string}
 */
var toHex = function(num) {
    if(num == 0){
        return "0";
    }
    let map = {
        0: "0",
        1: "1",
        2: "2",
        3: "3",
        4: "4",
        5: "5",
        6: "6",
        7: "7",
        8: "8",
        9: "9",
        10: "a",
        11: "b",
        12: "c",
        13: "d",
        14: "e",
        15: "f"
    };
    let result = "";
    while(num != 0){
        let remainder = num%16;
        result = map[remainder] + result;
        num = Math.floor(num/16);
    }
    return result;
    
};

    