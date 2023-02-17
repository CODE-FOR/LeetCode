#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedInteger {
private:
    int integer_value;
    vector<NestedInteger> vector_value;
    bool is_integer;

public:
    bool isInteger() {
        return is_integer;
    }

    int getInteger() {
        return integer_value;
    }

    vector<NestedInteger> getList() {
        return vector_value;
    }
};


class NestedIterator {

private:
    int position = 0;
    vector<int> flattened_list;

public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList) {
        for (auto &item : nestedList) {
            if (item.isInteger()) {
                flattened_list.push_back(item.getInteger());
            } else {
                vector<NestedInteger> tmp = item.getList();
                flatten(tmp);
            }
        }
    }
    
    int next() {
        return flattened_list[position++];
    }
    
    bool hasNext() {
        if (position < flattened_list.size()) {
            return true;
        }
        return false;
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
