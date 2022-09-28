#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int non_overlapping_size = n - k;
        for (int i = 0; i < non_overlapping_size; i++) {
            ans.push_back(i + 1);
        }
        for (int i = 0; i < k; i++) {
            if (i % 2) {
                ans.push_back(n - k + (i + 1) / 2);
            } else {
                ans.push_back(n - i / 2);
            }
        }
        return ans;
    }
};


int main() {
    Solution *s = new Solution();
    vector<int> ans = s->constructArray(6, 2);
    for (int num : ans) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}