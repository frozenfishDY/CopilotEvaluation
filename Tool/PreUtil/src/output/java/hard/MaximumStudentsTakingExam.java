/**https://leetcode.com/problems/maximum-students-taking-exam/ */
//Given a m * n matrix seats  that represent seats distributions in a classroom. If a seat is broken, it is denoted by '#' character otherwise it is denoted by a '.' character.
//Students can see the answers of those sitting next to the left, right, upper left and upper right, but he cannot see the answers of the student sitting directly in front or behind him. Return the maximum number of students that can take the exam together without any cheating being possible..
//Students must be placed in seats in good condition.


class MaximumStudentsTakingExam {
    public int maxStudents(char[][] seats) {
        int m = seats.length;
        int n = seats[0].length;
        int[] dp = new int[1 << n];
        for(int i = 0; i < m; i++){
            int[] next = new int[1 << n];
            for(int j = 0; j < (1 << n); j++){
                if(isValid(j, seats[i])){
                    for(int k = 0; k < (1 << n); k++){
                        if((j & k) == 0){
                            next[j] = Math.max(next[j], dp[k] + Integer.bitCount(j));
                        }
                    }
                }
            }
            dp = next;
        }
        int res = 0;
        for(int i = 0; i < (1 << n); i++){
            res = Math.max(res, dp[i]);
        }
        return res;
        
    }
}
     
    