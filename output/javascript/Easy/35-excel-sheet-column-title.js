/**https://leetcode.com/problems/excel-sheet-column-title/ */
//Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//For example:
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28 
//...
// 
//Example 1:
//Input: columnNumber = 1
//Output: "A"
//Example 2:
//Input: columnNumber = 28
//Output: "AB"
//Example 3:
//Input: columnNumber = 701
//Output: "ZY"
// 
//Constraints:
//	1 <= columnNumber <= 231 - 1
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function(columnNumber) {
    let result = "";
    while(columnNumber > 0){
        let remainder = columnNumber % 26;
        if(remainder == 0){
            result = "Z" + result;
            columnNumber = Math.floor(columnNumber / 26) - 1;
        }else{
            result = String.fromCharCode(remainder + 64) + result;
            columnNumber = Math.floor(columnNumber / 26);
        }
    }
    return result;
    
};