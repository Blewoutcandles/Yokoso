#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include "headers/trie.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

#define METHOD_ENABLE   1
#define TRIE_METHOD     !METHOD_ENABLE
#define SIMPLE          METHOD_ENABLE
#if TRIE_METHOD
void build_until_deviates(TrieNode* root, string& formed, int min_len) {
    if(!root || !min_len || root -> childcount == 0 || root -> childcount > 1) {
        return;
    }
    int nextchild = -1;
    for(int i = 0; i<ALPHABET_COUNT; i++) {
        if(root -> children[i]){
            nextchild = i;
            break;
        }
    }

    formed.push_back(static_cast<char>('a' + nextchild));
    build_until_deviates(root -> children[nextchild].get(), formed, --min_len);
}

string longestCommonPrefix(vector<string>& strs) {
    TrieNode root;
    int min_len = INT_MAX;
    for(string str : strs) {
        insert(&root, str);
        min_len = std::min(min_len, (int)str.size());
    }
    string result;
    //build the string until the TrieNode branch deviates
    build_until_deviates(&root, result, min_len);
    return result;
}
#endif

#if SIMPLE
string longestCommonPrefix(vector<string>& strs) {
    int size = strs.size();
    if(size == 1) {
        return strs[0];
    }
    std::sort(strs.begin(), strs.end());
    int minlen = std::min((int)strs[0].size(), (int)strs[size-1].size());
    string result;
    for(int i = 0; i<minlen; i++) {
        if(strs[0][i] != strs[size-1][i]) {
            break;
        }
        result += strs[0][i];
    }
    return result;
}
#endif

template<class T>
void print_vector(const vector<T>& p) {
    for(auto i: p) {
        cout << i << ",";
    }
    cout << "\b \b" << endl;
}

int main() {
    vector<string> pass {"flower", "flow", "flight"};
    cout << "CASE#1 : ";
    print_vector(pass);
    cout << longestCommonPrefix(pass) << endl;
    pass = {"dog","racecar","car"};
    cout << "CASE#2 : ";
    print_vector(pass);
    cout << longestCommonPrefix(pass) << endl;
    pass = {"ab", "a"};
    cout << "CASE#3 : ";
    print_vector(pass);
    cout << longestCommonPrefix(pass) << endl;
    return 0;
}