/**https://leetcode.com/problems/circular-array-loop/ */
//You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:
//If nums[i] is positive, move nums[i] steps forward, and
//If nums[i] is negative, move nums[i] steps backward.
//Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
//A cycle in the array consists of a sequence of indices seq of length k where:
//Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
//Every nums[seq[j]] is either all positive or all negative.
//k > 1
//Return true if there is a cycle in nums, or false otherwise.


class CircularArrayLoop {
    public boolean circularArrayLoop(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                continue;
            }
            int slow = i;
            int fast = next(nums, i);
            while(nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(nums, fast)] > 0){
                if(slow == fast){
                    if(slow != next(nums, slow)){
                        return true;
                    }
                    break;
                }
                slow = next(nums, slow);
                fast = next(nums, next(nums, fast));
            }
            slow = i;
            int val = nums[i];
            while(nums[slow] * val > 0){
                int next = next(nums, slow);
                nums[slow] = 0;
                slow = next;
            }
        }
        return false;
        
        
    }
}

    