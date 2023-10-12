/**https://leetcode.com/problems/count-ways-to-build-rooms-in-an-ant-colony/ */
//You are an ant tasked with adding n new rooms numbered 0 to n-1 to your colony. You are given the expansion plan as a 0-indexed integer array of length n, prevRoom, where prevRoom[i] indicates that you must build room prevRoom[i] before building room i, and these two rooms must be connected directly. Room 0 is already built, so prevRoom[0] = -1. The expansion plan is given such that once all the rooms are built, every room will be reachable from room 0._x000D_
//_x000D_
//You can only build one room at a time, and you can travel freely between rooms you have already built only if they are connected. You can choose to build any room as long as its previous room is already built._x000D_
//_x000D_
//Return the number of different orders you can build all the rooms in. Since the answer may be large, return it modulo 109 + 7._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: prevRoom = [-1,0,1]_x000D_
//Output: 1_x000D_
//Explanation: There is only one way to build the additional rooms: 0 → 1 → 2_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: prevRoom = [-1,0,0,1,2]_x000D_
//Output: 6_x000D_
//Explanation:_x000D_
//The 6 ways are:_x000D_
//0 → 1 → 3 → 2 → 4_x000D_
//0 → 2 → 4 → 1 → 3_x000D_
//0 → 1 → 2 → 3 → 4_x000D_
//0 → 1 → 2 → 4 → 3_x000D_
//0 → 2 → 1 → 3 → 4_x000D_
//0 → 2 → 1 → 4 → 3_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	n == prevRoom.length_x000D_
//	2 <= n <= 105_x000D_
//	prevRoom[0] == -1_x000D_
//	0 <= prevRoom[i] < n for all 1 <= i < n_x000D_
//	Every room is reachable from room 0 once all the rooms are built._x000D_
class Solution {_x000D_
    public int waysToBuildRooms(int[] prevRoom) {_x000D_
        _x000D_
    }_x000D_
}