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
        map<int, int> mp;
        int ans = -1;

        for(auto& interval : intervals){
            mp[interval.start]++;
            mp[interval.end]--;
        }

        int prev = 0, res = 0;

        for(auto& [time, count] : mp){
            prev += count;
            res = max(res, prev);
        }

        return res;

    }
};
