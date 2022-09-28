#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Worker {
    int wage;
    int quality;
    double wage_divide_quality;
    Worker(int wage, int quality, double wage_divide_quality): wage(wage), quality(quality), wage_divide_quality(wage_divide_quality) {}
};

bool cmp(Worker &w1, Worker &w2) {
    return w1.wage_divide_quality < w2.wage_divide_quality;
};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<Worker> workers;
        for (int i = 0; i < wage.size(); i++) {
            workers.emplace_back(wage[i], quality[i], double(wage[i]) / quality[i]);
        }
        sort(workers.begin(), workers.end(), cmp);
        int sum = 0;
        priority_queue<int> quality_in_deseqence;
        for (int i = 0; i < k; i++) {
            quality_in_deseqence.push(workers[i].quality);
            sum += workers[i].quality;
        }
        double min = sum * workers[k - 1].wage_divide_quality;
        for (int i = k; i < workers.size(); i++) {
            if (workers[i].quality < quality_in_deseqence.top()) {
                sum -= quality_in_deseqence.top();
                quality_in_deseqence.pop();
                quality_in_deseqence.push(workers[i].quality);
                sum += workers[i].quality;
                double tmp_min = sum * workers[i].wage_divide_quality;
                if (tmp_min < min) {
                    min = tmp_min;
                }
            }
        }
        return min; 
    }
};

int main() {
    vector<int> q{10, 20, 5};
    vector<int> w{70, 50, 30};
    Solution *s = new Solution();
    s->mincostToHireWorkers(q, w, 2);
    return 0;
}