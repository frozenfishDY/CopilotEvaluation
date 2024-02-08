/**https://leetcode.com/problems/sliding-window-median/ */
//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
//For examples, if arr = [2,3,4], the median is 3.
//For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
//You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.


class SlidingWindowMedian {
    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        double[] ans = new double[n - k + 1];
        PriorityQueue<Integer> small = new PriorityQueue<Integer>(new Comparator<Integer>() {
            public int compare(Integer num1, Integer num2) {
                return num2 - num1;
            }
        });
        PriorityQueue<Integer> large = new PriorityQueue<Integer>((num1, num2) -> (num1 - num2));
        for (int i = 0; i < n; i++) {
            if (small.size() <= large.size()) {
                large.add(nums[i]);
                small.add(large.poll());
            } else {
                small.add(nums[i]);
                large.add(small.poll());
            }
            if (small.size() + large.size() == k) {
                ans[i - k + 1] = ((long) small.peek() + large.peek()) / 2.0;
                if (!small.remove(nums[i - k + 1])) {
                    large.remove(nums[i - k + 1]);
                }
            }
        }
        return ans;
        
    }
}
     
    