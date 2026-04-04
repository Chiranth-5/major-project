### Month 1: The Baseline (1 Credit) — *The Speed of a Single Node*

**Focus:** Master the fundamental limits of the Intel Xeon CPUs.

**Task:** Write a C++ program for Matrix Multiplication. Benchmark it using 1 thread vs. 24 threads.

**Goal:** Calculate Peak GFLOPS (Giga-Floating Point Operations Per Second) for a single node.

**Deliverable:** A “Scaling Graph” showing where adding more CPU threads stops helping.


architecture of hercales cluster:

Heracles, is a specialized resource for the department, here is the "Identity" of your 18-node Cluster:
According to the PDS Lab's technical specs:
15 Compute Nodes (2-16): These are the "Workhorses." Each one has 2x Intel Xeon E5-2650 v4 processors. This is exactly where the 24-core count comes from (12 cores per socket).
Node 17 (The Modern GPU Node): This is your high-end node. It contains 2x NVIDIA L40S GPUs.
Node 18 (The Pascal Node): This node contains 4x NVIDIA Tesla P100 GPUs.

All 18 nodes are connected by a Mellanox SwitchX-2 with a 2Tb/s capacity, which is incredibly fast for a mid-sized cluster.

tasks:
1.calculate gflops for my laptop
2. calculate gflops for a single node in heracels.

