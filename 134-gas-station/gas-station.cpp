class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalGas = 0;   // Total gas available in all stations
        int totalCost = 0;  // Total cost required to travel all stations

        int tank = 0;       // Current gas in tank while travelling
        int start = 0;      // Starting index

        // Traverse all gas stations
        for(int i = 0; i < gas.size(); i++){

            // Add total gas and total cost
            totalGas += gas[i];
            totalCost += cost[i];

            // Calculate remaining gas after travelling to next station
            tank += gas[i] - cost[i];

            // If tank becomes negative → cannot reach next station
            if(tank < 0){

                // Move starting point to next station
                start = i + 1;

                // Reset tank since we start fresh
                tank = 0;
            }
        }

        // If total gas < total cost → impossible to complete
        if(totalGas < totalCost)
            return -1;

        // Otherwise return starting index
        return start;
    }
};