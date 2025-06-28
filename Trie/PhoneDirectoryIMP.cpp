//Phone directory
//https://www.geeksforgeeks.org/problems/phone-directory4628/1?page=1&category=Trie&sortBy=submissions

// User function Template for C++
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
    
    void printans(Trienode *curr ,vector<string> &temp , string prefix){
        if(curr->isterminal){
            temp.push_back(prefix);
        }
        
        for(char ch = 'a' ; ch<='z';ch++){
            Trienode * next = curr->children[ch-'a'];
            
            if(next != NULL){
                prefix.push_back(ch);
                printans(next , temp , prefix);
                prefix.pop_back();
            }
            
        }
    }
    
    
    
    
     vector<vector<string>> getsuggestion(string str){
         Trienode * prev = root;
         string prefix = "";
         vector<vector<string>> output;
         for(int i = 0 ; i < str.length();i++){
             char lastch = str[i];
             
             //push in prefix 
             prefix.push_back(lastch);
             
             //mark current node which is connected to prev node 
             Trienode *curr = prev->children[lastch-'a'];
             
             //if not found
             if(curr == NULL){
                // Once a prefix is not found, all subsequent prefixes should be "0"
                while (output.size() < str.length()) {
                    output.push_back({"0"});
                }
                break;
             }
             
             //if found
             
             vector<string> temp;  //an empty vector 
             printans(curr, temp , prefix);
             sort(temp.begin(), temp.end());
             output.push_back(temp);  //push that char in output final
             temp.clear();  //for next char
             prev = curr;
         }
         return output;
     }
};
class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie *t = new Trie();
        
        for(int i = 0 ; i <n;i++){
            t->insert(contact[i]);
        }
        
        return t->getsuggestion(s);
    }
};