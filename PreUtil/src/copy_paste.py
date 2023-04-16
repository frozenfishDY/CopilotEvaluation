
def getFileNameByUrl(url):
    prefix='https://leetcode.com/problems/'
    fileName=url[len(prefix):len(url)-1]
    res=purifyFileName(fileName)
    return res
    

def purifyFileName(fileName):
    numDict={"0":"Zero","1":"One","2":"Two","3":"Three","4":"Four","5":"Five","6":"Six","7":"Seven","8":"Eight","9":"Nine"}
    res=""
    str=fileName.split('-')
    if str[0].isdigit():
        for i in range(0,len(str[0])):
            if(str[0][i] in numDict):
                res=res+numDict[str[0][i]]
        for i in range(1,len(str)):
          str[i]=str[i].title()
          res=res+str[i]
    else:
        for i in range(0,len(str)):
          str[i]=str[i].title()
          res=res+str[i]
    return res

def purifyJavaClassName(java_content,filename):
    if "Solution" in java_content:
        java_content=java_content.replace("Solution",filename)
    return java_content

def main():       
    url="https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/"
    
    context_comment = """

You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.

"""

    c_content = """

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize){

}

    """

    js_content = """

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number[]} queries
 * @return {number[]}
 */
var treeQueries = function(root, queries) {
    
};

    """

    java_content ="""

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int[] treeQueries(TreeNode root, int[] queries) {
        
    }
}
     
    """

    python_content = """

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def treeQueries(self, root, queries):
        \"""
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        \"""
        
        
    """
    filename=getFileNameByUrl(url)
    java_content=purifyJavaClassName(java_content,filename)

    extension_content_dict = {".py": python_content, ".java": java_content, ".js": js_content, ".c": c_content}
    extension_path_dict = {".py": "output/python/hard/", ".java": "output/java/hard/", ".js": "output/javascript/hard/", ".c": "output/c/hard/"}
    print("Creating and Copying Comment and Function Name to all dirs...")

    # Read the training data
    for key,value in extension_content_dict.items():
        # write to comment and function name for copilot file
        file = extension_path_dict[key]+filename+key
        with open(file, 'w') as f:
            # write url of the leetcode problem
            if key == ".py":
                f.write("#"+url+"\n")
                for comment in context_comment.splitlines():
                    if comment != "":
                        comment_string = '#' + comment + '\n'
                        f.write(comment_string)
            else:
                f.write("/**"+url+" */"+"\n")
                for comment in context_comment.splitlines():
                    if comment !="":
                        comment_string = '//' + comment + '\n'
                        f.write(comment_string)
            f.write(value)

main()
