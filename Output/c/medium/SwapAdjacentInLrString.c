/**https://leetcode.com/problems/swap-adjacent-in-lr-string/ */
//In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.


bool canTransform(char * start, char * end){
    int len = strlen(start);
    int i = 0;
    int j = 0;
    while(i < len && j < len){
        while(i < len && start[i] == 'X'){
            i++;
        }
        while(j < len && end[j] == 'X'){
            j++;
        }
        if((i < len) ^ (j < len)){
            return false;
        }
        if(i < len && j < len){
            if(start[i] != end[j]){
                return false;
            }
            if(start[i] == 'L' && i < j){
                return false;
            }
            if(start[i] == 'R' && i > j){
                return false;
            }
        }
        i++;
        j++;
    }
    return true;

}

    