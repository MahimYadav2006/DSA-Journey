#include<vector>
#include<string>

using namespace std;
class TrieNode{
    public:
    char value;
    vector<TrieNode*> children;
    bool isEndPoint;
    TrieNode(char value){
        this->value = value;
        children.resize(26,NULL);
        isEndPoint = false;
    }
};
class Trie {
public:
    TrieNode* root = new TrieNode('.');
    Trie() {
        
    }
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(temp->children[index] == NULL) temp->children[index] = new TrieNode(word[i]); 
            temp = temp->children[index];
        }
        temp->isEndPoint = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            int index = word[i]-'a';
            if(temp->children[index] == NULL) return false;
            temp = temp->children[index];
        }
        return temp->isEndPoint;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i=0;i<prefix.length();i++){
            int index = prefix[i]-'a';
            if(temp->children[index] == NULL) return false;
            temp = temp->children[index];
        }
        return true;
    }
};