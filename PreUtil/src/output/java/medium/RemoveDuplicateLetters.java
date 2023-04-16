/**https://leetcode.com/problems/remove-duplicate-letters/ */
//Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.


class RemoveDuplicateLetters {
    public String removeDuplicateLetters(String s) {
        int[] map = new int[26];
        boolean[] visited = new boolean[26];
        for(char c : s.toCharArray()){
            map[c - 'a']++;
        }
        Stack<Character> stack = new Stack<>();
        for(char c : s.toCharArray()){
            map[c - 'a']--;
            if(visited[c - 'a']){
                continue;
            }
            while(!stack.isEmpty() && stack.peek() > c && map[stack.peek() - 'a'] > 0){
                visited[stack.pop() - 'a'] = false;
            }
            stack.push(c);
            visited[c - 'a'] = true;
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()){
            sb.append(stack.pop());
        }
        return sb.reverse().toString();
        
        
    }
}

    