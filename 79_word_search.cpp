#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::max;
using std::string;

#define DIRS    4
#define UP      -1
#define DOWN    1
#define LEFT    -1
#define RIGHT   1

const int dir[4] = {UP, DOWN, LEFT, RIGHT};
int rowsize, colsize;

bool dfs(vector<vector<char>>& board, 
    int rowidx, 
    int colidx, 
    string word, 
    int wrdidx) {
    
    if(wrdidx == (int)word.size()) { return true; }
    
    if(rowidx < 0 || colidx < 0 || rowidx >= rowsize || colidx >= colsize) {
        return false;
    }
    if(board[rowidx][colidx] == '#') { return false; }
    if(board[rowidx][colidx] != word[wrdidx]) { return false; }
    char temp = board[rowidx][colidx];
    board[rowidx][colidx] = '#';

    bool ans = dfs(board, rowidx + UP, colidx, word, wrdidx+1) || 
        dfs(board, rowidx + DOWN, colidx, word, wrdidx+1) || 
        dfs(board, rowidx, colidx + LEFT, word, wrdidx+1) || 
        dfs(board, rowidx, colidx + RIGHT, word, wrdidx+1);

    board[rowidx][colidx] = temp;
    return ans;
}

bool exist(vector<vector<char>>& board, string word) {
    rowsize = board.size(), colsize = board[0].size();

    for(int i = 0; i<rowsize; i++) {
        for(int j = 0; j<colsize; j++) {
            if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}

void solve_and_print(const vector<vector<vector<char>>> &result, 
        vector<string>& word) {
    
    int index = 0;

    for (auto i : result) {
        cout << "Test Case : ";
        for (auto j : i) {
            cout << "[";
            for (auto m : j) {
                cout << m << ",";
            }
            cout << "\b \b";
            cout <<"], ";
        }
        cout << "\b \b";
        cout << "\n\n"  << std::boolalpha << exist(i, word[index++])<< " is the answer" << "\n\n";
    }
}

int main() {
    vector<vector<vector<char>>> question = {
        {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},

    };
    vector<string> word {"ABCCED"};
    solve_and_print(question, word);
    return 0;
}