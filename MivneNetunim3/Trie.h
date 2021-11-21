#pragma once
#include<string>
class Trie {
protected:
	class TrieNode {
	public:
		TrieNode* children[? ? ? ] = { 0 };
		TrieNode* father;
		bool isEndWord = false;
	};
public:
	Tire() {}

	void insertWord(string word);
	void deleteWord(string word);
	bool searchWord(string word);
	void PrintAllWordsFromPrefix(TrieNode *);

private:
	bool searchWord(string word, TrieNode* node);
};