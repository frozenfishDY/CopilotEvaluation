/**https://leetcode.com/problems/evaluate-division/ */
//You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
//You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
//Return the answers to all queries. If a single answer cannot be determined, return -1.0.
//Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    double* result = (double*)malloc(sizeof(double) * queriesSize);
    *returnSize = queriesSize;
    for(int i = 0; i < queriesSize; i++){
        result[i] = -1.0;
    }
    for(int i = 0; i < queriesSize; i++){
        if(strcmp(queries[i][0], queries[i][1]) == 0){
            result[i] = 1.0;
        }
    }
    for(int i = 0; i < equationsSize; i++){
        for(int j = 0; j < queriesSize; j++){
            if(strcmp(equations[i][0], queries[j][0]) == 0 && strcmp(equations[i][1], queries[j][1]) == 0){
                result[j] = values[i];
            }
            else if(strcmp(equations[i][0], queries[j][1]) == 0 && strcmp(equations[i][1], queries[j][0]) == 0){
                result[j] = 1.0 / values[i];
            }
        }
    }
    for(int i = 0; i < equationsSize; i++){
        for(int j = 0; j < queriesSize; j++){
            if(strcmp(equations[i][0], queries[j][0]) == 0){
                for(int k = 0; k < equationsSize; k++){
                    if(strcmp(equations[i][1], equations[k][0]) == 0 && strcmp(equations[k][1], queries[j][1]) == 0){
                        result[j] = values[i] * values[k];
                    }
                    else if(strcmp(equations[i][1], equations[k][1]) == 0 && strcmp(equations[k][0], queries[j][1]) == 0){
                        result[j] = values[i] / values[k];
                    }
                }
            }
            else if(strcmp(equations[i][0], queries[j][1]) == 0){
                for(int k = 0; k < equationsSize; k++){
                    if(strcmp(equations[i][1], equations[k][0]) == 0 && strcmp(equations[k][1], queries[j][0]) == 0){
                        result[j] = 1.0 / values[i] / values[k];
                    }
                    else if(strcmp(equations[i][1], equations[k][1]) == 0 && strcmp(equations[k][0], queries[j][0]) == 0){
                        result[j] = 1.0 / values[i] * values[k];
                    }  

                    

}

    