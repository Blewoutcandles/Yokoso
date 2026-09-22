#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::less;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    priority_queue<int, vector<int>, less<int>> pq;

    for(int i : nums1) {
        pq.push(i);
    }
    for(int i: nums2) {
        pq.push(i);
    }
    //time complexity of pushing elements to pq is log n
    //for m+n elements from both the array = O((m+n) log(m+n))
    if(pq.empty()) return 0.0;
    int size = size1 + size2;
    bool even = size%2 == 0;
    int median = even? size/2 - 1: size/2;

    while(median--) {
        pq.pop();
    }
    return even? static_cast<double> (pq.top() + (pq.pop(), pq.top()))/2 : pq.top();
    
}

int main() {
    vector<int> n1 {1,2,3}, n2 {4,5};
    cout << "The median of the sorted array: " << findMedianSortedArrays(n1, n2) << endl;
}