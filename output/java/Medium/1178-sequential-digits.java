/**https://leetcode.com/problems/sequential-digits/ */
//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.


class SequentialDigits {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> res = new ArrayList<>();
        for(int i = 1; i <= 9; i++){
            int num = i;
            for(int j = i + 1; j <= 9; j++){
                num = num * 10 + j;
                if(num >= low && num <= high){
                    res.add(num);
                }
            }
        }
        Collections.sort(res);
        return res;
        
    }
}

    