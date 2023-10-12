/**https://leetcode.com/problems/rank-transform-of-an-array/ */
//Given an array of integers arr, replace each element with its rank.
//The rank represents how large the element is. The rank has the following rules:
//	Rank is an integer starting from 1.
//	The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
//	Rank should be as small as possible.
// 
//Example 1:
//Input: arr = [40,10,20,30]
//Output: [4,1,2,3]
//Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
//Example 2:
//Input: arr = [100,100,100]
//Output: [1,1,1]
//Explanation: Same elements share the same rank.
//Example 3:
//Input: arr = [37,12,28,9,100,56,80,5,12]
//Output: [5,3,4,2,8,6,7,1,3]
// 
//Constraints:
//	0 <= arr.length <= 105
//	-109 <= arr[i] <= 109
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
int i,j;
    int temp;
    for(i=0;i<arrSize;i++){
        returnNums[i]=arr[i];
    }
    for(i=0;i<arrSize-1;i++){
        for(j=0;j<arrSize-i-1;j++){
            if(returnNums[j]>returnNums[j+1]){
                temp=returnNums[j];
                returnNums[j]=returnNums[j+1];
                returnNums[j+1]=temp;
            }
        }
    }
    for(i=0,j=1;i<arrSize;i++){
        if(returnNums[i]!=returnNums[i+1]){
            returnNums[i]=j;
            j++;
        }else{
            returnNums[i]=j;
        }
    }
    *returnSize=arrSize;
    return returnNums;
}