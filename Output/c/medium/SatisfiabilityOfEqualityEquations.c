/**https://leetcode.com/problems/satisfiability-of-equality-equations/ */
//You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
//Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.


bool equationsPossible(char ** equations, int equationsSize){
    int parent[26];
    for(int i = 0; i < 26; i++){
        parent[i] = i;
    }
    for(int i = 0; i < equationsSize; i++){
        if(equations[i][1] == '='){
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            int xParent = findParent(parent, x);
            int yParent = findParent(parent, y);
            if(xParent != yParent){
                parent[xParent] = yParent;
            }
        }
    }
    for(int i = 0; i < equationsSize; i++){
        if(equations[i][1] == '!'){
            int x = equations[i][0] - 'a';
            int y = equations[i][3] - 'a';
            int xParent = findParent(parent, x);
            int yParent = findParent(parent, y);
            if(xParent == yParent){
                return false;
            }
        }
    }
    return true;

}

    