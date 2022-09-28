#include <iostream>
#include <vector>

using namespace std;


struct Hlevel {
    long long top;
    long long bottom;

    Hlevel(long long top, long long bottom): top(top), bottom(bottom) {}
};


struct Area {
    long long left;
    long long right;
    vector<Hlevel> hs;

    Area(int left, int right, vector<Hlevel> hs): left(left), right(right), hs(hs) {}

    // string to_str() {
    //     return to_string(left) + " " + to_string(right) + " " + to_string(top) + " " + to_string(bottom);
    // }
};

bool need_insert(vector<Hlevel> hs, long long top, long long bottom) {
    for (int i = 0; i + 1 < hs.size(); i++) {
        if (bottom < hs[i + 1].bottom && top > hs[i].top) {
            i++;
            return true;
        }
    }
    return false;
}

vector<Hlevel> do_insert(vector<Hlevel> hs, long long top, long long bottom) {
    for (int i = 0; i + 1 < hs.size(); i++) {
        if (bottom < hs[i + 1].bottom && top > hs[i].top) {
            long long insert_bottom = max(bottom, hs[i].top);
            long long insert_top = min(top, hs[i + 1].bottom);
            i++;
            hs.insert(hs.begin() + i, Hlevel(insert_top, insert_bottom));
        }
    }
    return hs;
}


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<Area> areas;
        vector<Hlevel> hs_origin;
        hs_origin.push_back(Hlevel(0, 0));
        hs_origin.push_back(Hlevel(1000000001, 1000000001));
        areas.push_back(Area(0, 0, hs_origin));
        areas.push_back(Area(1000000001, 1000000001, hs_origin));
        int num = 0;
        cout << rectangles.size() << endl;
        for (auto &rectangle : rectangles) {
            cout << "next:" + to_string(num) << endl;
            num++;
            long long left = rectangle[0];
            long long right = rectangle[2];
            long long bottom = rectangle[1];
            long long top = rectangle[3];
            if (num == 42) {
                int a =1;
            }
            for (int i = 0; i < areas.size(); i++) {
                cout << i << endl;
                if (areas[i].left >= right) {
                    break;
                }
                if (areas[i].right <= left) {
                    continue;
                }
                if (areas[i].left >= left && areas[i].right <= right) {
                    areas[i].hs = do_insert(areas[i].hs, top, bottom);
                }
                else if (areas[i].left >= left && areas[i].right >= right) {
                    if (need_insert(areas[i].hs, top, bottom)) {
                        areas.insert(areas.begin() + i, Area(areas[i].left, right, do_insert(areas[i].hs, top, bottom)));
                        i++;
                        areas[i].left = right;
                    }
                }
                else if (areas[i].left <= left && areas[i].right <= right) {
                    if (need_insert(areas[i].hs, top, bottom)) {
                        long long tmp_right = areas[i].right;
                        areas[i].right = left;
                        i++;
                        areas.insert(areas.begin() + i, Area(left, tmp_right, do_insert(areas[i - 1].hs, top, bottom)));
                    }
                }
                else if (areas[i].left <= left && areas[i].right >= right) {
                    if (need_insert(areas[i].hs, top, bottom)) {
                        long long tmp_right = areas[i].right;
                        areas[i].right = left;
                        i++;
                        areas.insert(areas.begin() + i, Area(left, right, do_insert(areas[i - 1].hs, top, bottom)));
                        i++;
                        areas.insert(areas.begin() + i, Area(right, tmp_right, areas[i - 2].hs));
                    }
                }
            }
            for (int i = 0; i + 1 < areas.size(); i++) {
                if (left < areas[i + 1].left && right > areas[i].right) {
                    long long insert_left = max(left, areas[i].right);
                    long long insert_right = min(right, areas[i + 1].left);
                    i++;
                    areas.insert(areas.begin() + i, Area(insert_left, insert_right, do_insert(hs_origin, top, bottom)));
                }
            }
        }
        long long area_sum = 0;
        long long mod_num = 1000000007;
        for (int i = 0; i < areas.size(); i++) {
            cout << i << endl;
            // cout << areas[i].to_str() << endl;
            long long h_sum = 0;
            for (int j = 0; j < areas[i].hs.size(); j++) {
                h_sum += areas[i].hs[j].top - areas[i].hs[j].bottom;
            }
            area_sum += (areas[i].right - areas[i].left) * h_sum % mod_num;
            area_sum %= mod_num;
        }
        return area_sum;
    }
};

int main() {
    Solution *s = new Solution();
    vector<vector<int>> t = vector<vector<int>>({{471,0,947,999},{780,0,823,320},{868,0,948,538},{907,0,911,673},{929,0,952,596},{458,0,889,669},{156,0,364,754},{900,0,973,236},{406,0,620,454},{773,0,946,538},{407,0,834,23},{759,0,858,526},{431,0,776,599},{969,0,979,30},{642,0,737,339},{239,0,448,183},{260,0,517,903},{14,0,674,976},{251,0,850,112},{57,0,794,395},{595,0,728,149},{970,0,989,36},{496,0,954,791},{447,0,832,805},{829,0,939,100},{169,0,568,501},{704,0,969,411},{607,0,609,221},{935,0,953,437},{47,0,670,130},{794,0,799,230},{943,0,959,90},{332,0,337,732},{123,0,228,344},{281,0,487,598},{381,0,732,443},{235,0,391,548},{646,0,930,20},{219,0,675,95},{8,0,212,227},{138,0,704,658},{368,0,782,707},{810,0,826,957},{543,0,697,654},{887,0,986,180},{837,0,900,228},{280,0,391,331},{180,0,229,42},{201,0,489,687},{648,0,680,732},{228,0,630,922},{886,0,960,56},{946,0,955,522},{903,0,992,464},{557,0,860,38},{89,0,268,642},{669,0,774,185},{1,0,724,374},{395,0,923,782},{82,0,230,550},{166,0,166,808},{441,0,644,435},{497,0,823,224},{372,0,973,556},{188,0,846,127},{226,0,396,535},{869,0,945,575},{406,0,526,795},{781,0,795,569},{563,0,831,991},{466,0,486,641},{274,0,855,529},{61,0,819,364},{285,0,421,101},{193,0,950,748},{320,0,655,836},{207,0,627,945},{782,0,899,56},{578,0,970,913},{499,0,684,205},{490,0,877,16},{483,0,668,915},{364,0,741,16}});
    s->rectangleArea(t);
}