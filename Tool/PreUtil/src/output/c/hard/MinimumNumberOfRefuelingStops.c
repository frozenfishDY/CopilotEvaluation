/**https://leetcode.com/problems/minimum-number-of-refueling-stops/ */
//A car travels from a starting position to a destination which is target miles east of the starting position.
//There are gas stations along the way. The gas stations are represented as an array stations where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles east of the starting position and has fueli liters of gas.
//The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it. It uses one liter of gas per one mile that it drives. When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
//Return the minimum number of refueling stops the car must make in order to reach its destination. If it cannot reach the destination, return -1.
//Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. If the car reaches the destination with 0 fuel left, it is still considered to have arrived.


int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    int* result = (int*)malloc(sizeof(int) * (stationsSize + 1));
    int* queue = (int*)malloc(sizeof(int) * stationsSize);
    int head = 0, tail = 0;
    for(int i = 0; i < stationsSize; i++){
        while(head < tail && stations[queue[tail - 1]][1] < stations[i][1]) tail--;
        queue[tail++] = i;
        if(i - head >= stationsSize) head++;
        if(i >= stationsSize - 1) result[i - stationsSize + 1] = stations[i][0];
    }
    *returnSize = stationsSize + 1;
    return result;

}

    