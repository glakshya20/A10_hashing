#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findCommon(vector<int> &A, vector<int> &B)
{
    unordered_set<int> setA(A.begin(), A.end());
    vector<int> result;

    for (int num : B)
    {
        if (setA.find(num) != setA.end())
        {
            result.push_back(num);
        }
    }

    return result;
}

int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    vector<int> common = findCommon(A, B);

    for (int num : common)
        cout << num << " ";

    return 0;
}
