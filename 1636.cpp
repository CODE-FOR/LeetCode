#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;



struct NumAlongWithItsFrequency {
    int num;
    int freq;
    NumAlongWithItsFrequency(int num, int freq) : num(num), freq(freq) {};
};

bool compare_num_along_with_its_frequency (NumAlongWithItsFrequency &n1, NumAlongWithItsFrequency &n2) {
    return n1.freq == n2.freq ? (n1.num > n2.num) : (n1.freq < n2.freq);
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> num_and_freqs;
        for (int num : nums) {
            if (num_and_freqs.find(num) == num_and_freqs.end()) {
                num_and_freqs[num] = 0;
            }
            num_and_freqs[num] += 1;
        }
        vector<NumAlongWithItsFrequency> num_along_with_its_frequenctys;
        for (auto &num_and_freq : num_and_freqs) {
            num_along_with_its_frequenctys.emplace_back(num_and_freq.first, num_and_freq.second);
        }
        sort(num_along_with_its_frequenctys.begin(), num_along_with_its_frequenctys.end(), compare_num_along_with_its_frequency);
        for (auto &num_and_freq : num_along_with_its_frequenctys) {
            for (int i = 0; i < num_and_freq.freq; i++) {
                res.push_back(num_and_freq.num);
            }
        }
        return res;
    }
};