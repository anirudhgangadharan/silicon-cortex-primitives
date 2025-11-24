# Silicon Cortex Primitives

## Overview
This repository houses low-level C++ implementations of biologically-plausible neuron and synapse models. The goal is to bridge the gap between biological **Integration Capacity** and silicon-based **Spiking Neural Networks (SNNs)** for next-generation Brain-Computer Interfaces.

## Modules

### 1. Leaky Integrate-and-Fire (LIF) Model
* **File:** `lif_neuron.cpp`
* **Physics:** Simulates the membrane potential as an RC circuit ($V_m$).
* **Dynamics:** Implements temporal decay ($\tau$), Action Potential thresholding, and Absolute Refractory periods.
* **Why:** Unlike standard ANN neurons (ReLU/Sigmoid), this model captures the **Time-Domain** information essential for neuromorphic hardware (Loihi/TrueNorth).

### 2. Spike-Timing-Dependent Plasticity (STDP)
* **File:** `stdp_synapse.cpp`
* **Algorithm:** Implements the Hebbian learning rule where synaptic weight ($w$) is adjusted based on the relative timing ($\Delta t$) of pre- and post-synaptic spikes.
* **Logic:**
    * **Causal ($\Delta t > 0$):** Long-Term Potentiation (LTP).
    * **Anti-Causal ($\Delta t < 0$):** Long-Term Depression (LTD).

## Roadmap
- [x] Basic Integrate-and-Fire
- [x] Leakage & Refractory Dynamics
- [x] STDP Synaptic Learning
- [ ] Network Topology (Cortical Column Simulation)

---
*Author: Anirudh Gangadharan | Medical Scholar & Computational Researcher*
