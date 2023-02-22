#include <vector>

using std::vector;

#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int l = newInterval[0];
        int r = newInterval[1];
        vector<vector<int>> new_intervals;
        int i = 0;
        bool inserted = false;
        while(i < intervals.size()) {
            auto &interval = intervals[i];
            if (interval[1] < l) {
                new_intervals.push_back(interval);
                i++;
                continue;
            }
            if (interval[0] > r) {
                newInterval[0] = l;
                newInterval[1] = r;
                new_intervals.push_back(newInterval);
                inserted = true;
                while (i < intervals.size()) {
                    new_intervals.push_back(intervals[i]);
                    i++;
                }
                break;
            }
            l = min(l, interval[0]);
            r = max(r, interval[1]);
            i++;
        }
        if (!inserted) {
            newInterval[0] = l;
            newInterval[1] = r;
            new_intervals.push_back(newInterval);
        }
        return new_intervals;
    }
};