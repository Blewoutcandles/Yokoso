#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>
#include <memory>

#define ALPHABET_COUNT  26

class TrieNode {
public:
    std::unique_ptr<TrieNode> children[ALPHABET_COUNT];
    bool isLeaf;
    int childcount;

    TrieNode() {
        isLeaf = false;
        for(int i = 0; i<ALPHABET_COUNT; i++) {
            children[i] = nullptr;
        }
        childcount = 0;
    }
};

void insert(TrieNode* root, const std::string& key);
#endif