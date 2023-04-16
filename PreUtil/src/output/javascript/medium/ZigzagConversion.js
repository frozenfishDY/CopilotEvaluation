/**https://leetcode.com/problems/zigzag-conversion/ */
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//string convert(string s, int numRows);


/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if(numRows == 1){
        return s;
    }
    let result = "";
    let cycle = 2 * numRows - 2;
    for(let i = 0; i < numRows; i++){
        for(let j = 0; j + i < s.length; j += cycle){
            result += s[j + i];
            if(i != 0 && i != numRows - 1 && j + cycle - i < s.length){
                result += s[j + cycle - i];
            }
        }
    }
    return result;
    
};

    