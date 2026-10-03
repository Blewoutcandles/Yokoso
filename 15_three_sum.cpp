#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;

#define METHOD_EN   1
#define TWO_POINTER METHOD_EN

vector<vector<int>> threeSum(vector<int>& nums) {
    const int size = nums.size();
    sort(nums.begin(), nums.end()); //time complexity: O(nlogn)
    vector<vector<int>> result;
#if TWO_POINTER
    for (int i = 0; i<size; i++) {
        //achieveable target = 0, if first number: positive -> no result
        if(nums[i] > 0) {
            break;
        }

        //if two successive numbers are same skip
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        //fix one number here: then do two pointer approach
        int left = i+1;
        int right = size-1;

        while(left < right) {
            int target = nums[i] + nums[left] + nums[right];

            if(target == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                //increment left, decrement right since keeping left as it is
                //will make target negative and keeping right as it is
                //will make target positive. Doing thus is mandatory, which also 
                //adds to the fact to have distinct sets of values.
                while(left < right && nums[left] == nums[left+1]) {
                    //skip the same element
                    left++;
                }
                while(right > left && nums[right] == nums[right-1]) {
                    //skip the same element
                    right--;
                }
                left++;
                right--;
                continue;
            }

            //if the target is negative, increase left
            if(target < 0) {
                while(left < right && nums[left] == nums[left+1]) {
                    //skip the same element
                    left++;
                }
                left++;
            }
            if(target > 0) {
                while(right > left && nums[right] == nums[right-1]) {
                    //skip the same element
                    right--;
                }
                //if the target is positive, reduce right 
                right--;
            }
        }
    }
#endif
    return result;
}

void print_result(const vector<vector<int>> &result) {
    for (auto i : result) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> test_cases {
        {-1,0,1,2,-1,-4}, 
        {1,1,0}, 
        {0,0,0}, 
        {0,0,0,0}, 
        {1,1,-2}
    };
    for(auto nums : test_cases) {
        vector<vector<int>> result = threeSum(nums);
        print_result(result);
    }
    return 0;
}

/*
-4,-1,-1,0,1,2
-4 -1 2 = -3
skip left -1, now left = 0
right no same element, so right is still 2
-4 0 2 = -2
target < 0, left++
*/