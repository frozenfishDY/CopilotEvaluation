/**https://leetcode.com/problems/find-unique-binary-string/ */
//Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
// 
//Example 1:
//Input: nums = ["01","10"]
//Output: "11"
//Explanation: "11" does not appear in nums. "00" would also be correct.
//Example 2:
//Input: nums = ["00","01"]
//Output: "11"
//Explanation: "11" does not appear in nums. "10" would also be correct.
//Example 3:
//Input: nums = ["111","011","001"]
//Output: "101"
//Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 16
//	nums[i].length == n
//	nums[i] is either '0' or '1'.
//	All the strings of nums are unique.
char * findDifferentBinaryString(char ** nums, int numsSize){
int i,j;
    int len=strlen(nums[0]);
    int nums_len=pow(2,len);
    char *res=malloc(sizeof(char)*(len+1));
    char **arr=malloc(sizeof(char*)*nums_len);
    for(i=0;i<nums_len;i++){
        arr[i]=malloc(sizeof(char)*(len+1));
        memset(arr[i],0,len+1);
    }
    for(i=0;i<numsSize;i++){
        strcpy(arr[atoi(nums[i])],nums[i]);
    }
    for(i=0;i<nums_len;i++){
        if(arr[i][0]==0){
            sprintf(res,"%d",i);
            break;
        }
    }
    for(i=0;i<nums_len;i++){
        free(arr[i]);
    }
    free(arr);
    return res;
}