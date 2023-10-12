/**https://leetcode.com/problems/solve-the-equation/ */
//Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
//If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// 
//Example 1:
//Input: equation = "x+5-3+x=6+x-2"
//Output: "x=2"
//Example 2:
//Input: equation = "x=x"
//Output: "Infinite solutions"
//Example 3:
//Input: equation = "2x=x"
//Output: "x=0"
// 
//Constraints:
//	3 <= equation.length <= 1000
//	equation has exactly one '='.
//	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
class Solution {
    public String solveEquation(String equation) {
        int[] left = evaluate(equation.split("=")[0]);
        int[] right = evaluate(equation.split("=")[1]);
        if (left[0] == right[0] && left[1] == right[1]) {
            return "Infinite solutions";
        }
        if (left[0] == right[0]) {
            return "No solution";
        }
        return "x=" + (right[1] - left[1]) / (left[0] - right[0]);
    }
    private int[] evaluate(String expression) {
        String[] tokens = expression.split("(?=[+-])");
        int[] result = new int[2];
        for (String token : tokens) {
            if (token.equals("+x") || token.equals("x")) {
                result[0]++;
            } else if (token.equals("-x")) {
                result[0]--;
            } else if (token.contains("x")) {
                result[0] += Integer.parseInt(token.substring(0, token.length() - 1));
            } else {
                result[1] += Integer.parseInt(token);
            }
        }
        return result;
    }
}