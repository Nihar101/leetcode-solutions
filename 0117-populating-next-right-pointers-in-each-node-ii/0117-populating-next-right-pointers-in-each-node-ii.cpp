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
void solve(Node* curr, Node* next){
    if(!curr)return;
    curr->next = next;
    Node* temp =curr;
    while(temp->next&&(!temp->next->left&&!temp->next->right))temp=temp->next;
    if(temp->next)temp=temp->next;
    std::cout<<curr->val<<"-next->"<<curr->next<<endl;
    Node * transfer = NULL;
    if(temp!=curr&&temp->right)transfer=temp->right;
    if(temp!=curr&&temp->left)transfer= temp->left;

    if(curr->right){
        solve(curr->right,transfer);
    }
    if(curr->left){
        if(curr->right)solve(curr->left,curr->right);
        else solve(curr->left,transfer);
    }

    return;
}

class Solution {
public:
    Node* connect(Node* root) {
        solve(root,NULL);
        return root;
    }
};