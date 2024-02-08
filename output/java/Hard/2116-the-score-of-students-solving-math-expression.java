/**https://leetcode.com/problems/the-score-of-students-solving-math-expression/ */
//You are given a string s that contains digits 0-9, addition symbols '+', and multiplication symbols '*' only, representing a valid math expression of single digit numbers (e.g., 3+5*2). This expression was given to n elementary school students. The students were instructed to get the answer of the expression by following this order of operations:
//Compute multiplication, reading from left to right; Then,
//Compute addition, reading from left to right.
//You are given an integer array answers of length n, which are the submitted answers of the students in no particular order. You are asked to grade the answers, by following these rules:
//If an answer equals the correct answer of the expression, this student will be rewarded 5 points;
//Otherwise, if the answer could be interpreted as if the student applied the operators in the wrong order but had correct arithmetic, this student will be rewarded 2 points;
//Otherwise, this student will be rewarded 0 points.
//Return the sum of the points of the students.


class TheScoreOfStudentsSolvingMathExpression {
    public int scoreOfStudents(String s, int[] answers) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i += 2){
            dp[i][i] = s.charAt(i) - '0';
        }
        for(int len = 3; len <= n; len += 2){
            for(int i = 0; i + len <= n; i += 2){
                int j = i + len - 1;
                for(int k = i + 1; k < j; k += 2){
                    if(s.charAt(k) == '+'){
                        dp[i][j] = Math.max(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                    }else{
                        dp[i][j] = Math.max(dp[i][j], dp[i][k - 1] * dp[k + 1][j]);
                    }
                }
            }
        }
        int res = 0;
        for(int a : answers){
            if(a == dp[0][n - 1]){
                res += 5;
            }else if(a == dp[0][n - 1] + 1 || a == dp[0][n - 1] - 1){
                res += 2;
            }
        }
        return res;
        
    }
}
     
    