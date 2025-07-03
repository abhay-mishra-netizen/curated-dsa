class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 'total' keeps track of net gas left after completing the circuit
        // 'curr' is the gas left in the tank while trying to go from 'start' to i
        // 'start' stores the index where we attempt to start the journey
        int total = 0, curr = 0, start = 0;
        int n = gas.size();

        // Iterate through all stations
        for (int i = 0; i < n; ++i) {
            // Calculate the net gain/loss of gas at this station
            int gain = gas[i] - cost[i];

            // Update total gas balance and current gas balance
            total += gain;
            curr += gain;

            // If current gas becomes negative, we cannot reach the next station from 'start'
            // So, we reset 'curr' and move the start to the next station
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }

        // If total gas is non-negative, the trip is possible starting from 'start'
        // Otherwise, it's impossible to complete the circuit
        return (total >= 0) ? start : -1;
    }
};
