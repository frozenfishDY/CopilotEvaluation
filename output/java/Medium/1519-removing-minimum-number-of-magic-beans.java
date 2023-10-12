/**https://leetcode.com/problems/removing-minimum-number-of-magic-beans/ */
//You are given an array of positive integers beans, where each integer represents the number of magic beans found in a particular magic bag.
//Remove any number of beans (possibly none) from each bag such that the number of beans in each remaining non-empty bag (still containing at least one bean) is equal. Once a bean has been removed from a bag, you are not allowed to return it to any of the bags.
//Return the minimum number of magic beans that you have to remove.
// 
//Example 1:
//Input: beans = [4,1,6,5]
//Output: 4
//Explanation: 
//- We remove 1 bean from the bag with only 1 bean.
//  This results in the remaining bags: [4,0,6,5]
//- Then we remove 2 beans from the bag with 6 beans.
//  This results in the remaining bags: [4,0,4,5]
//- Then we remove 1 bean from the bag with 5 beans.
//  This results in the remaining bags: [4,0,4,4]
//We removed a total of 1 + 2 + 1 = 4 beans to make the remaining non-empty bags have an equal number of beans.
//There are no other solutions that remove 4 beans or fewer.
//Example 2:
//Input: beans = [2,10,3,2]
//Output: 7
//Explanation:
//- We remove 2 beans from one of the bags with 2 beans.
//  This results in the remaining bags: [0,10,3,2]
//- Then we remove 2 beans from the other bag with 2 beans.
//  This results in the remaining bags: [0,10,3,0]
//- Then we remove 3 beans from the bag with 3 beans. 
//  This results in the remaining bags: [0,10,0,0]
//We removed a total of 2 + 2 + 3 = 7 beans to make the remaining non-empty bags have an equal number of beans.
//There are no other solutions that removes 7 beans or fewer.
// 
//Constraints:
//	1 <= beans.length <= 105
//	1 <= beans[i] <= 105
class Solution {
    public long minimumRemoval(int[] beans) {
        int n = beans.length;
        int[] pre = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1];
            if (beans[i - 1] > beans[i - 2]) {
                pre[i]++;
            }
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (beans[mid] < beans[i]) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (beans[l] < beans[i]) {
                res += pre[i] - pre[l];
            } else {
                res += pre[i] - pre[l] - 1;
            }
        }
        return res;
    }
}