/**https://leetcode.com/problems/palindrome-pairs/ */
//You are given a 0-indexed array of unique strings words.
//A palindrome pair is a pair of integers (i, j) such that:
//0 <= i, j < words.length,
//i != j, and
//words[i] + words[j] (the concatenation of the two strings) is a palindrome.
//Return an array of all the palindrome pairs of words.


class PalindromePairs {
    public List<List<Integer>> palindromePairs(String[] words) {
        int n = words.length;
        List<List<Integer>> ans = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(words[i], i);
        }
        for (int i = 0; i < n; i++) {
            String word = words[i];
            int m = word.length();
            for (int j = 0; j <= m; j++) {
                String left = word.substring(0, j);
                String right = word.substring(j);
                if (isPalindrome(left)) {
                    String rightRev = new StringBuilder(right).reverse().toString();
                    if (map.containsKey(rightRev) && map.get(rightRev) != i) {
                        List<Integer> list = new ArrayList<>();
                        list.add(map.get(rightRev));
                        list.add(i);
                        ans.add(list);
                    }
                }
                if (isPalindrome(right)) {
                    String leftRev = new StringBuilder(left).reverse().toString();
                    if (map.containsKey(leftRev) && map.get(leftRev) != i && right.length() != 0) {
                        List<Integer> list = new ArrayList<>();
                        list.add(i);
                        list.add(map.get(leftRev));
                        ans.add(list);
                    }
                }
            }
        }
        return ans;
        
        
    }
}
     
    