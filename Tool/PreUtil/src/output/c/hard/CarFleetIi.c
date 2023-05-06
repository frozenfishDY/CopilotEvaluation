/**https://leetcode.com/problems/car-fleet-ii/ */
//There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:
//positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
//speedi is the initial speed of the ith car in meters per second.
//For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.
//Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* getCollisionTimes(int** cars, int carsSize, int* carsColSize, int* returnSize){
    int i,j,k;
    double* arr = (double*)malloc(sizeof(double)*carsSize);
    for(i=0;i<carsSize;i++){
        arr[i] = 0;
    }
    for(i=1;i<carsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    double sum = 0;
    for(i=0;i<carsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return arr;

}

    