/**https://leetcode.com/problems/find-in-mountain-array/ */
//(This problem is an interactive problem.)
//You may recall that an array arr is a mountain array if and only if:
//arr.length >= 3
//There exists some i with 0 < i < arr.length - 1 such that:
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.
//You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
//MountainArray.get(k) returns the element of the array at index k (0-indexed).
//MountainArray.length() returns the length of the array.
//Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.


/**
 * *********************************************************************
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * int get(MountainArray *, int index);
 * int length(MountainArray *);
 */

int findInMountainArray(int target, MountainArray* mountainArr) {
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr[i] = 0;
    }
    int count = 0;
    int temp = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr[count] = temp;
            temp = 0;
            count++;
        }
        else{
            temp = temp*10 + (s[i]-'0');
        }
    }
    arr[count] = temp;
    count++;
    int* arr2 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr2[i] = 0;
    }
    int count2 = 0;
    int temp2 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr2[count2] = temp2;
            temp2 = 0;
            count2++;
        }
        else{
            temp2 = temp2*10 + (s[i]-'0');
        }
    }
    arr2[count2] = temp2;
    count2++;
    int* arr3 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr3[i] = 0;
    }
    int count3 = 0;
    int temp3 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr3[count3] = temp3;
            temp3 = 0;
            count3++;
        }
        else{
            temp3 = temp3*10 + (s[i]-'0');
        }
    }
    arr3[count3] = temp3;
    count3++;
    int* arr4 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr4[i] = 0;
    }
    int count4 = 0;
    int temp4 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr4[count4] = temp4;
            temp4 = 0;
            count4++;
        }
        else{
            temp4 = temp4*10 + (s[i]-'0
	
}

    