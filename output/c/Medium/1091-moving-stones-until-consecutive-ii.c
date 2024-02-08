/**https://leetcode.com/problems/moving-stones-until-consecutive-ii/ */
//There are some stones in different positions on the X-axis. You are given an integer array stones, the positions of the stones.
//Call a stone an endpoint stone if it has the smallest or largest position. In one move, you pick up an endpoint stone and move it to an unoccupied position so that it is no longer an endpoint stone.
//In particular, if the stones are at say, stones = [1,2,5], you cannot move the endpoint stone at position 5, since moving it to any position (such as 0, or 3) will still keep that stone as an endpoint stone.
//The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
//Return an integer array answer of length 2 where:
//answer[0] is the minimum number of moves you can play, and
//answer[1] is the maximum number of moves you can play.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStonesII(int* stones, int stonesSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 2);
    int min = 0;
    int max = 0;
    int i = 0;
    int j = 0;
    int temp = 0;
    int count = 0;
    int maxCount = 0;
    int minCount = 0;
    int minCount2 = 0;
    int minCount3 = 0;
    int minCount4 = 0;
    int minCount5 = 0;
    int minCount6 = 0;
    int minCount7 = 0;
    int minCount8 = 0;
    int minCount9 = 0;
    int minCount10 = 0;
    int minCount11 = 0;
    int minCount12 = 0;
    int minCount13 = 0;
    int minCount14 = 0;
    int minCount15 = 0;
    int minCount16 = 0;
    int minCount17 = 0;
    int minCount18 = 0;
    int minCount19 = 0;
    int minCount20 = 0;
    int minCount21 = 0;
    int minCount22 = 0;
    int minCount23 = 0;
    int minCount24 = 0;
    int minCount25 = 0;
    int minCount26 = 0;
    int minCount27 = 0;
    int minCount28 = 0;
    int minCount29 = 0;
    int minCount30 = 0;
    int minCount31 = 0;
    int minCount32 = 0;
    int minCount33 = 0;
    int minCount34 = 0;
    int minCount35 = 0;
    int minCount36 = 0;
    int minCount37 = 0;
    int minCount38 = 0;
    int minCount39 = 0;
    int minCount40 = 0;
    int minCount41 = 0;
    int minCount42 = 0;
    int minCount43 = 0;
    int minCount44 = 0;
    int minCount45 = 0;
    int minCount46 = 0;
    int minCount47 = 0;
    int minCount48 = 0;
    

}

    