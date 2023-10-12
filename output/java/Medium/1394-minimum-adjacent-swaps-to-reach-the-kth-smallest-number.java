/**https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/ */
//You are given a string num, representing a large integer, and an integer k.
//We call some integer wonderful if it is a permutation of the digits in num and is greater in value than num. There can be many wonderful integers. However, we only care about the smallest-valued ones.
//	For example, when num = "5489355142":
//	
//		The 1st smallest wonderful integer is "5489355214".
//		The 2nd smallest wonderful integer is "5489355241".
//		The 3rd smallest wonderful integer is "5489355412".
//		The 4th smallest wonderful integer is "5489355421".
//	
//	
//Return the minimum number of adjacent digit swaps that needs to be applied to num to reach the kth smallest wonderful integer.
//The tests are generated in such a way that kth smallest wonderful integer exists.
// 
//Example 1:
//Input: num = "5489355142", k = 4
//Output: 2
//Explanation: The 4th smallest wonderful number is "5489355421". To get this number:
//- Swap index 7 with index 8: "5489355142" -> "5489355412"
//- Swap index 8 with index 9: "5489355412" -> "5489355421"
//Example 2:
//Input: num = "11112", k = 4
//Output: 4
//Explanation: The 4th smallest wonderful number is "21111". To get this number:
//- Swap index 3 with index 4: "11112" -> "11121"
//- Swap index 2 with index 3: "11121" -> "11211"
//- Swap index 1 with index 2: "11211" -> "12111"
//- Swap index 0 with index 1: "12111" -> "21111"
//Example 3:
//Input: num = "00123", k = 1
//Output: 1
//Explanation: The 1st smallest wonderful number is "00132". To get this number:
//- Swap index 3 with index 4: "00123" -> "00132"
// 
//Constraints:
//	2 <= num.length <= 1000
//	1 <= k <= 1000
//	num only consists of digits.
class Solution {
    public int getMinSwaps(String num, int k) {
        char[] nums = num.toCharArray();
        for (int i = 0; i < k; i++) {
            nextPermutation(nums);
        }
        return minSwaps(num.toCharArray(), nums);
    }
    private void nextPermutation(char[] nums) {
        int n = nums.length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }
    private int minSwaps(char[] nums, char[] target) {
        int res = 0;
        int i = 0;
        while (i < nums.length) {
            if (nums[i] != target[i]) {
                int j = i + 1;
                while (j < nums.length && nums[j] != target[i]) {
                    j++;
                }
                while (j > i) {
                    swap(nums, j, j - 1);
                    j--;
                    res++;
                }
            }
            i++;
        }
        return res;
    }
    private void reverse(char[] nums, int start) {
        int left = start;
        int right = nums.length - 1;
        while (left < right) {
            swap(nums, left++, right--);
        }

    }
    private void swap(char[] nums, int i, int j) {
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

    }
}