/**https://leetcode.com/problems/check-if-point-is-reachable/ */
//There exists an infinitely large grid. You are currently at point (1, 1), and you need to reach the point (targetX, targetY) using a finite number of steps.
//In one step, you can move from point (x, y) to any one of the following points:
//(x, y - x)
//(x - y, y)
//(2 * x, y)
//(x, 2 * y)
//Given two integers targetX and targetY representing the X-coordinate and Y-coordinate of your final position, return true if you can reach the point from (1, 1) using some number of steps, and false otherwise.


bool isReachable(int targetX, int targetY){
    int x = 1, y = 1;
    while(x < targetX || y < targetY){
        if(x < targetX && y < targetY){
            if(targetX - x > targetY - y){
                x += y;
            }else{
                y += x;
            }
        }else if(x < targetX){
            x += y;
        }else{
            y += x;
        }
    }
    return x == targetX && y == targetY;

}

    