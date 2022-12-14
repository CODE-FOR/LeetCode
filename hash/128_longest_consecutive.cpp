#include <vector>
#include <unordered_set>

using std::min;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (const int &num : nums)
        {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int &num : num_set)
        {
            if (!num_set.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1))
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = longestStreak + currentStreak - min(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
