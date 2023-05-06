/**https://leetcode.com/problems/maximum-building-height/ */
//You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
//However, there are city restrictions on the heights of the new buildings:
//The height of each building must be a non-negative integer.
//The height of the first building must be 0.
//The height difference between any two adjacent buildings cannot exceed 1.
//Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
//It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
//Return the maximum possible height of the tallest building.


int maxBuilding(int n, int** restrictions, int restrictionsSize, int* restrictionsColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr13[i] = 0;
    }
    int* arr14 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr14[i] = 0;
    }
    int* arr15

}

    