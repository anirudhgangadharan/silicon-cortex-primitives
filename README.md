# Silicon Cortex Primitives

## Overview
This repository houses low-level C++ implementations of biological neuron models, specifically designed to bridge the gap between biological "Integration Capacity" and silicon-based Spiking Neural Networks (SNNs).

## Current Modules
### 1. The Perceptron Node (Integrate-and-Fire)
* **Status:** Active
* **Logic:** Simulates membrane potential dynamics ($V_m$), synaptic summation ($\Sigma$), and Action Potential generation based on all-or-none thresholds.
* **Goal:** To serve as the atomic unit for higher-order "Cognit" verification protocols in neuromorphic hardware.

## Roadmap
* [x] Basic Integrate-and-Fire Model (C++)
* [ ] Synaptic Plasticity (STDP) Implementation
* [ ] Inhibitory/Excitatory Network Topology
* [ ] Interface with Python/PyTorch (via Bindings) for NeuroLink Protocol v0.1

## About the Author
Medical Scientist (MBBS) & Computational Researcher focusing on the intersection of BCI, Neuromorphic Computing, and Collective Intelligence.
