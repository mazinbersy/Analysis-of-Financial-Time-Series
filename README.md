# Exchange Rate Analysis using Binary Heaps

## Overview

This C++ program analyzes exchange rate data read from a file using binary heaps. It calculates the mean exchange rate, finds the maximum and minimum exchange rate values, and identifies the contiguous period over which the sum of rate changes is maximum.

## Files

1. `BinaryHeap.h`: Header file containing the definition of the BinaryHeap class.
2. `main.cpp`: Main C++ program file containing the implementation of the analysis.

## BinaryHeap Class

- The `BinaryHeap` class implements a binary heap data structure, providing operations like heapify, building heap from an array, and deleting minimum/maximum nodes.

## Main Program

- `readInfo_and_findAverage`: Reads exchange rate data from a file and calculates the average exchange rate.
- `findMaxValues`: Finds and displays the N maximum exchange rate values along with their change from the mean.
- `findMinValues`: Finds and displays the N minimum exchange rate values along with their change from the mean.
- `maxSubsequence`: Finds the start and end indices of the contiguous period over which the sum of rate changes is maximum.

## Input Format

- The program expects exchange rate data in a file named `exchangeInfo.txt`.
- Each line of the file should contain a date (string) and the corresponding exchange rate value (double), separated by a space.

## Output Format

- The program outputs the mean exchange rate.
- It displays the N maximum and N minimum exchange rate values along with their change from the mean.
- It identifies the contiguous period with the maximum sum of rate changes and displays the start and end dates of that period.
