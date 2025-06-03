#include<iostream>
#include<string>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool terminalNode;
    TrieNode(char data){
        this->data=data;
        terminalNode=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        // Base Case -> if no word is left
        if(word.length()==0){
            root->terminalNode=true;
            return;
        }
        // Taking the index and looking if the node is present or not
        int index=word[0]-'A';
        if(root->children[index]==NULL){
            root->children[index]=new TrieNode(word[0]);
        } 
        insertUtil(root->children[index],word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->terminalNode;
        }
        int index=word[0]-'A';
        if(root->children[index]==NULL){
            return false;
        }
        return searchUtil(root->children[index],word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root,word);
    }
    void deleteUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->terminalNode=false;
            return;
        }
        int index=word[0]-'A';
        if(root->children[index]==NULL){
            // Word exist hi nhi krta hai
            return;
        }
        deleteUtil(root->children[index],word.substr(1));
    }
    void deleteWord(string word){
        deleteUtil(root,word);
    }
};
int main(){
    Trie* t=new Trie();
    t->insertWord("MAHIM");
    t->insertWord("MAHENDRA");
    t->insertWord("VIKAS");
    t->insertWord("MAH");
    cout<<t->searchWord("MAH")<<endl;
    t->deleteWord("MAHIM");
    cout<<t->searchWord("MAHIM")<<endl;
}