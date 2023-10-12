/**https://leetcode.com/problems/create-sorted-array-through-instructions/ */
//Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:_x000D_
//_x000D_
//_x000D_
//	The number of elements currently in nums that are strictly less than instructions[i]._x000D_
//	The number of elements currently in nums that are strictly greater than instructions[i]._x000D_
//_x000D_
//_x000D_
//For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5]._x000D_
//_x000D_
//Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7_x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: instructions = [1,5,6,2]_x000D_
//Output: 1_x000D_
//Explanation: Begin with nums = []._x000D_
//Insert 1 with cost min(0, 0) = 0, now nums = [1]._x000D_
//Insert 5 with cost min(1, 0) = 0, now nums = [1,5]._x000D_
//Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6]._x000D_
//Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6]._x000D_
//The total cost is 0 + 0 + 0 + 1 = 1._x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: instructions = [1,2,3,6,5,4]_x000D_
//Output: 3_x000D_
//Explanation: Begin with nums = []._x000D_
//Insert 1 with cost min(0, 0) = 0, now nums = [1]._x000D_
//Insert 2 with cost min(1, 0) = 0, now nums = [1,2]._x000D_
//Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3]._x000D_
//Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6]._x000D_
//Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6]._x000D_
//Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6]._x000D_
//The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: instructions = [1,3,3,3,2,4,2,1,2]_x000D_
//Output: 4_x000D_
//Explanation: Begin with nums = []._x000D_
//Insert 1 with cost min(0, 0) = 0, now nums = [1]._x000D_
//Insert 3 with cost min(1, 0) = 0, now nums = [1,3]._x000D_
//Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3]._x000D_
//Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3]._x000D_
//Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3]._x000D_
//Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4]._x000D_
//​​​​​​​Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4]._x000D_
//​​​​​​​Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4]._x000D_
//​​​​​​​Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4]._x000D_
//The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= instructions.length <= 105_x000D_
//	1 <= instructions[i] <= 105_x000D_


int createSortedArray(int* instructions, int instructionsSize){
int i, j, k, l, m, n;
    int ans = 0;
    int mod = 1000000007;
    int max = 0;
    for (i = 0; i < instructionsSize; i++) {
        max = max > instructions[i] ? max : instructions[i];
    }
    int* bit = (int*)malloc(sizeof(int) * (max + 1));
    memset(bit, 0, sizeof(int) * (max + 1));
    for (i = 0; i < instructionsSize; i++) {
        int left = 0;
        int right = 0;
        for (j = instructions[i]; j > 0; j -= (j & (-j))) {
            left += bit[j];
        }
        for (j = instructions[i] + 1; j <= max; j += (j & (-j))) {
            right += bit[j];
        }
        ans = (ans + (left < right ? left : right)) % mod;
        for (j = instructions[i]; j <= max; j += (j & (-j))) {
            bit[j]++;
        }
    }
    return ans;
}