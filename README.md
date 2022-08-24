# Five-state 3-hop MOESI cache coherence protocol

The key idea to solve race between Get and Put message at directory (homenode) is that adding FwdAck to make sure the forward message
(triggered by Get message) is received by processors and then begin process Put messages.

## How to run

Just run `make` command and you will get `msi.out` and `msi_opt.out`

## Directory State Transition

* The solid line represent a passive state transition -- the directory **receive** a message and transfer to a next state.

![Directory State Transition](pic/EECS%20570%20HW2-Page-3.png)

## Processor State Transition

* The dotted line represent an active state transition -- the processor **send** a message and transfer to a next state.
* The solid line represent a passive state transition -- the processor **receive** a message and transfer to a next state.

![Processor State Transition](pic/EECS%20570%20HW2-Page-2.png)
