// 1.calculate gflops for my laptop

// Since we are doing a Performance Analysis, we need a task that is CPU-bound 
// (meaning the CPU has to do a lot of math, but doesn't have to wait for the hard drive).

// Assignment 1: The "Sequential" Math Stress Test
// We will calculate the sum of square roots for 100 million numbers. This is a great "micro-benchmark."

// Step 1: Create basic_cpu.cpp
// Copy this code. It performs 100 million square root operations on a single thread.

#include <iostream>
#include <cmath>
#include <chrono>

int main() 
{
    const int iterations = 100000000; // 100 Million
    double sum = 0.0;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) 
    {
        sum += std::sqrt(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    double gflops = (iterations / elapsed.count()) / 1e9;

    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    std::cout << "Result: " << sum << " (to prevent optimization)" << std::endl;
    std::cout << "Performance: " << gflops << " GFLOPS" << std::endl;

    return 0;
}