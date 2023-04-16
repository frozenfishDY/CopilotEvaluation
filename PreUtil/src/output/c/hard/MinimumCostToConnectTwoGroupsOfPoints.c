/**https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/ */
//You are given two groups of points where the first group has size1 points, the second group has size2 points, and size1 >= size2.
//The cost of the connection between any two points are given in an size1 x size2 matrix where cost[i][j] is the cost of connecting point i of the first group and point j of the second group. The groups are connected if each point in both groups is connected to one or more points in the opposite group. In other words, each point in the first group must be connected to at least one point in the second group, and each point in the second group must be connected to at least one point in the first group.
//Return the minimum cost it takes to connect the two groups.


int connectTwoGroups(int** cost, int costSize, int* costColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*costSize);
    for(i=0;i<costSize;i++){
        arr13[i] = 0;
    }

}

    