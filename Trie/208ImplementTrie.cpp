//208. Implement Trie (Prefix Tree)
//https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=problem-list-v2&envId=trie

class Trienode {
public:
    char data;
    bool isterminal;
    Trienode* children[26];

    Trienode(char dd) {
        data = dd;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie {
public:
    Trienode* root;
    Trie() { root = new Trienode('\0'); }

    void insertutil(Trienode*root , string word){

        //base case if no word 
        if(word.length()==0){
            root-> isterminal = true;  //means root has direct terminal node , no node further so terminal
            return;
        }

        int index = word[0]-'a';
        Trienode* child;

        //alphabet present 
        if(root -> children[index] != NULL){//means root have that children of word needed "CAT" -> root have 'C'
            child = root-> children[index];
        }

        else{//alphabet not present , then create
            child = new Trienode(word[0]);
            root -> children[index] = child;
        }

        //recusrion for next alphabet of word
        insertutil(child , word.substr(1));

    }

    void insert(string word) {
        insertutil(root, word);
    }

    bool searchutil(Trienode* root, string word){

        //if got terminal node 
        if(word.length()==0){
            return root->isterminal;
        }

        int index = word[0]-'a';
        Trienode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{//not there in tree
            return false; 
        }

        //now recurssion
        return searchutil(child , word.substr(1));
    }

    bool search(string word) {
        return searchutil(root, word);
    }

    bool startutil(Trienode* root, string word){

        //if got terminal node 
        if(word.length()==0){
            return true;  //just return true if there word exist with this
        }

        int index = word[0]-'a';
        Trienode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{//not there in tree
            return false; 
        }

        //now recurssion
        return startutil(child , word.substr(1));
    }
    bool startsWith(string prefix) {
        return startutil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */