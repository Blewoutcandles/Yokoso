#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    int size = nums.size();

    for(int i = 0; i<size; i++) {
        int second = target - nums[i];
        if(mp.find(second) != mp.end()) {
            return {mp[second], i};
        }else {
            mp[nums[i]] = i;
        }
    }
    return vector<int>();
}

int main() {
    vector<int> result = twoSum(vector<int>{3,3}, 6);
    for(int i : result) {
        cout << i << "-";
    }
    cout << "\b \b" << endl;
    return 0;
}