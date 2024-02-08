/**https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/ */
//You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
//status[i] is 1 if the ith box is open and 0 if the ith box is closed,
//candies[i] is the number of candies in the ith box,
//keys[i] is a list of the labels of the boxes you can open after opening the ith box.
//containedBoxes[i] is a list of the boxes you found inside the ith box.
//You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
//Return the maximum number of candies you can get following the rules above.


class MaximumCandiesYouCanGetFromBoxes {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int n = status.length;
        boolean[] opened = new boolean[n];
        boolean[] hasKey = new boolean[n];
        boolean[] hasBox = new boolean[n];
        for (int i : initialBoxes) {
            hasBox[i] = true;
        }
        int res = 0;
        while (true) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                if (hasBox[i] && (status[i] == 1 || hasKey[i])) {
                    res += candies[i];
                    opened[i] = true;
                    hasBox[i] = false;
                    for (int j : keys[i]) {
                        hasKey[j] = true;
                    }
                    for (int j : containedBoxes[i]) {
                        hasBox[j] = true;
                    }
                    found = true;
                }
            }
            if (!found) {
                break;
            }
        }
        return res;
        
    }
}
     
    