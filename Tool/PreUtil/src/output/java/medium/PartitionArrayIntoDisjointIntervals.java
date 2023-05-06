/**https://leetcode.com/problems/partition-array-into-disjoint-intervals/ */
//Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
//Every element in left is less than or equal to every element in right.
//left and right are non-empty.
//left has the smallest possible size.
//Return the length of left after such a partitioning.
//Test cases are generated such that partitioning exists.


class PartitionArrayIntoDisjointIntervals {
    public int partitionDisjoint(int[] nums) {
        int n = nums.length;
        int[] leftMax = new int[n];
        int[] rightMin = new int[n];
        leftMax[0] = nums[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = Math.max(leftMax[i - 1], nums[i]);
        }
        rightMin[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMin[i] = Math.min(rightMin[i + 1], nums[i]);
        }
        for(int i = 1; i < n; i++){
            if(leftMax[i - 1] <= rightMin[i]){
                return i;
            }
        }
        return -1;
        
        
    }
}

    