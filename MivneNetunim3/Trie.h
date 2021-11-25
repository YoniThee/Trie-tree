#pragma once
#include<string>
class Trie {
protected:
	class TrieNode {
	public:
		TrieNode* children[26] = { 0 };
		TrieNode* father;
		bool isEndWord = false;
		char ch;
	};
public:
	Trie()
	{
		for (int i = 0; i < 26; i++) {
			this->root->children[i] = nullptr;
		}
	}

	TrieNode * root;

	void insertWord(string word);
	void deleteWord(string word);
	bool searchWord(string word);
	void PrintAllWordsFromPrefix(TrieNode *);

private:
	bool searchWord(string word, TrieNode* node);
};