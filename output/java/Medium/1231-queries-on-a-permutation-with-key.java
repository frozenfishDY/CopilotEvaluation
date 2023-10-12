/**https://leetcode.com/problems/queries-on-a-permutation-with-key/ */
//Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:_x000D_
//_x000D_
//_x000D_
//	In the beginning, you have the permutation P=[1,2,3,...,m]._x000D_
//	For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i]._x000D_
//_x000D_
//_x000D_
//Return an array containing the result for the given queries._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: queries = [3,1,2,1], m = 5_x000D_
//Output: [2,1,2,1] _x000D_
//Explanation: The queries are processed as follow: _x000D_
//For i=0: queries[i]=3, P=[1,2,3,4,5], position of 3 in P is 2, then we move 3 to the beginning of P resulting in P=[3,1,2,4,5]. _x000D_
//For i=1: queries[i]=1, P=[3,1,2,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,3,2,4,5]. _x000D_
//For i=2: queries[i]=2, P=[1,3,2,4,5], position of 2 in P is 2, then we move 2 to the beginning of P resulting in P=[2,1,3,4,5]. _x000D_
//For i=3: queries[i]=1, P=[2,1,3,4,5], position of 1 in P is 1, then we move 1 to the beginning of P resulting in P=[1,2,3,4,5]. _x000D_
//Therefore, the array containing the result is [2,1,2,1].  _x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: queries = [4,1,2,2], m = 4_x000D_
//Output: [3,1,2,0]_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: queries = [7,5,5,8,3], m = 8_x000D_
//Output: [6,5,0,7,5]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	1 <= m <= 10^3_x000D_
//	1 <= queries.length <= m_x000D_
//	1 <= queries[i] <= m_x000D_
class Solution {
    public int[] processQueries(int[] queries, int m) {
        
    }
}