#include"Trie.h"
#include<string>
#include<iostream>
using namespace std;

void Trie::insertWord(string word)
{

	TrieNode * node = this->root;
    for (int i = 0; i < word.length(); i++)
    {
        // create a new node if the path doesn't exist
        if (node->children[(word[i] - 97)] == nullptr) {
            node->children[(int)(word[i] - 97)] = new TrieNode();
        }
        // go to the next node
        TrieNode* temp = node;
        node = node->children[(int)(word[i] - 97)];
        node->father = temp;
    }
    node->isEndWord = true;
}

bool Trie::deleteWord(string word)
{
    TrieNode * node = root;
    if (searchWord(word)) {
        // go to the last node at this word
        for (int i = 0; i < word.length(); i++) {
            node = node->children[(int)(word[i] - 97)];
        }

        for (int i = word.length()-1; i >= 0; i--) {
            // if the end of word no have any child
            if (!(anyChild(node))) {
                node = node->father;
                node->children[(int)(word[i] - 97)] = nullptr;
            }
            if (node->isEndWord)
                node->isEndWord = false;
        }
        return true;
    }
    return false;
}

bool Trie::searchWord(string word)
{
    {
        // return false if Trie is empty
        if (root == nullptr) {
            return false;
        }

        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            // if the string is invalid 
            if (node->children[(int)word[i] - 97] == nullptr) {
                return false;
            }
            // go to the next node
            node = node->children[(int)word[i]-97];
            
        }

        // return true if the nodeent node is a leaf and the
        // end of the string is reached
        return node->isEndWord;
    }
}
void print(Trie::TrieNode * node, string str, int level) 
{    
    if (node->isEndWord)
    {
        cout << str << endl;
        int i = 0;
        for (; i < 26; i++) {
            if (node->children[i] != nullptr) 
                break;            
        }
        if (i == 26) //the node have no leaf
            str = "";
    }

    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            str += (char)(i + 97);
            print(node->children[i], str, level + 1);
           //after finish one word oprinting in reqursive return to the last char in str that have another children
            str = str.substr(0, level);

        }
    }
}
bool Trie::PrintAllWordsFromPrefix(string word)
{

   // chek if have this profix in tree
    TrieNode* node = nullptr;
    int i = 1;
    if (root->children[(int)(word[0] - 97)] != nullptr) {
        node = root->children[(int)(word[0]-97)];
        // check if the rest of word id exists
        for (; i < word.length(); i++) {
            if (node->children[(int)(word[i] - 97)] == nullptr)
                node = nullptr;
            else
                node = node->children[(int)(word[i] - 97)];

        }
    }
    
    if (node) {
        int level = i;
        word = word.substr(0,i);
        print(node, word,level);
        return true;
    }
    else
        return false;
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

bool Trie::searchWord(string word, TrieNode* root)
{
    {
        // return false if Trie is empty
        if (root == nullptr) {
            return false;
        }

        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            // go to the next node
            node = node->children[(int)word[i] - 97];
            // if the string is invalid
            if (node == nullptr) {
                return false;
            }
        }

        // return true if the nodeent node is a leaf and the
        // end of the string is reached
        return node->isEndWord;
    }
}
