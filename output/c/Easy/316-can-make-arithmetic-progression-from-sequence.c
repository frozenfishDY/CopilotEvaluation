/**https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/ */
//A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
//Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.
// 
//Example 1:
//Input: arr = [3,5,1]
//Output: true
//Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
//Example 2:
//Input: arr = [1,2,4]
//Output: false
//Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
// 
//Constraints:
//	2 <= arr.length <= 1000
//	-106 <= arr[i] <= 106
bool canMakeArithmeticProgression(int* arr, int arrSize){
int i, j, temp;
    for(i=0;i<arrSize;i++){
        for(j=i+1;j<arrSize;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int diff=arr[1]-arr[0];
    for(i=2;i<arrSize;i++){
        if(arr[i]-arr[i-1]!=diff)
            return false;
    }
    return true;
}