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
char * convertToTitle(int columnNumber){
    char *res = (char *)malloc(sizeof(char) * 8);
    int i = 0;
    while (columnNumber > 0) {
        res[i++] = (columnNumber - 1) % 26 + 'A';
        columnNumber = (columnNumber - 1) / 26;
    }
    res[i] = '\0';
    int len = strlen(res);
    for (i = 0; i < len / 2; i++) {
        char tmp = res[i];
        res[i] = res[len - i - 1];
        res[len - i - 1] = tmp;
    }
    return res;

}