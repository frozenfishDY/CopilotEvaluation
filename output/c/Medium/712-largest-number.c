/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
char * largestNumber(int* nums, int numsSize){
char *res = (char *)malloc(sizeof(char) * 1000);
    char **s = (char **)malloc(sizeof(char *) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        s[i] = (char *)malloc(sizeof(char) * 10);
        sprintf(s[i], "%d", nums[i]);
    }
    qsort(s, numsSize, sizeof(char *), cmp);
    if (s[0][0] == '0') {
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    for (int i = 0; i < numsSize; i++) {
        strcat(res, s[i]);
    }
    return res;
}