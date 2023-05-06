/**https://leetcode.com/problems/brace-expansion-ii/ */
//Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) denote the set of words the expression represents.
//The grammar can best be understood through simple examples:
//Single letters represent a singleton set containing that word.
//R("a") = {"a"}
//R("w") = {"w"}
//When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
//R("{a,b,c}") = {"a","b","c"}
//R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
//When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression.
//R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
//R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
//Formally, the three rules for our grammar:
//For every lowercase letter x, we have R(x) = {x}.
//For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) �� R(e2) �� ...
//For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) �� R(e2)}, where + denotes concatenation, and �� denotes the cartesian product.
//Given an expression representing a set of words under the given grammar, return the sorted list of words that the expression represents.


class BraceExpansionIi {
    public List<String> braceExpansionII(String expression) {
        List<String> res = new ArrayList<>();
        if (expression == null || expression.length() == 0) {
            return res;
        }
        Stack<List<String>> stack = new Stack<>();
        stack.push(new ArrayList<>());
        int i = 0;
        while (i < expression.length()) {
            char c = expression.charAt(i);
            if (c == '{') {
                int j = i;
                int count = 0;
                while (j < expression.length()) {
                    if (expression.charAt(j) == '{') {
                        count++;
                    } else if (expression.charAt(j) == '}') {
                        count--;
                    }
                    if (count == 0) {
                        break;
                    }
                    j++;
                }
                List<String> list = braceExpansionII(expression.substring(i + 1, j));
                stack.push(list);
                i = j + 1;
            } else if (c == ',') {
                i++;
            } else if (c == '}') {
                List<String> list = stack.pop();
                List<String> prev = stack.peek();
                prev.addAll(list);
                i++;
            } else {
                int j = i;
                while (j < expression.length() && Character.isLowerCase(expression.charAt(j))) {
                    j++;
                }
                List<String> prev = stack.peek();
                prev.add(expression.substring(i, j));
                i = j;
            }
        }
        List<String> list = stack.pop();
        Collections.sort(list);
        return list;
        
    }
}
     
    