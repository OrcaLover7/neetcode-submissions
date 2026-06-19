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
        vector<int> starts, ends;
        int n = (int)intervals.size();
        
        for(auto& interval : intervals){
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int s = 0, e = 0;

        int count = 0, ans = 0;

        while(s < n and e < n){
            if(starts[s] < ends[e]){
                s++;
                count++;
            }
            else{
                e++;
                count--;
            }

            ans = max(ans, count);
        }

        return ans;

    }
};
