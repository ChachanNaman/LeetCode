//14. Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/description/

//TC = O(m*n).  n strings of m lenght
//SC = O(m*n)

class Trienode{
    public :
    char data;
    bool isterminal;
    int wordcount;
    Trienode* children[26];

    Trienode(char ch){
        data = ch;
        for(int i = 0 ; i<26;i++){
            children[i]=NULL;
        }
        isterminal = false;
        wordcount = 0;
    }
};
class trie{
    public:
    Trienode* root ;

    trie(char ch){
        root = new Trienode(ch);//have some data like character 
    }

    void insertutil(Trienode* root , string word){
        //base case if no char left
        if(word.length()==0){
            root->isterminal = true;
            return;
        }

        int index = word[0]-'a';
        Trienode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new Trienode(word[0]);
            root->wordcount++;
            root->children[index]= child;
        }

        //recursion
        insertutil(child , word.substr(1));
    }
    void insertword(string word){
        insertutil(root, word);
    }
    
    void lcp(string word ,string &ans ){
        for (int i = 0 ; i < word.length(); i++){
            char ch = word[i];
            if(root->wordcount == 1){
                ans.push_back(ch);
                //move forward
                int index = ch-'a';
                root = root->children[index];
            }
            else{
                break;
            }

            if(root->isterminal){
                break;
            }
        }
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Algo :
        //1. insert all words into trie 
        //2. then if root have one child then store in ans coz trie have tree like structure and one child means common to all sub trees
        //3. if child node got next more than one children then stop there means no more common prefix

        //so traverse hamesha first word se trie mein like strs[0] ko lcp ke function mein bhejunga to traverese from first string only like first word



        int n = strs.size();

        for (const string& s : strs) {
            if (s.empty()) return "";
        }//if one of the string is empty return straigh ""ans rather than traversing all

        trie *t = new trie('\0');

        for(int i = 0 ; i <n ; i++){
            t->insertword(strs[i]);
        }
        string word = strs[0]; //first word to be inserted first for initial start for lcp

        string ans = "";

        t->lcp(word, ans);
        return ans;
    }
};