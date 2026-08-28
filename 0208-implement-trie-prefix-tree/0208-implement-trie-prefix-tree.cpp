class Trie {
private:
    struct Node {
        bool end;
        Node* child[26];
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            end = false;
        }
    };
    Node* root;

public:
    Trie() { 
        root = new Node();
     }

    void insert(string word) {
        Node* curr = root;
        for( auto c: word){
            int idx = c-'a';
            if(curr->child[idx]==NULL){
                Node* newchild = new Node();
                curr->child[idx]= newchild;
                curr= curr->child[idx];
            }
            else{
                curr= curr->child[idx];
            }
        }
        curr->end = true;
    }

    bool search(string word) {
        Node* curr = root;
        for( auto c: word){
            int idx = c-'a';
            if(curr->child[idx]==NULL){
                return false;
            }
            else{
                curr= curr->child[idx];
            }
        }
        return curr->end;
    }

    bool startsWith(string prefix) {
         Node* curr = root;
        for( auto c: prefix){
            int idx = c-'a';
            if(curr->child[idx]==NULL){
                return false;
            }
            else{
                curr= curr->child[idx];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */