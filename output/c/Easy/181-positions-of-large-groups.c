/**https://leetcode.com/problems/positions-of-large-groups/ */
//In a string s of lowercase letters, these letters form consecutive groups of the same character.
//For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".
//A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].
//A group is considered large if it has 3 or more characters.
//Return the intervals of every large group sorted in increasing order by start index.
// 
//Example 1:
//Input: s = "abbxxxxzzy"
//Output: [[3,6]]
//Explanation: "xxxx" is the only large group with start index 3 and end index 6.
//Example 2:
//Input: s = "abc"
//Output: []
//Explanation: We have groups "a", "b", and "c", none of which are large groups.
//Example 3:
//Input: s = "abcdddeeeeaabbbcd"
//Output: [[3,5],[6,9],[12,14]]
//Explanation: The large groups are "ddd", "eeee", and "bbb".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s contains lowercase English letters only.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes){
 int len = strlen(s);
    int** ret = (int**)malloc(sizeof(int*) * len);
    *returnColumnSizes = (int*)malloc(sizeof(int) * len);
    *returnSize = 0;
    int i = 0;
    while(i < len){
        int j = i + 1;
        while(s[j] == s[i]){
            j++;
        }
        if(j - i >= 3){
            int* tmp = (int*)malloc(sizeof(int) * 2);
            tmp[0] = i;
            tmp[1] = j - 1;
            ret[*returnSize] = tmp;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
        i = j;
    }
    return ret;
}