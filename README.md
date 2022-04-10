# 5 state 3-hop MOESI cache coherence protocol

The key idea to solve race between Get and Put message at directory (homenode) is that adding FwdAck to make sure the forward message
(triggered by Get message) is received by processors and then begin process Put messages.

## Directory State Transition

![Directory State Transition]()

## Processor State Transition

![Processor State Transition]()

* The dotted line represent a active state transition -- the processor **send** a message and transfer to a next state.
* The solid line represent a passive state transition -- the processor **receive** a message and transfer to a next state.
