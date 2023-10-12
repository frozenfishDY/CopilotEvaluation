/**https://leetcode.com/problems/find-the-k-beauty-of-a-number/ */
//The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
//	It has a length of k.
//	It is a divisor of num.
//Given integers num and k, return the k-beauty of num.
//Note:
//	Leading zeros are allowed.
//	0 is not a divisor of any value.
//A substring is a contiguous sequence of characters in a string.
// 
//Example 1:
//Input: num = 240, k = 2
//Output: 2
//Explanation: The following are the substrings of num of length k:
//- "24" from "240": 24 is a divisor of 240.
//- "40" from "240": 40 is a divisor of 240.
//Therefore, the k-beauty is 2.
//Example 2:
//Input: num = 430043, k = 2
//Output: 2
//Explanation: The following are the substrings of num of length k:
//- "43" from "430043": 43 is a divisor of 430043.
//- "30" from "430043": 30 is not a divisor of 430043.
//- "00" from "430043": 0 is not a divisor of 430043.
//- "04" from "430043": 4 is not a divisor of 430043.
//- "43" from "430043": 43 is a divisor of 430043.
//Therefore, the k-beauty is 2.
// 
//Constraints:
//	1 <= num <= 109
//	1 <= k <= num.length (taking num as a string)
int divisorSubstrings(int num, int k){
int res = 0;
    int i = 0, j = 0, k = 0;
    char *numStr = (char*)calloc(10, sizeof(char));
    sprintf(numStr, "%d", num);
    for (; i < strlen(numStr) - k + 1; i++) {
        int tmp = 0;
        for (j = 0; j < k; j++) {
            tmp = tmp * 10 + numStr[i + j] - '0';
        }
        if (num % tmp == 0) {
            res++;
        }
    }
    return res;
}
int kthBeauty(int num, int k){
int res = 0;
    int i = 0;
    for (; i < strlen(num); i++) {
        res += divisorSubstrings(num, i);
    }
    return res;
}