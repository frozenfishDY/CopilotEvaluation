/**https://leetcode.com/problems/paint-house-iii/ */
//There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.
//A neighborhood is a maximal group of continuous houses that are painted with the same color.
//For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].
//Given an array houses, an m x n matrix cost and an integer target where:
//houses[i]: is the color of the house i, and 0 if the house is not painted yet.
//cost[i][j]: is the cost of paint the house i with the color j + 1.
//Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.


int minCost(int* houses, int housesSize, int** cost, int costSize, int* costColSize, int m, int n, int target){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*target);
    for(i=0;i<target;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*target);
    for(i=0;i<target;i++){
        arr2[i] = 0;
    }
    for(i=0;i<target;i++){
        for(j=0;j<costSize;j++){
            if(i+1==cost[j]){
                arr[i] = j+1;
            }
        }
    }
    for(i=0;i<target;i++){
        for(j=0;j<costSize;j++){
            if(i+1>cost[j]){
                if(arr[i]<arr[i-cost[j]]+j+1){
                    arr[i] = arr[i-cost[j]]+j+1;
                }
            }
        }
    }
    if(arr[target-1]==0){
        return "0";
    }
    char* str = (char*)malloc(sizeof(char)*arr[target-1]);
    for(i=0;i<arr[target-1];i++){
        str[i] = '0';
    }
    int num = target;
    for(i=arr[target-1]-1;i>=0;i--){
        for(j=costSize-1;j>=0;j--){
            if(num>=cost[j]){
                if(arr[num-1]==arr[num-cost[j]-1]+j+1){
                    str[i] = j+1+'0';
                    num = num-cost[j];
                    break;
                }
            }
        }
    }
    return str;

}

    