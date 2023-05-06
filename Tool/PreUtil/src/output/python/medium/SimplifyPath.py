#https://leetcode.com/problems/simplify-path/
#Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.
#In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.
#The canonical path should have the following format:
#The path starts with a single slash '/'.
#Any two directories are separated by a single slash '/'.
#The path does not end with a trailing '/'.
#The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
#Return the simplified canonical path.


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if path=="":
            return ""
        if path=="/":
            return "/"
        if path[-1]=="/":
            path=path[:-1]
        path=path.split("/")
        stack=[]
        for i in range(len(path)):
            if path[i]==".":
                continue
            elif path[i]=="..":
                if len(stack)>0:
                    stack.pop()
            else:
                stack.append(path[i])
        if len(stack)==0:
            return "/"
        res=""
        for i in range(len(stack)):
            res+="/"+stack[i]
        return res
        

    