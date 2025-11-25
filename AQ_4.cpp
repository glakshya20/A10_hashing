#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(vector<int> &nums)
{
    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : nums)
    {
        freq[num]++;
    }

    // Find the first element with frequency 1
    for (int num : nums)
    {
        if (freq[num] == 1)
            return num;
    }

    return -1; // if no unique element exists
}

int main()
{
    vector<int> nums = {4, 5, 1, 2, 0, 4};

    int result = firstNonRepeating(nums);

    cout << result;
    return 0;
}
