/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int k=q.size()-1;
            Node* a = q.front();
            q.pop();
            if(a->left)q.push(a->left);
            if(a->right)q.push(a->right);
            while(k--){
                Node* b = q.front();
                q.pop();
                if(b->left)q.push(b->left);
                if(b->right)q.push(b->right);
                a->next = b;
                a=b;
            }
        }
        return root;
    }
};