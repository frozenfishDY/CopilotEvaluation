/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.


class SwapAdjacentInLrString {
    public boolean canTransform(String start, String end) {
        int n = start.length();
        int m = end.length();
        if(n != m){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            while(i < n && start.charAt(i) == 'X'){
                i++;
            }
            while(j < m && end.charAt(j) == 'X'){
                j++;
            }
            if(i == n && j == m){
                return true;
            }
            if(i == n || j == m){
                return false;
            }
            if(start.charAt(i) != end.charAt(j)){
                return false;
            }
            if(start.charAt(i) == 'L' && i < j){
                return false;
            }
            if(start.charAt(i) == 'R' && i > j){
                return false;
            }
            i++;
            j++;
        }
        return true;
        
    }
}

    