/**https://leetcode.com/problems/minimum-absolute-difference/ */
//Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
//Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
//	a, b are from arr
//	a < b
//	b - a equals to the minimum absolute difference of any two elements in arr
// 
//Example 1:
//Input: arr = [4,2,1,3]
//Output: [[1,2],[2,3],[3,4]]
//Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
//Example 2:
//Input: arr = [1,3,6,10,15]
//Output: [[1,3]]
//Example 3:
//Input: arr = [3,8,-10,23,19,-4,-14,27]
//Output: [[-14,-10],[19,23],[23,27]]
// 
//Constraints:
//	2 <= arr.length <= 105
//	-106 <= arr[i] <= 106
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
int i,j;
    for(i=0;i<arrSize;i++){
        returnNums[i]=arr[i];
    }
    for(i=0;i<arrSize-1;i++){
        for(j=0;j<arrSize-i-1;j++){
            if(returnNums[j]>returnNums[j+1]){
                int temp=returnNums[j];
                returnNums[j]=returnNums[j+1];
                returnNums[j+1]=temp;
            }
        }
    }
    int min=returnNums[1]-returnNums[0];
    for(i=1;i<arrSize-1;i++){
        if(returnNums[i+1]-returnNums[i]<min){
            min=returnNums[i+1]-returnNums[i];
        }
    }
    int count=0;
    for(i=0;i<arrSize-1;i++){
        if(returnNums[i+1]-returnNums[i]==min){
            count++;
        }
    }
    *returnSize=count;
    int **returnNums2 = malloc(sizeof(int*)*count);
    *returnColumnSizes = malloc(sizeof(int)*count);
    int k=0;
    for(i=0;i<arrSize-1;i++){
        if(returnNums[i+1]-returnNums[i]==min){
            (*returnColumnSizes)[k]=2;
            returnNums2[k]=malloc(sizeof(int)*2);
            returnNums2[k][0]=returnNums[i];
            returnNums2[k][1]=returnNums[i+1];
            k++;
        }
    }
    return returnNums2;
}