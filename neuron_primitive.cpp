#include <iostream>
using namespace std;
//This is the class for the artificial brain cell

class Neuron {
    public:
        float potential;
        float threshold;
        float resting_potential;
        float decay_factor; //time constant
        
        Neuron() {
            potential = -70.0;
            threshold = -55.0;
            resting_potential = -70.0;
            decay_factor = 0.90; // Retain 90% of charge per time step (Leak 10%)
            cout << "LIF Neuron created. Decay factor (Alpha)" << decay_factor << endl;
        }
        
        void update_time_step() {
            // The equation: V_new = V_old * Decay + V_rest * (1-Decay)
            potential = (potential * decay_factor) + (resting_potential * (1.0 - decay_factor));
            cout << "...Time passes potential decays to:" << potential << "mV" << endl;
            
        }
        void input(float signal) {
            potential = potential + signal ;
            cout << "Received:" << signal << "mV | New potential :" << potential << "mV" <<endl;
            
            if (potential >= threshold) {
                cout << "ACTION POTENTIAL DETECTED! <<<" << endl;
                potential = -70.0; //Reset
                cout << "Neuron Reset." << endl;
            }
        }
};

int main() {
    Neuron n;
    
    cout << "\n--- TEMPORAL SUMMATION ---" << endl;
    // Stimulus 1: Weak (sub-threshold)
    n.input(10.0); //Goes to -60
    
    //Time passes (The leak)
    n.update_time_step(); //should drop back to -70
    
    //Stimulus 2: 
    n.input(10.0); //if leaked, this might not fire yet
    
    //Stimulus 3 (strong)
    n.input(20.0);
    
    return 0;
}
