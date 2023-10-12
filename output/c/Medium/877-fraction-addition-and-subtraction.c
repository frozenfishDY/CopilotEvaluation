/**https://leetcode.com/problems/fraction-addition-and-subtraction/ */
//Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
//The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.
// 
//Example 1:
//Input: expression = "-1/2+1/2"
//Output: "0/1"
//Example 2:
//Input: expression = "-1/2+1/2+1/3"
//Output: "1/3"
//Example 3:
//Input: expression = "1/3-1/2"
//Output: "-1/6"
// 
//Constraints:
//	The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
//	Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
//	The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
//	The number of given fractions will be in the range [1, 10].
//	The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
char * fractionAddition(char * expression){
int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(s);
    int* count = (int*)malloc(sizeof(int) * 10);
    memset(count, 0, sizeof(int) * 10);
    for (i = 0; i < len; i++) {
        switch (s[i]) {
            case 'z':
                count[0]++;
                break;
            case 'w':
                count[2]++;
                break;
            case 'u':
                count[4]++;
                break;
            case 'x':
                count[6]++;
                break;
            case 'g':
                count[8]++;
                break;
            case 's':
                count[7]++;
                break;
            case 'f':
                count[5]++;
                break;
            case 'h':
                count[3]++;
                break;
            case 'i':
                count[9]++;
                break;
            case 'o':
                count[1]++;
                break;
        }
    }
    count[7] -= count[6];
    count[5] -= count[4];
    count[3] -= count[8];
    count[9] = count[9] - count[8] - count[6] - count[5];
    count[1] = count[1] - count[0] - count[2] - count[4];
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    memset(res, 0, sizeof(char) * (len + 1));
    for (i = 0; i < 10; i++) {
        for (j = 0; j < count[i]; j++) {
            res[k++] = i + '0';
        }
    }
    res[k] = '\0';
    free(count);
    return res;
}