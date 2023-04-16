/**https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/ */
//The XOR sum of a list is the bitwise XOR of all its elements. If the list only contains one element, then its XOR sum will be equal to this element.
//For example, the XOR sum of [1,2,3,4] is equal to 1 XOR 2 XOR 3 XOR 4 = 4, and the XOR sum of [3] is equal to 3.
//You are given two 0-indexed arrays arr1 and arr2 that consist only of non-negative integers.
//Consider the list containing the result of arr1[i] AND arr2[j] (bitwise AND) for every (i, j) pair where 0 <= i < arr1.length and 0 <= j < arr2.length.
//Return the XOR sum of the aforementioned list.


int getXORSum(int* arr1, int arr1Size, int* arr2, int arr2Size){
    int i,j,k;
    int ans = 0;
    for(i=0;i<arr1Size;i++){
        for(j=0;j<arr2Size;j++){
            ans = ans ^ (arr1[i] & arr2[j]);
        }
    }
    return ans;

}

    