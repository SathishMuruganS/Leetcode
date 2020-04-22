/**
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

**/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
    TreeNode* head;

    TreeNode* bstInsert(TreeNode** node, int val){
        if (*node == NULL){
            *node = new TreeNode(val);
            if (head == NULL){
                head = *node;
            }
            return head;
        }

        if ((*node)->val < val){
            return bstInsert(&((*node)->right), val);
        } else {
            return bstInsert(&((*node)->left), val);
        }
    }

public:
    Solution()
    {
        head = NULL;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        for(auto ii: preorder){
            bstInsert(&head, ii);
        }

        return head;
    }
    
    bool bstCompare(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL || root2 == NULL) {
            return root1 == root2;
        }

        if (root1->val != root2->val) {
            return false;
        }

        return bstCompare(root1->left, root2->left) && bstCompare(root1->right, root2->right);
    }

    void bstPreorder(TreeNode* node){
        if (node != NULL){
            cout<<node->val<<" ";
            bstPreorder(node->left);
            bstPreorder(node->right);
        } 
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<int> vec;
        vector<TreeNode*> tree;

        for(int i = 1; i<= n; i++){
            vec.push_back(i);
        }

        bool flag = true;
        do{
            TreeNode* temp_node = bstFromPreorder(vec);

            for(auto ii: tree){
                if (!bstCompare(temp_node, ii)){
                    flag = true;
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                tree.push_back(temp_node);
            }
            
            head = NULL;
        }while(next_permutation(vec.begin(), vec.end()));

        return tree;
    }
};

int main()
{
    Solution s;
    vector<TreeNode*> vec_tree = s.generateTrees(4);
    
    for(auto ii: vec_tree){
        cout<<"[";
        s.bstPreorder(ii);
        cout<<"]"<<endl;
    }

    return 0;
}
