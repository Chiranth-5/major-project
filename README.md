# Resilient Heterogeneity-Aware Scheduling for AI Workloads on Unreliable Mid-Scale Infrastructure

This project focuses on building a "Control Plane" that optimizes job placement across a mixed (Xeon, P100, L40S) 18-node cluster while accounting for frequent hardware unreliability. This 4-month roadmap is designed for a 6-credit Master's Thesis completion.

---

## The 4-Month Execution Roadmap

### **Month 1: The Cluster Oracle (Hardware DNA & Health)**
**Focus:** Building a real-time "Source of Truth" for the 18-node cluster.

* **Tasks:**
    * Develop a **Python-based Inventory Service** to catalog node-specific hardware (Xeon cores, P100 vs. L40S VRAM).
    * Implement a **Heartbeat Monitor** to ping nodes and query GPU status every 30 seconds.
* **The Research Element:** Identifying the **"Performance Gap"**—quantifying exactly how much slower a P100 is compared to an L40S for standard LLM inference tasks to create a performance baseline.
* **Deliverable:** A **Dynamic Cluster Map** (JSON/Dashboard) that automatically flags nodes as `Healthy`, `Degraded`, or `Offline`.
** Learn : speed of each node quantification techneiques and latest tools.
computer architecture( bechanmarking) and computer network.

LLM inferene task: categories of AI model tasks . 
how AI model works and the all categories of different AI mdels tasks .



---

### **Month 2: The Policy Engine (Decision Logic)**
**Focus:** Developing the mathematical "brain" of the scheduler.

* **Tasks:**
    * Create a **Weighted Scoring Algorithm**. Instead of simple round-robin, the scheduler calculates:
      $$Score = (Compute\_Power \times Reliability\_History) - Network\_Latency$$
    * Categorize AI jobs into **"Tiers"** (e.g., Tier 1: Heavy Training, Tier 2: Light Inference).
* **The Research Element:** Designing a policy that prevents **"Job Starvation"** ensuring small jobs aren't blocked by massive workloads in a heterogeneous environment.
* **Deliverable:** A **Validated Decision Matrix** showing which hardware tier is mathematically optimal for specific AI model sizes.

---

### **Month 3: The Resilient Plugin (Integration & Chaos)**
**Focus:** Turning logic into a functional tool for Slurm or Kubernetes.

* **Tasks:**
    * Develop a **Scheduler Plugin** that intercepts job submissions and places them based on the Phase 2 logic.
    * **The Chaos Test:** Run a batch of concurrent jobs and manually "kill" nodes or disconnect network interfaces to test system response.
* **The Research Element:** Measuring **"Failover Latency"**—quantifying how quickly the scheduler detects a crash and re-queues the job to a healthy node compared to default system settings.
* **Deliverable:** A **Functional Scheduler Prototype** and a **"Chaos Report"** comparing success rates against default cluster configurations.

---

### **Month 4: The Empirical Publication (The Proof)**
**Focus:** Writing the paper and finalizing the thesis for December graduation.

* **Tasks:**
    * Synthesize all data into professional visualizations showing **Throughput**, **GPU Utilization**, and **Failure Recovery Time**.
    * Format the paper for **Electronics (MDPI)** or **Journal of Big Data** for a fast-track review cycle.
* **The Research Element:** Proving that **"Health-Awareness"** is more critical than "Raw Speed" in real-world, unpredictable academic clusters.
* **Deliverable:** A **Submitted Research Paper** and a completed **6-credit Thesis Dissertation**.

---

## 📊 Key Performance Indicators (KPIs)

| Metric | Target Goal |
| :--- | :--- |
| **Job Success Rate** | > 95% during simulated node failures |
| **GPU Utilization** | > 20% improvement over Round-Robin baseline |
| **Failover Time** | < 60 seconds from node failure to job re-queue |
| **Publication Goal** | Submission to peer-reviewed journal by end of Month 4 |

---

## 🛠️ Technology Stack
* **Backend:** Python, C++
* **Orchestration:** Slurm / Kubernetes (K8s)
* **Monitoring:** Prometheus / Custom Python Heartbeat
* **Hardware:** 18-Node Cluster (NVIDIA L40S, P100, Intel Xeon)





Orchestration: slurm / kubernetes(k8)s


This is a high-level engineering roadmap that will look incredible on your resume. By splitting these into Summer and Fall, you are essentially transitioning the PDS Lab from "Classic HPC" (Ganglia/TORQUE) to "Modern Cloud-Native HPC" (Prometheus/Kubernetes).

Since you are aiming for 3 credits each, you need to ensure the "Research" component is clear. Here is how I would structure the proposals for your professor.

Phase 1: Summer (3 Credits)
Project Title: High-Resolution Observability and Performance Characterization in Heterogeneous Clusters.

The Goal: Replace Ganglia with a Prometheus/Grafana stack.

The Research Core: * Sampling Jitter: Investigate if Prometheus's "pull" frequency interferes with low-latency MPI jobs.

