#include "Combination.hpp"
#include <cassert>
#include <unordered_set>
// #include <iostream>
using namespace std;

#define TEST_MAX 10

int CombinationCount(int n, int m)
{
    int count = 1;
    for (int i = 1; i <= n; i++) {
        count *= i;
    }
    for (int i = 1; i <= m; i++) {
        count /= i;
    }
    for (int i = 1; i <= n-m; i++) {
        count /= i;
    }

    return count;
}

void AssertDifference(const vector<unordered_set<int>> & vs)
{
    for (int i = 0; i < vs.size(); i++)
        for (int j = i+1; j < vs.size(); j++) {
            assert( vs[i] != vs[j] );
        }
}


int main()
{
    int s[MAX];
    for (int i = 0; i < MAX; i++) {
        s[i] = i;
    }

    for (int n = 1; n < TEST_MAX; n++) {
        for (int m = 1; m <= n; m++) {

            vector<unordered_set<int>> result = Combination(s, n, m);
            int count = CombinationCount(n, m);
            // cout << "n: " << n << ", m: " << m << ", result.size: " << result.size() << ", count: " << count << endl;
            assert( result.size() == count );
            AssertDifference(result);
            for (int i = 0; i < result.size(); i++) {
                assert( result[i].size() == m );
            }
        }
    }

    return 0;
}