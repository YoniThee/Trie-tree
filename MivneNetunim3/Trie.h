#pragma once
#include<string>
using namespace std;
class Trie {
protected:
	class TrieNode {
	public:
		TrieNode* children[26] = { 0 };
		TrieNode* father;
		bool isEndWord = false;
		char ch;

		TrieNode()
		{
			children[26] = { 0 };
			
		}

	};
public:
	Trie()
	{
		root = new TrieNode();
		for (int i = 0; i < 26; i++) {
			this->root->children[i] = nullptr;
		}
	}



	TrieNode * root;
	void insertWord(string word);
	bool deleteWord(TrieNode* node, string word);
	bool searchWord(string word);
	void PrintAllWordsFromPrefix(TrieNode *);
	bool anyChild(TrieNode* node);

private:
	bool searchWord(string word, TrieNode* node);
};