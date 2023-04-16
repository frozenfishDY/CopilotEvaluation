/**https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/ */
//There is an n x n grid, with the top-left cell at (0, 0) and the bottom-right cell at (n - 1, n - 1). You are given the integer n and an integer array startPos where startPos = [startrow, startcol] indicates that a robot is initially at cell (startrow, startcol).
//You are also given a 0-indexed string s of length m where s[i] is the ith instruction for the robot: 'L' (move left), 'R' (move right), 'U' (move up), and 'D' (move down).
//The robot can begin executing from any ith instruction in s. It executes the instructions one by one towards the end of s but it stops if either of these conditions is met:
//The next instruction will move the robot off the grid.
//There are no more instructions left to execute.
//Return an array answer of length m where answer[i] is the number of instructions the robot can execute if the robot begins executing from the ith instruction in s.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* executeInstructions(int n, int* startPos, int startPosSize, char * s, int* returnSize){
    int* arr = malloc(strlen(s) * sizeof(int));
    int i, j, k, l;
    int count = 0;
    int x = startPos[0];
    int y = startPos[1];
    for(i = 0; i < strlen(s); i++){
        if(s[i] == 'L'){
            y--;
        }
        else if(s[i] == 'R'){
            y++;
        }
        else if(s[i] == 'U'){
            x--;
        }
        else if(s[i] == 'D'){
            x++;
        }
        if(x < 0 || x >= n || y < 0 || y >= n){
            break;
        }
        count++;
    }
    for(i = 0; i < strlen(s); i++){
        arr[i] = count;
    }
    *returnSize = strlen(s);
    return arr;


}

    