GPU Insights: Develop custom exporters for Node 18 to track per-process GPU memory and power draw, which Ganglia currently lacks.

Deliverables:

A live, persistent Grafana dashboard for the PDS Lab.

A performance report comparing the resource overhead of gmond vs. node_exporter.

A documentation guide for future students to add custom metrics.

Phase 2: Fall (3 Credits)
Project Title: Evaluating Container Orchestration for Scalable AI Infrastructure.

The Goal: Implement a Kubernetes (K8s) or Slurm-on-K8s environment alongside TORQUE.

The Research Core: * The "Tax" of Virtualization: Measure the execution time difference of an AI training job (like your hand-gesture recognition project) on bare-metal Slurm vs. Docker/K8s.

Resource Scheduling: Implement "Fair-Share" scheduling in K8s to mimic HPC batch queuing.

Deliverables:

A working K8s namespace or cluster environment for the lab.

A benchmark study showing the networking/latency trade-offs of containerized MPI.

A prototype of a "Self-Service" portal where students can launch pre-configured AI containers.







what mertrics are mesured in gangalia vs pramatheous.
extensive expiriments and comparing the output of gangalia and shortcoimgn aboserved fromt hais reading.(Quantify this).
short coming qauntify
the do working of both the tools.


Experimental Comparative Analysis of Cluster Monitoring Frameworks in HPC EnvironmentsCourse Title: Self-Directed Study in High-Performance Computing InfrastructureCredits: 3.0Focus Area: Systems Architecture & Distributed MonitoringOverview: This study performs a rigorous, quantified experimental analysis of the Ganglia Distributed Monitoring System within a multi-node High-Performance Computing (HPC) cluster to identify critical performance "gaps" in modern research workflows. While Ganglia has served as a legacy standard for cluster-level status, this project investigates its shortcomings in data fidelity, network overhead, and storage efficiency when subjected to high-frequency metric injection.Methodology: The research is divided into two phases. First, a stress-test baseline is established on the Heracles/Hydra cluster to measure the $O(N^2)$ network scaling issues inherent in Ganglia’s multicast model and the 95% resolution loss caused by RRDTool’s data averaging. Second, the study proposes and evaluates Prometheus, an open-source, cloud-native monitoring tool, as a high-performance alternative.Key Objectives:Quantify Monitoring Overhead: Measure the CPU/Memory footprint of gmond vs. node_exporter during high-cardinality data bursts.Analyze Data Preservation: Document the "Resolution Gap" by comparing peak-detection accuracy between Ganglia’s lossy storage and Prometheus’s TSDB delta-compression.Network Modeling: Calculate the reduction in management network congestion when transitioning from a "Push/Multicast" to a "Pull/Scrape" architecture.






```
ganglia-vs-prometheus-hpc-cluster/
├── README.md                           # Master project overview, executive summary, and portfolio guide
├── docs/
│   ├── 01-architecture-deep-dive.md    # Protocol stack & storage model comparison (UDP/Multicast vs. TCP/Unicast/TSDB)
│   ├── 02-local-sandbox-setup.md       # 3-node UTM/Ubuntu ARM64 local virtualization runbook
│   ├── 03-experimental-matrix.md       # 4-quadrant benchmark methodology (isolating network noise & multi-tenant stress)
│   ├── 04-production-18-node-grid.md   # Scaling strategies and grid-level performance findings
│   └── 05-rootless-userspace-runbook.md  # Documents unprivileged, home-directory binary execution and tmux management
├── configs/
│   ├── ganglia/
│   │   ├── gmond.conf                  # Worker/master gmond daemon configuration
│   │   └── gmetad.conf                 # Central gmetad aggregation and RRD polling config
│   └── prometheus/
│       ├── prometheus.yml              # Standard system-level scrape jobs & targets configuration
│       ├── node_exporter.service       # Systemd unit file for privileged edge telemetry
│       └── prometheus-userspace.yml     # User-mode scraping config for unprivileged cluster targets
└── scripts/
    ├── ganglia/
    │   ├── bootstrap_gmond_system.sh    # Installs and configures gmond via apt & systemd (Root)
    │   ├── bootstrap_gmetad_master.sh   # Installs and configures gmetad + gweb on master (Root)
    │   └── scale_ganglia_fleet.py       # Orchestrates gmond bindings across cluster nodes
    ├── prometheus/
    │   ├── deploy_node_exporter.sh      # Automates system-level node_exporter tarball & service (Root)
    │   ├── deploy_prometheus_tsdb.sh    # Sets up central Prometheus server and target bindings (Root)
    │   └── userspace_rootless_deploy.sh # Rootless tarball unpack, custom config, & tmux launcher (User-space)
    └── benchmarking/
        ├── scale_orchestration.py       # Coordinates cross-node fleet targets & test cycles
        └── workload_spike.py            # Generates CPU/memory contention for metric analysis
```














