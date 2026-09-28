#include "../headers/trie.h"

void insert(TrieNode* root, const std::string& key) {
    TrieNode* curr = root;
    for(char c : key) {
        int ch_idx = (int) (c - 'a');
        if(curr -> children[ch_idx] == nullptr) {
            curr -> children[ch_idx] = std::make_unique<TrieNode>();
            curr -> childcount++;
        }
        curr = curr -> children[ch_idx].get();
    }
    curr -> isLeaf = true;
}