#include <iostream>
#include <vector>
#include <cmath>

//Biological neuron modelled as a leaky-integrate and fire unit

class LIF_neuron {
    private:
        double membrane_potential; //intetnal voltage
        double resting_potential; //-70mV
        double threshold; //-55mV
        double decay_factor; //the rate at which the voltage leaks (0.9=slow leak)
        double is_refractory; //Is the neuron resting
        double refractory_timer; //How long to rest
        
    public:
        //Birth of the neuron
        LIF_neuron() {
            membrane_potential = -70.0;
            resting_potential = -70.0;
            threshold = -55.0;
            decay_factor = 0.9;
            refractory_timer = 0;
            
        }
        
        //Time step 
        // input_current is the signal from other neurons /sensors
        
        bool update(double input_current) {
            //1. Handle refractory period (Resting)
            if (is_refractory) {
                refractory_timer--;
                std::cout << "[...] Refractory, Recovering,\n";
                if (refractory_timer <= 0) is_refractory = false;
                return false; //cannot fire while resting
            }  
           //2. Integration -ie, New potential = (old*decay) + input 
            membrane_potential = (membrane_potential*decay_factor) + input_current;
            //3.Check for spike- action potential
            if (membrane_potential >= threshold) {
                fire();
                return true; // spike!
            } else {
                std::cout <<"Potential:" <<membrane_potential << "mV\n";
                return false; // silent
            }
        }
        
        void fire() {
            std::cout << ">>>SPIKE! ACTION POTENTIAL GENERATED! <<<\n";
            membrane_potential = resting_potential; //Reset
            is_refractory =  true;
            refractory_timer = 3; // Rest for 3 cycles
            
            
        }
};

int main() {
    LIF_neuron brain_cell;
    
    std::cout <<"---INJECTING CURRENT---\n";
    
    //Simulat 10ms of activity
    std::vector<double> inputs = {0.0, 5.0, 5.0, 5.0, 20.0, 0.0, 0.0, 0.0, 5.0, 5.0};
    
    for (int t = 0; t <10; t++) {
        std::cout << "Time" << t <<"ms: ";
        brain_cell.update(inputs[t]);
    }
    
    return 0;
}
