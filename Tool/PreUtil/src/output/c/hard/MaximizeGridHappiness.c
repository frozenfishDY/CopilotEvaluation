/**https://leetcode.com/problems/maximize-grid-happiness/ */
//You are given four integers, m, n, introvertsCount, and extrovertsCount. You have an m x n grid, and there are two types of people: introverts and extroverts. There are introvertsCount introverts and extrovertsCount extroverts.
//You should decide how many people you want to live in the grid and assign each of them one grid cell. Note that you do not have to have all the people living in the grid.
//The happiness of each person is calculated as follows:
//Introverts start with 120 happiness and lose 30 happiness for each neighbor (introvert or extrovert).
//Extroverts start with 40 happiness and gain 20 happiness for each neighbor (introvert or extrovert).
//Neighbors live in the directly adjacent cells north, east, south, and west of a person's cell.
//The grid happiness is the sum of each person's happiness. Return the maximum possible grid happiness.


int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*m);
    for(i=0;i<m;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<m;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[m-1];

}

    