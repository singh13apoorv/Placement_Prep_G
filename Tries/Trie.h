#include "TrieNode.h"
#include <string>
using namespace std;

class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    private:
    void insertWord(TrieNode *root, string word){
        if (word.size() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root -> children[index] != NULL){
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    public:
    void insertWord(string word){
        insertWord(root, word);
    }

    private:
    bool search(TrieNode *root, string word){
        if (word.size() == 0){
            if (root -> isTerminal == true){
                return true;
            }
            else {
                return false;
            }
        }

        int index = word[0] - 'a';
        if (root -> children[index] == NULL){
            return false;
        }

        bool smallAns = search(root -> children[index], word.substr(1));

        return smallAns;
    }

    public:
    bool search(string word){
        return search(root, word);
    }

    private:
    void remove(TrieNode *root, string word){
        if (word.size() == 0){
            root -> isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root -> children[index] != NULL){
            child = root -> children[index];
        }
        else {
            return;
        }

        remove(child, word.substr(1));

        if (child -> isTerminal == false){
            for (int i = 0; i < 26; i++){
                if (child -> children[i] != NULL){
                    return;
                }
            }

            delete child;
            root -> children[index] = NULL;
        }
    }

    public:
    void remove(string word){
        remove(root, word);
    }
};