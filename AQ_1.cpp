#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;

    for (int num : nums)
    {
        if (seen.find(num) != seen.end())
        {
            return true; // Duplicate found
        }
        seen.insert(num);
    }

    return false; // No duplicates
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}
