/**https://leetcode.com/problems/sort-an-array/ */
//Given an array of integers nums, sort the array in ascending order and return it.
//You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


class SortAnArray {
    public int[] sortArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        int[] count = new int[100001];
        for(int i = 0; i < n; i++){
            count[nums[i] + 50000]++;
        }
        int index = 0;
        for(int i = 0; i < 100001; i++){
            while(count[i] > 0){
                res[index++] = i - 50000;
                count[i]--;
            }
        }
        return res;
        
    }
}

    