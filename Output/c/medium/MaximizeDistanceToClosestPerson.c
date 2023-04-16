/**https://leetcode.com/problems/maximize-distance-to-closest-person/ */
//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//There is at least one empty seat, and at least one person sitting.
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//Return that maximum distance to the closest person.


int maxDistToClosest(int* seats, int seatsSize){
    int* hash = (int*)malloc(sizeof(int) * seatsSize);
    int count = 0;
    int result = 0;
    for(int i = 0; i < seatsSize; i++){
        if(seats[i] == 1){
            count = 0;
        }else{
            count++;
            hash[i] = count;
        }
    }
    count = 0;
    for(int i = seatsSize - 1; i >= 0; i--){
        if(seats[i] == 1){
            count = 0;
        }else{
            count++;
            if(hash[i] > count){
                hash[i] = count;
            }
            result = result > hash[i] ? result : hash[i];
        }
    }
    return result;

}

    