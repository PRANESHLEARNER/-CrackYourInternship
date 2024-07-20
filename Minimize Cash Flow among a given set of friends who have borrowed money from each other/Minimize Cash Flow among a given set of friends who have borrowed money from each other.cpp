#include <iostream>
#include <queue>

using namespace std;

struct AscCmp {
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        return p1.second < p2.second;
    }
};


struct DscCmp {
    bool operator()(const pair<int, int>& p1,
                    const pair<int, int>& p2)
    {
        return p1.second > p2.second;
    }
};

class Solution {
private:
    
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   DscCmp>
        minQ;
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   AscCmp>
        maxQ;


    void constructMinMaxQ(const vector<int>& amount)
    {
        for (int i = 0; i < amount.size(); ++i) {
            if (amount[i] == 0)
                continue;
            if (amount[i] > 0) {
                maxQ.emplace(i, amount[i]);
            }
            else {
                minQ.emplace(i, amount[i]);
            }
        }
    }

    void solveTransaction()
    {
        while (!minQ.empty() && !maxQ.empty()) {
            pair<int, int> maxCreditEntry = maxQ.top();
            maxQ.pop();

            pair<int, int> maxDebitEntry = minQ.top();
            minQ.pop();

            // Get the remaining transaction value by adding
            // credit and debit cash
            int transaction_val = maxCreditEntry.second
                                  + maxDebitEntry.second;

            int debtor = maxDebitEntry.first,
                creditor = maxCreditEntry.first,
                owed_amount = 0;

            if (transaction_val == 0) {
                // credit and debit cash for this person is
                // cancelled out
                owed_amount = maxCreditEntry.second;
            }
            else if (transaction_val < 0) {
                // transaction_val is the debit cash which
                // is remaining, so push to the queue for
                // further processing
                owed_amount = maxCreditEntry.second;
                minQ.emplace(maxDebitEntry.first,
                             transaction_val);
            }
            else {
                // transaction_val is the credit cash which
                // is remaining, so push to the queue for
                // further processing
                owed_amount = -(maxDebitEntry.second);
                maxQ.emplace(maxCreditEntry.first,
                             transaction_val);
            }

            // Print result
            cout << "Person " << debtor << " pays "
                 << owed_amount << " to Person " << creditor
                 << endl;
        }
    }

public:
    void minCashFlow(const vector<vector<int> >& graph)
    {
        int n = graph.size();

        // Calculate the cash to be credited/debited to/from
        // each person and store in vector amount
        vector<int> amount(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = graph[j][i] - graph[i][j];
                amount[i] += diff;
            }
        }

        // Fill in both queues minQ and maxQ using amount
        // vector
        constructMinMaxQ(amount);

        // Solve the transaction using minQ, maxQ and amount
        // vector
        solveTransaction();
    }
};

int main()
{
    // Test case 1
    vector<vector<int> > graph = {
        { 0, 1000, 2000 },
        { 0, 0, 5000 },
        { 0, 0, 0 },
    };

    cout << "Solution 1 : " << endl;
    Solution S;
    S.minCashFlow(graph);

    // Test case 2
    vector<vector<int> > graph2 = { { 2, 63, 0, 85, 49 },
                                    { 0, 76, 0, 0, 27 },
                                    { 0, 0, 0, 17, 0 },
                                    { 73, 32, 50, 6, 71 },
                                    { 0, 86, 0, 0, 10 }

    };

    cout << "Solution 2 : " << endl;
    Solution S2;
    S2.minCashFlow(graph2);
    return 0;
}
