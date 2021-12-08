#include"Trie.h"
#include<string>
#include<iostream>
using namespace std;

void Trie::insertWord(string word)
{

	TrieNode * curr = this->root;
    for (int i = 0; i < word.length(); i++)
    {
        TrieNode* temp = curr/*->children[(word[i] - 97)] */;
        // create a new node if the path doesn't exist
        if (curr->children[(word[i] - 97)] == nullptr) {
            //TrieNode * temp1 = new TrieNode();
            curr->children[(int)(word[i] - 97)] = new TrieNode();
            //curr->root->children[(int)(word[i] - 97)] = new TrieNode();

        }

        // go to the next node
        //int z = (int)(word[i] - 97);
        curr = curr->children[(int)(word[i] - 97)];
    }
    curr->isEndWord = true;
}

bool Trie::deleteWord(TrieNode * node, string word)
{
    if (node == nullptr) {
        return false;
    }

    // if the end of the word is not reached
    if (word.length())
    {

        // recur for the node corresponding to the next character in the word
        // and if it returns true, delete the current node (if it is non-leaf)

        if (node != nullptr &&
            node->children[(int)word[0]-97] != nullptr &&
            deleteWord(node->children[(int)word[0]-97], word.substr(1)) &&
            node->isEndWord == false)
        {
            if (!anyChild(node))
            {
                delete node;
                node = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool Trie::searchWord(string word)
{
    {
        // return false if Trie is empty
        if (root == nullptr) {
            return false;
        }

        //                                             ben
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            // if the string is invalid (reached end of a path in the Trie)
            if (node->children[(int)word[i] - 97] == nullptr) {
                return false;
            }
            // go to the next node
            node = node->children[(int)word[i]-97];
            
        }

        // return true if the current node is a leaf and the
        // end of the string is reached
        return node->isEndWord;
    }
}

void Trie::PrintAllWordsFromPrefix(TrieNode*)
{
    
}

bool Trie::anyChild(TrieNode* node)
{
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            return true;
            break;
        }

    }
    return false;
}

bool Trie::searchWord(string word, TrieNode* node)
{
    {
        // return false if Trie is empty
        if (node == nullptr) {
            return false;
        }

        TrieNode* curr = node;
        for (int i = 0; i < word.length(); i++)
        {
            // go to the next node
            curr = curr->children[(int)word[i] - 97];
            // if the string is invalid (reached end of a path in the Trie)
            if (curr == nullptr) {
                return false;
            }
        }

        // return true if the current node is a leaf and the
        // end of the string is reached
        return curr->isEndWord;
    }
}
