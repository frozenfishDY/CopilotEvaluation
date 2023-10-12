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
class Solution {
    public String convertToTitle(int columnNumber) {
        String result = "";
        while (columnNumber > 0) {
            int remainder = columnNumber % 26;
            if (remainder == 0) {
                result = "Z" + result;
                columnNumber = columnNumber / 26 - 1;
            } else {
                result = (char) (remainder + 64) + result;
                columnNumber = columnNumber / 26;
            }
        }
        return result;
        
    }
}