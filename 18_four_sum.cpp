#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::max;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    const int size = nums.size();
    vector<vector<int>> result;

    for(int i = 0; i<size-3; i++) {
        if(nums[i] > 0 && nums[i] > target) { break; }

        if(i > 0 && nums[i] == nums[i-1]) { continue; }
        bool firstrun = true;
        for(int j = i+1; j<size-2; j++) {
            if(!firstrun && j > 1 && nums[j] == nums[j-1]) { continue; }

            long long firsthalfsum = nums[i] + nums[j];
            if (firsthalfsum > 0 && firsthalfsum > target) { break; }

            int left = j+1, right = size-1;
            while(left < right) {
                long long sum = firsthalfsum + nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    while(left < right && nums[left] == nums[left+1]) { left++; }
                    while(left < right && nums[right] == nums[right-1]) { right--; }

                    left++;
                    right--;
                }else if (sum > target) {
                    while(left < right && nums[right] == nums[right-1]) { right--; }
                    right--;
                }else {
                    while(left < right && nums[left] == nums[left+1]) { left++; }
                    left++;
                }
            }
            firstrun = false;
        }
    }
    return result;
}

void solve_and_print(const vector<vector<int>> &result, const vector<int>& target) {
    int index = 0;
    for (auto i : result) {
        cout << "Test Case : ";
        vector<vector<int>> ans = fourSum(i, target[index++]);
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n\n";
        cout << "Answer: \n";
        for(auto t: ans) {
            cout << "[";
            for (auto m : t) {
                cout << m << ",";
            }
            cout << "\b \b" << "]" <<"\n\n";
        }
    }
}

int main() {
    vector<vector<int>> test_cases {
        {1,0,-1,0,-2,2}, 
        {2,2,2,2,2},
        {-1000000000,-1000000000,1000000000,-1000000000,-1000000000},
        {1,-2,-5,-4,-3,3,3,5},
        {-2,-1,-1,1,1,2,2}
    };
    vector<int> target {0, 8, 294967296, -11, 0};
    solve_and_print(test_cases, target);
    return 0;
}