/**https://leetcode.com/problems/building-boxes/ */
//You have a cubic storeroom where the width, length, and height of the room are all equal to n units. You are asked to place n boxes in this room where each box is a cube of unit side length. There are however some rules to placing the boxes:
//You can place the boxes anywhere on the floor.
//If box x is placed on top of the box y, then each side of the four vertical sides of the box y must either be adjacent to another box or to a wall.
//Given an integer n, return the minimum possible number of boxes touching the floor.


int minimumBoxes(int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] < arr[j] + 1) ? arr[i] : arr[j] + 1;
        }
    }
    int max = 0;
    for(i=0;i<n;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;

}

    