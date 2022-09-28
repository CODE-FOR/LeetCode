#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


class NumArray {
public:
    vector<int> segment_tree;
    int right_bound;

    int build(vector<int>& nums, int left, int right, int current_node_id) {
        if (left == right) {
            segment_tree[current_node_id - 1] = nums[left];
            return nums[left];
        }
        int mid = left + ((right - left) >> 1);
        int left_partition_sum = build(nums, left, mid, current_node_id << 1);
        int right_partiton_sum = build(nums, mid + 1, right, (current_node_id << 1) + 1);
        segment_tree[current_node_id - 1] = left_partition_sum + right_partiton_sum;
        return segment_tree[current_node_id - 1];
    }


    void update(int left, int right, int val, int index, int current_node_id) {
        if (left == right) {
            segment_tree[current_node_id - 1] = val;
            return;
        }
        int mid = left + ((right - left) >> 1);
        if (mid < index) {
            update(mid + 1, right, val, index, (current_node_id << 1) + 1);
        } else {
            update(left, mid, val, index, current_node_id << 1);
        }
        segment_tree[current_node_id - 1] = segment_tree[(current_node_id << 1) - 1] + segment_tree[(current_node_id << 1) ];
    }

    NumArray(vector<int>& nums) {
        segment_tree = vector<int>(nums.size() * 4);
        if (nums.empty()) {
            throw invalid_argument("received empty nums");
        }
        right_bound = nums.size() - 1;
        build(nums, 0, right_bound, 1);
    }
    
    void update(int index, int val) {
        update(0, right_bound, val, index, 1);
    }

    int sum_range(int search_left, int search_right, int left, int right, int current_node_id) {
        
        if (search_left <= left && search_right >= right) {
            return segment_tree[current_node_id - 1];
        }
        int mid = left + ((right - left) >> 1);
        int sum = 0;
        if (search_left <= mid) {
            sum += sum_range(search_left, search_right, left, mid, current_node_id << 1);
        }
        if (search_right > mid) {
            sum += sum_range(search_left, search_right, mid + 1, right, (current_node_id << 1) + 1);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        return sum_range(left, right, 0, right_bound, 1);
    }
};


int main() {
    vector<int> input = vector<int>({9, -8});
    NumArray* num_array = new NumArray(input);
    num_array->update(0, 3);
    int res = num_array->sumRange(1, 1);
    cout << res << endl;
    res = num_array->sumRange(0, 1);
    cout << res << endl;
    num_array->update(1, -3);
    res = num_array->sumRange(0, 1);
    cout << res << endl;
    return 0;
}