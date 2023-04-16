/**https://leetcode.com/problems/teemo-attacking/ */
//Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.
//You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.
//Return the total number of seconds that Ashe is poisoned.


int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int i = 0;
    int count = 0;
    while(i < timeSeriesSize - 1){
        if(timeSeries[i + 1] - timeSeries[i] >= duration){
            count += duration;
        }else{
            count += timeSeries[i + 1] - timeSeries[i];
        }
        i++;
    }
    if(timeSeriesSize > 0){
        count += duration;
    }
    return count;


}

    