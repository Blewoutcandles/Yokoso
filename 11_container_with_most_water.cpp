#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::max;
using std::min;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int maxarea = 0;
    while(left < right) {
        maxarea = max(maxarea, min(height[right], height[left])*(right-left));
        if(height[left] < height[right]) {
            left++;
        }else if (height[left] == height[right]) {
            left++;
            right--;
        }else {
            right--;
        }
    }
    return maxarea;
}

int main() {
    vector<int> height {1,8,6,2,5,4,8,3,7};
    cout << "The container with most water: " << maxArea(height) << endl;
    height = {1,1};
    cout << "The container with most water: " << maxArea(height) << endl;
    return 0;
}