#include <iostream>
using namespace std;
//This is the class for the artificial brain cell

class Neuron {
    public:
        float potential;
        float threshold;
        
        Neuron() {
            potential = -70.0;
            threshold = -55.0;
            cout << "Neuron created. Resting potential : -70mV" << endl;
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
    
    cout << "\n--- STIMULATION ---" << endl;
    // Stimulus 1: Weak (sub-threshold)
    n.input(5.0);
    //Stimulus 2: Strong (Summation --> FIRE)
    n.input(15.0);
    return 0;
}
