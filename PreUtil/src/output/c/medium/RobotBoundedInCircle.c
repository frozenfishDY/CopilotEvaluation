/**https://leetcode.com/problems/robot-bounded-in-circle/ */
//On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
//The north direction is the positive direction of the y-axis.
//The south direction is the negative direction of the y-axis.
//The east direction is the positive direction of the x-axis.
//The west direction is the negative direction of the x-axis.
//The robot can receive one of three instructions:
//"G": go straight 1 unit.
//"L": turn 90 degrees to the left (i.e., anti-clockwise direction).
//"R": turn 90 degrees to the right (i.e., clockwise direction).
//The robot performs the instructions given in order, and repeats them forever.
//Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.


bool isRobotBounded(char * instructions){
    int x = 0;
    int y = 0;
    int direction = 0;
    int length = strlen(instructions);
    for(int i = 0; i < length; i++){
        if(instructions[i] == 'G'){
            if(direction == 0){
                y++;
            }else if(direction == 1){
                x++;
            }else if(direction == 2){
                y--;
            }else{
                x--;
            }
        }else if(instructions[i] == 'L'){
            direction = (direction + 3) % 4;
        }else{
            direction = (direction + 1) % 4;
        }
    }
    if(x == 0 && y == 0){
        return true;
    }
    if(direction == 0){
        return false;
    }
    return true;

}

    