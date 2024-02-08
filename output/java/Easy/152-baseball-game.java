/**https://leetcode.com/problems/baseball-game/ */
//You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
//You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
//An integer x.
//Record a new score of x.
//'+'.
//Record a new score that is the sum of the previous two scores.
//'D'.
//Record a new score that is the double of the previous score.
//'C'.
//Invalidate the previous score, removing it from the record.
//Return the sum of all the scores on the record after applying all the operations.
//The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.


class BaseballGame {
    public int calPoints(String[] operations) {
        int[] scores = new int[operations.length];
        int count = 0;
        for(int i = 0; i < operations.length; i++){
            if(operations[i].equals("+")){
                scores[count] = scores[count - 1] + scores[count - 2];
                count++;
            }else if(operations[i].equals("D")){
                scores[count] = scores[count - 1] * 2;
                count++;
            }else if(operations[i].equals("C")){
                scores[count - 1] = 0;
                count--;
            }else{
                scores[count] = Integer.parseInt(operations[i]);
                count++;
            }
        }
        int sum = 0;
        for(int i = 0; i < count; i++){
            sum += scores[i];
        }
        return sum;
        
        
    }
}

    