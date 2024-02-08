/**https://leetcode.com/problems/moving-stones-until-consecutive/ */
//There are three stones in different positions on the X-axis. You are given three integers a, b, and c, the positions of the stones.
//In one move, you pick up a stone at an endpoint (i.e., either the lowest or highest position stone), and move it to an unoccupied position between those endpoints. Formally, let's say the stones are currently at positions x, y, and z with x < y < z. You pick up the stone at either position x or position z, and move that stone to an integer position k, with x < k < z and k != y.
//The game ends when you cannot make any more moves (i.e., the stones are in three consecutive positions).
//Return an integer array answer of length 2 where:
//answer[0] is the minimum number of moves you can play, and
//answer[1] is the maximum number of moves you can play.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * 2);
    int min = 0;
    int max = 0;
    int temp = 0;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(a > c){
        temp = a;
        a = c;
        c = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
    if(b - a == 1 && c - b == 1){
        min = 0;
    }
    else if(b - a == 1 || c - b == 1 || b - a == 2 || c - b == 2){
        min = 1;
    }
    else{
        min = 2;
    }
    max = c - a - 2;
    result[0] = min;
    result[1] = max;
    *returnSize = 2;
    return result;

}

    