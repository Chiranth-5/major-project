// 1.calculate gflops for my laptop

// Since we are doing a Performance Analysis, we need a task that is CPU-bound 
// (meaning the CPU has to do a lot of math, but doesn't have to wait for the hard drive).

// Assignment 1: The "Sequential" Math Stress Test
// We will calculate the sum of square roots for 100 million numbers. This is a great "micro-benchmark."

// Step 1: Create basic_cpu.cpp
// Copy this code. It performs 100 million square root operations on a single thread.