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
        vector<int> start_times, end_times;
        int n = (int)intervals.size();

        for(auto& interval : intervals){
            start_times.push_back(interval.start);
            end_times.push_back(interval.end);
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int s = 0, e = 0;

        int count = 0, ans = 0;

        while(s < n && e < n){
            if(start_times[s] < end_times[e]) {
                count++;
                s++;
            }
            else{
                e++;
                count--;
            }

            ans = max(count, ans);
        }

        return ans;
    }
};
