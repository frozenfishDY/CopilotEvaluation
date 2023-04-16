/**https://leetcode.com/problems/walking-robot-simulation/ */
//A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
//-2: Turn left 90 degrees.
//-1: Turn right 90 degrees.
//1 <= k <= 9: Move forward k units, one unit at a time.
//Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
//Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).
//Note:
//North means +Y direction.
//East means +X direction.
//South means -Y direction.
//West means -X direction.


int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize){
    int x = 0;
    int y = 0;
    int direction = 0;
    int result = 0;
    int hash[10001][10001];
    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < 10001; j++){
            hash[i][j] = 0;
        }
    }
    for(int i = 0; i < obstaclesSize; i++){
        hash[obstacles[i][0] + 30000][obstacles[i][1] + 30000] = 1;
    }
    for(int i = 0; i < commandsSize; i++){
        if(commands[i] == -2){
            direction = (direction + 3) % 4;
        }else if(commands[i] == -1){
            direction = (direction + 1) % 4;
        }else{
            for(int j = 0; j < commands[i]; j++){
                if(direction == 0){
                    if(hash[x + 30000][y + 30001] == 1){
                        break;
                    }
                    y++;
                }else if(direction == 1){
                    if(hash[x + 30001][y + 30000] == 1){
                        break;
                    }
                    x++;
                }else if(direction == 2){
                    if(hash[x + 30000][y + 29999] == 1){
                        break;
                    }
                    y--;
                }else{
                    if(hash[x + 29999][y + 30000] == 1){
                        break;
                    }
                    x--;
                }
            }
        }
        result = result > x * x + y * y ? result : x * x + y * y;
    }
    return result;

}

    