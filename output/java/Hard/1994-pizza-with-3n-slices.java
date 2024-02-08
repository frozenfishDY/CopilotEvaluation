/**https://leetcode.com/problems/pizza-with-3n-slices/ */
//There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
//You will pick any pizza slice.
//Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
//Your friend Bob will pick the next slice in the clockwise direction of your pick.
//Repeat until there are no more slices of pizzas.
//Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.


class PizzaWith3NSlices {
    public int maxSizeSlices(int[] slices) {
        int n = slices.length;
        int m = n / 3;
        return Math.max(maxSum(slices, 0, n - 2, m), maxSum(slices, 1, n - 1, m));
      
    }
}
     
    