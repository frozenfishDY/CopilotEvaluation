/**https://leetcode.com/problems/maximum-students-taking-exam/ */
//Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
//Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..
//Students must be placed in seats in good condition.


int maxStudents(char** seats, int seatsSize, int* seatsColSize){
    int i,j,k;
    int* arr2 = (int*)malloc(sizeof(int)*seatsSize);
    for(i=0;i<seatsSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<seatsSize;i++){
        for(j=i+1;j<seatsSize;j++){
            if(seats[j][0]==seats[i][0]){
                arr2[i]++;
            }
            else{
                break;
            }
        }
        for(j=i-1;j>=0;j--){
            if(seats[j][0]==seats[i][0]){
                arr2[i]++;
            }
            else{
                break;
            }
        }
    }
    int max = 0;
    for(i=0;i<seatsSize;i++){
        if(arr2[i]>max){
            max = arr2[i];
        }
    }
    return max;

}

    