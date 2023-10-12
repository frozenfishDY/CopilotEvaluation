/**https://leetcode.com/problems/thousand-separator/ */
//Given an integer n, add a dot (".") as the thousands separator and return it in string format.
// 
//Example 1:
//Input: n = 987
//Output: "987"
//Example 2:
//Input: n = 1234
//Output: "1.234"
// 
//Constraints:
//	0 <= n <= 231 - 1
char * thousandSeparator(int n){
int i, j = 0, k = 0, l = 0, m = 0;
    char *str = (char*)malloc(sizeof(char) * 10);
    if(n == 0){
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    while(n != 0){
        str[k++] = n % 10 + '0';
        n /= 10;
        j++;
        if(j % 3 == 0){
            str[k++] = '.';
            l++;
        }
    }
    str[k] = '\0';
    if(str[k - 1] == '.')
        str[k - 1] = '\0';
    for(i = 0; i < k / 2; i++){
        m = str[i];
        str[i] = str[k - i - 1];
        str[k - i - 1] = m;
    }
    return str;
}