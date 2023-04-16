/**https://leetcode.com/problems/simplify-path/ */
//Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
//In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
//The canonical path should have the following format:
//The path starts with a single slash '/'.
//Any two directories are separated by a single slash '/'.
//The path does not end with a trailing '/'.
//The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
//Return the simplified canonical path.


char * simplifyPath(char * path){
    int len = strlen(path);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    result[0] = '\0';
    int i = 0;
    int j = 0;
    while(i < len){
        if(path[i] == '/'){
            i++;
            continue;
        }
        if(path[i] == '.'){
            if(i + 1 < len && path[i + 1] == '.'){
                if(j > 0){
                    j--;
                    while(j > 0 && result[j] != '/'){
                        j--;
                    }
                }
                i += 2;
            }
            else if(i + 1 < len && path[i + 1] == '/'){
                i += 2;
            }
            else{
                result[j++] = path[i++];
            }
        }
        else{
            result[j++] = path[i++];
        }
    }
    if(j == 0){
        result[j++] = '/';
    }
    else if(result[j - 1] == '/'){
        j--;
    }
    result[j] = '\0';
    return result;

}

    