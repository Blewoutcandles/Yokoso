#include <bits/stdc++.h>
using std::vector;
using std::unordered_map;
using std::cout;
using std::endl;
using std::max;

#define METHOD_EN   0
#define TWO_PASS    METHOD_EN
#define SINGLE_PASS !METHOD_EN

int trap(vector<int>& height) {
    int water = 0;
    const int size = height.size();
#if TWO_PASS
    vector<int> leftmaxbuilding(size, 0); //buildings at left with maximum height
    int leftmax = 0;
    //Find out the left side with maximum height at each index
    for(int left = 0; left<size; left++) {
        leftmax = max(leftmax, height[left]);
        leftmaxbuilding[left] = leftmax;
    }

    vector<int> rightmaxbuilding(size, 0);//buildings at left with maximum height
    int rightmax = 0;
    //Find out the right side with maximum height at each index
    for(int right = size-1; right>=0; right--) {
        rightmax = max(rightmax, height[right]);
        rightmaxbuilding[right] = rightmax;
    }

    //at each index now, fetch leftmaxbuilding, rightmaxbuilding: to represent the relationship:
    //leftmaxbuilding - current_building - rightmaxbuilding
    //and calculate the water trapped at each index as :
    //min(leftmaxbuilding, rightmaxbuilding) - current_building_height = water trapped
    //add all the water trapped at each index to get the final result
    for(int i = 0; i<size; i++) {
        water += (std::min(leftmaxbuilding[i], rightmaxbuilding[i])-height[i]);
    }
#endif
#if SINGLE_PASS
    int left = 0, right = size-1;
    int leftmax = 0, rightmax = 0;

    while(left < right) {
        if(height[left] <= height[right]) {
            leftmax = max (leftmax, height[left]);
            water += (leftmax - height[left]);
            left++;
        }else {
            rightmax = max (rightmax, height[right]);
            water += (rightmax - height[right]);
            right--;
        }
    }
#endif

    return water;
}

void solve_and_print(const vector<vector<int>> &result) {
    for (auto i : result) {
        cout << "Test Case : ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "\n\n"  << trap(i)<< " is the answer" << "\n\n";
    }
}

int main() {
    vector<vector<int>> test_cases {
        {0,1,0,2,1,0,1,3,2,1,2,1}, 
        {4,2,0,3,2,5}
    };
    
    solve_and_print(test_cases);
    return 0;
}