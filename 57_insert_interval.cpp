#include <bits/stdc++.h>
using std::vector;
using std::cout;
using std::endl;
using std::swap;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int updatedintervalstart = newInterval[0], updatedintervalend = newInterval[1];
    int i = 0;
    for(; i<intervals.size(); i++) {

        //if the current interval endtime is less than the start of the new interval
        //store in result and continue with the next one.
        if(intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            continue;      
        }
        //if the new updated interval end time is less than the start of the current interval
        //push the updatedinterval -> start and end time to result and push the rest of the 
        //vector elements of interval to result and return.
        if(updatedintervalend < intervals[i][0]){
            break;
        }

        //As we go along the intervals keep track of the minimum interval, maximum interval 
        //Once completed push the updatedinterval -> start and end time to result and return the 
        //result
        updatedintervalstart = updatedintervalstart >= intervals[i][0] ? intervals[i][0] : updatedintervalstart;
        updatedintervalend = updatedintervalend <= intervals[i][1] ? intervals[i][1] : updatedintervalend;
        
    }
    result.push_back({updatedintervalstart, updatedintervalend});
    while(i < intervals.size()) {
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

int main() {
    vector<vector<int>> question = {{1,2},{3,5},{8,10}};
    vector<int> newInterval = {2,9};
    vector<vector<int>> ans = insert(question, newInterval);
    for(auto i : ans) {
        cout << i[0] << "," << i[1] << endl;
    }
    question = {{1,3},{6,9}};
    newInterval = {2,5};
    ans = insert(question, newInterval);
    for(auto i : ans) {
        cout << i[0] << "," << i[1] << endl;
    }
    question = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    ans = insert(question, newInterval);
    for(auto i : ans) {
        cout << i[0] << "," << i[1] << endl;
    }
    return 0;
}
/*
Current:Array/Two Pointers
Suggested:Array/Two Pointers
Key Idea:Merging overlapping intervals efficiently using linear traversal.
Consider:How would you handle this problem if the input intervals were unsorted?
Current complexity:
O(N)
Suggested complexity:
O(N)
Suggestions:Your time and space complexities are optimal. Great job!
*/