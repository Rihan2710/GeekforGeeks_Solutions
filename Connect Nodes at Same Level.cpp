/*
Given a binary tree, connect the nodes that are at the same level. 
The structure of the tree Node contains an addition nextRight pointer for this purpose.

Initially, all the nextRight pointers point to garbage values. 
Your function should set these pointers to point next right for each node.

       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL
Example 1:

Input:
     3
   /  \
  1    2
Output:
3 1 2
1 3 2
Explanation:The connected tree is
       3 ------> NULL
     /   \
    1---> 2 -----> NULL

Example 2:

Input:
      10
    /   \
   20   30
  /  \
 40  60
Output:
10 20 30 40 60
40 20 60 10 30
Explanation:The connected tree is
        10 ---> NULL
       /   \
     20---> 30 ---> NULL
   /   \
 40---> 60 ---> NULL

Your Task:
You don't have to read input or print anything. Complete the function connect() that takes the root of the tree as  input parameter and connects the nodes that lie at the same level. 

Note: The generated output will contain 2 lines. First line contains the level order traversal of the tree and second line contains the inorder traversal of the tree.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */


Solution : 

class Solution{
    public:
    void connect(Node *root)
    {   
        //Code Starts here
        queue<Node *> nq;
        nq.push(root);
        nq.push(NULL);
        while(!nq.empty())
        {
            Node *temp = nq.front();
            nq.pop();
            if(temp==NULL)
            {
                if(!nq.empty())
                nq.push(NULL);
            }
            else
            {
                temp->nextRight = nq.front();
                if(temp->left) 
                    nq.push(temp->left);
                if(temp->right) 
                    nq.push(temp->right);
            }
        }   //Ends here...
       

    }    
};