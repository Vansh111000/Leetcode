/*
 * @lc app=leetcode id=3753 lang=cpp
 *
 * [3753] Total Waviness of Numbers in Range II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    typedef long long ll;
    string s;
    int n;
    vector<vector<vector<ll>>> dpn;
    vector<vector<vector<ll>>> dpw;

    pair<ll, ll> solve(int curr, int prevPrev, int prev,
                       bool isLimitedWithActualNumber, bool isLeadingZeros)
    {
        if (curr == n)
        {
            return {1, 0}; // no more score can be generated and we found one
                           // last number
        }

        if (!isLimitedWithActualNumber && !isLeadingZeros && prevPrev >= 0 && prev >= 0)
        {
            if (dpn[curr][prevPrev][prev] != -1 and dpw[curr][prevPrev][prev] != -1)
            {
                return {
                    dpn[curr][prevPrev][prev],
                    dpw[curr][prevPrev][prev]};
            }
        }
        ll totalNumbers = 0;
        ll totalWaveScore = 0;
        int limitDigit = (isLimitedWithActualNumber) ? (s[curr] - '0') : 9;

        for (int i = 0; i <= limitDigit; i++)
        {
            bool newIsLeadingZeros = (isLeadingZeros && i == 0);

            int newPrevPrev = prev;
            int newPrev = newIsLeadingZeros ? -1 : i;

            auto [remainTotalNumbers, remainTotalWaveScore] =
                solve(curr + 1, newPrevPrev, newPrev,
                      isLimitedWithActualNumber && i == limitDigit,
                      newIsLeadingZeros);

            if (!newIsLeadingZeros && prevPrev >= 0 && prev >= 0)
            {
                bool isPeak = (prevPrev < prev and prev > i),
                     isValley = (prevPrev > prev and prev < i);
                if (isPeak or isValley)
                {
                    totalWaveScore += remainTotalNumbers;
                }
            }

            totalNumbers += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!isLimitedWithActualNumber && !isLeadingZeros && prevPrev >= 0 && prev >= 0)
        {
            dpn[curr][prevPrev][prev] = totalNumbers;
            dpw[curr][prevPrev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }
    ll func(ll num)
    {
        if (num < 100)
        {
            return 0;
        }
        s = to_string(num);
        n = s.length();

        // dpn.resize(n,vector<vector<int>>(11,vector<int>(11,0)));
        // dpw.resize(n,vector<vector<int>>(11,vector<int>(11,0)));

        dpn.assign(n, vector<vector<long long>>(11, vector<long long>(11, -1)));
        dpw.assign(n, vector<vector<long long>>(11, vector<long long>(11, -1)));

        auto [totalNumbers, totalWaveScore] = solve(0, -1, -1, true, true);
        return totalWaveScore;
    }
    long long totalWaviness(long long num1, long long num2)
    {
        return func(num2) - func(num1 - 1);
    }
};
// @lc code=end

