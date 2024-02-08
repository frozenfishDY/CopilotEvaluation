/**https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/ */
//Alice manages a company and has rented some floors of a building as office space. Alice has decided some of these floors should be special floors, used for relaxation only.
//You are given two integers bottom and top, which denote that Alice has rented all the floors from bottom to top (inclusive). You are also given the integer array special, where special[i] denotes a special floor that Alice has designated for relaxation.
//Return the maximum number of consecutive floors without a special floor.


class MaximumConsecutiveFloorsWithoutSpecialFloors {
    public int maxConsecutive(int bottom, int top, int[] special) {
        int[] count = new int[top - bottom + 1];
        for (int floor : special) {
            count[floor - bottom]++;
        }
        int result = 0;
        int current = 0;
        for (int i = 0; i < count.length; i++) {
            if (count[i] == 0) {
                current++;
            } else {
                result = Math.max(result, current);
                current = 0;
            }
        }
        result = Math.max(result, current);
        return result;
        
    }
}
     
    