#include <iostream>
#include <cmath>
#include <vector>

// ==========================================
// MODULE 2: SPIKE-TIMING-DEPENDENT PLASTICITY (STDP)
// ==========================================
// This class models the 'Learning Rule' of the brain.
// Unlike standard AI (Backpropagation), the brain learns by TIMING.
// Rule: "Neurons that fire together, wire together."

class STDPSynapse {
private:
    double weight;           // Synaptic Strength (0.0 to 1.0)
    double tau_plus = 20.0;  // Time window for strengthening (LTP)
    double tau_minus = 20.0; // Time window for weakening (LTD)
    double A_plus = 0.01;    // Max learning rate (Potentiation)
    double A_minus = 0.012;  // Max forgetting rate (Depression)

public:
    // Constructor: Start with a weak connection
    STDPSynapse() : weight(0.5) {}

    // THE UPDATE FUNCTION
    // delta_t = t_post - t_pre (Time difference between spikes)
    void update(double delta_t) {
        if (delta_t > 0) {
            // CAUSAL: Input fired BEFORE Output (Pre -> Post)
            // The synapse realizes it contributed to the firing.
            double change = A_plus * std::exp(-delta_t / tau_plus);
            weight += change;
            std::cout << "[LTP] Causal Link (dt=" << delta_t << "ms). Strengthening by " << change << "\n";
        } 
        else {
            // ANTI-CAUSAL: Input fired AFTER Output (Post -> Pre)
            // The synapse realizes it was too late (Noise).
            double change = A_minus * std::exp(delta_t / tau_minus); // delta_t is negative
            weight -= change;
            std::cout << "[LTD] Noise Detected (dt=" << delta_t << "ms). Weakening by " << change << "\n";
        }

        // Biological Constraints (Weights cannot be infinite)
        if (weight > 1.0) weight = 1.0;
        if (weight < 0.0) weight = 0.0;
    }

    double get_weight() const { return weight; }
};

int main() {
    STDPSynapse synapse;
    std::cout << "--- STDP LEARNING SIMULATION ---\n";
    std::cout << "Initial Weight: " << synapse.get_weight() << "\n\n";

    // SCENARIO 1: Learning (Causal)
    // The input spike arrived 10ms BEFORE the neuron fired.
    synapse.update(10.0);
    
    // SCENARIO 2: Forgetting (Noise)
    // The input spike arrived 5ms AFTER the neuron fired.
    synapse.update(-5.0);

    std::cout << "\nFinal Learned Weight: " << synapse.get_weight() << "\n";
    return 0;
}
