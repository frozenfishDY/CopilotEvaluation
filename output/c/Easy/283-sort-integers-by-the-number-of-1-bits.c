/**https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/ */
//You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.
//Return the array after sorting it.
// 
//Example 1:
//Input: arr = [0,1,2,3,4,5,6,7,8]
//Output: [0,1,2,4,8,3,5,6,7]
//Explantion: [0] is the only integer with 0 bits.
//[1,2,4,8] all have 1 bit.
//[3,5,6] have 2 bits.
//[7] has 3 bits.
//The sorted array by bits is [0,1,2,4,8,3,5,6,7]
//Example 2:
//Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
//Output: [1,2,4,8,16,32,64,128,256,512,1024]
//Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
// 
//Constraints:
//	1 <= arr.length <= 500
//	0 <= arr[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize){
int i,j;
    *returnSize=arrSize;
    int *returnArr=(int *)malloc(sizeof(int)*arrSize);
    for(i=0;i<arrSize;i++){
        int temp=0;
        int tempArr=arr[i];
        while(tempArr){
            temp+=tempArr%2;
            tempArr/=2;
        }
        returnArr[i]=temp;
    }
    for(i=0;i<arrSize;i++){
        for(j=0;j<arrSize-i-1;j++){
            if(returnArr[j]>returnArr[j+1]){
                int temp=returnArr[j];
                returnArr[j]=returnArr[j+1];
                returnArr[j+1]=temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return returnArr;
}