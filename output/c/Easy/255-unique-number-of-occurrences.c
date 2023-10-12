/**https://leetcode.com/problems/unique-number-of-occurrences/ */
//Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
// 
//Example 1:
//Input: arr = [1,2,2,1,1,3]
//Output: true
//Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
//Example 2:
//Input: arr = [1,2]
//Output: false
//Example 3:
//Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
//Output: true
// 
//Constraints:
//	1 <= arr.length <= 1000
//	-1000 <= arr[i] <= 1000
bool uniqueOccurrences(int* arr, int arrSize){
int count[2001]={0};
    int i;
    for(i=0;i<arrSize;i++){
        count[arr[i]+1000]++;
    }
    int count2[1001]={0};
    for(i=0;i<2001;i++){
        if(count[i]!=0){
            count2[count[i]]++;
            if(count2[count[i]]>1){
                return false;
            }
        }
    }
    return true;
}