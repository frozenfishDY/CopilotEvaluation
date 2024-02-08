/**https://leetcode.com/problems/gas-station/ */
//There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
//Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique


int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int start = 0;
    int end = 0;
    int sum = 0;
    while(start < gasSize){
        sum += gas[end] - cost[end];
        if(sum < 0){
            start = end + 1;
            sum = 0;
        }
        end = (end + 1) % gasSize;
        if(start == end){
            return start;
        }
    }
    return -1;

}

    