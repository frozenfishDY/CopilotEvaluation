/**https://leetcode.com/problems/reconstruct-original-digits-from-english/ */
//Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
// 
//Example 1:
//Input: s = "owoztneoer"
//Output: "012"
//Example 2:
//Input: s = "fviefuro"
//Output: "45"
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//	s is guaranteed to be valid.
char * originalDigits(char * s){
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
            res[k++] = (char)(i + '0');
        }
    }
    return res;
}