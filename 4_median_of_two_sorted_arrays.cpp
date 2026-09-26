#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::less;
using std::swap;
using std::max;
using std::min;

#define METHOD          1
#define BINARY_SEARCH   METHOD
#define PRIORITY_QUEUE  !METHOD

#if PRIORITY_QUEUE
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
#endif

#if BINARY_SEARCH
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();

    if(m > n) {
        return findMedianSortedArrays(b, a);
    }

    bool odd = (m+n)%2 != 0;
    const int left_half = (m + n + 1)/2; //ignore the right half
    double median_sum = 0.0;
    int low = 0, high = m;

    while(low <= high) {
        int consider_element_from_a = (low + high)/2; //consider element for left half from a
        int consider_element_from_b = left_half - consider_element_from_a; //consider element for left half
        //from b

        int a_left = consider_element_from_a == 0? INT_MIN : a[consider_element_from_a-1];
        int a_right = consider_element_from_a == m? INT_MAX : a[consider_element_from_a];
        int b_left = consider_element_from_b == 0? INT_MIN: b[consider_element_from_b-1];
        int b_right = consider_element_from_b == n? INT_MAX : b[consider_element_from_b];

        if(a_left <= b_right && b_left <= a_right) {
            if (odd) {
                return (double) max(a_left, b_left);
            }else{
                return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
            }
        }
        if(b_left > a_right) {
            low = consider_element_from_a + 1;
        }
        else if(a_left > b_right) {
            high = consider_element_from_a - 1;
        }
    }
    return median_sum;
}
#endif

int main() {
    vector<int> n1 {1,2}, n2 {3,4};
    cout << "The median of the sorted array: " << findMedianSortedArrays(n1, n2) << endl;
}