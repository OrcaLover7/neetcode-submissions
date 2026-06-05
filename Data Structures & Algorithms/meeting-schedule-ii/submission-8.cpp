/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){ return a.start < b.start; });

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(auto& interval : intervals){
            if(!min_heap.empty() && min_heap.top() <= interval.start) min_heap.pop();
            min_heap.push(interval.end);
        }

        return (int)min_heap.size();
    }
};
