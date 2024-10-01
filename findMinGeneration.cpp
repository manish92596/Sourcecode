#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'findMinGeneration' function below.
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY layer as parameter.
 */
long findMinGeneration(vector<int> layer) {
    int n = layer.size();
    
    // Find the maximum number of neurons in any layer
    int maxNeurons = *max_element(layer.begin(), layer.end());
    long generations = 0;

    // Continue until all layers are equal to maxNeurons
    while (true) {
        // Count how many neurons we need to add to reach maxNeurons
        int totalNeeded = 0;
        for (int i = 0; i < n; i++) {
            if (layer[i] < maxNeurons) {
                totalNeeded += maxNeurons - layer[i];
            }
        }

        // If no neurons need to be added, break the loop
        if (totalNeeded == 0) break;

        // Determine how many layers can be increased in this generation
        if (generations % 2 == 0) {
            // Even generation: 2 neurons can be added to at most one layer
            generations += (totalNeeded + 1) / 2; // ceil(totalNeeded / 2)
        } else {
            // Odd generation: 1 neuron can be added to at most one layer
            generations += totalNeeded; // just add as is
        }

        // Update the layers to reflect the changes
        for (int i = 0; i < n; i++) {
            if (layer[i] < maxNeurons) {
                layer[i]++;
                if (generations % 2 == 1) break; // Only one layer can be updated in odd generations
            }
        }
    }
    
    return generations;
}

int main() {
    // Hardcoded input for Sample Case 0
    vector<int> layer = {3, 3, 6}; // Sample input: layer = [3, 3, 6]
    
    long result = findMinGeneration(layer);
    cout << result << endl;  // Output the minimum number of generations

    return 0;
}
