/**https://leetcode.com/problems/couples-holding-hands/ */
//There are n couples sitting in 2n seats arranged in a row and want to hold hands.
//The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
//Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.


class CouplesHoldingHands {
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int x = row[i];
            int y = x % 2 == 0 ? x + 1 : x - 1;
            if (row[i + 1] == y) {
                continue;
            }
            ans++;
            int j = pos[y];
            row[j] = row[i + 1];
            pos[row[i + 1]] = j;
        }
        return ans;
        
    }
}
     
    