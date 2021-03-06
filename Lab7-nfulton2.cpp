// Lab7-nfulton2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Modified 11/12/2018
//Code used for sort from...
//https://www.geeksforgeeks.org/heap-sort/
//https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/
//https://www.geeksforgeeks.org/insertion-sort/
//https://stackoverflow.com/questions/22504837/how-to-implement-quick-sort-algorithm-in-c

// The goal of this program is to compare execution times of several sorting
// methods. The methods used are quick sort, comparison, insertion, heap, standard, and bubble

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "winTimer.h"
#include "Lab7-nfulton2.h"

int main()
{
	//declare the timer
	Timer a;
	std::vector<int> set1;
	std::vector<int> set2;
	std::vector<int> set3;
	std::vector<int> set4;
	std::vector<int> set5;
	std::vector<int> set6;
	
	//generate the random sized vectors
	generateRandomVector(set1);
	generateRandomVector(set2);
	generateRandomVector(set3);
	generateRandomVector(set4);
	generateRandomVector(set5);
	generateRandomVector(set6);
	
	//time and record the times
	a.start();
	comparisonSort(set1);
	a.stop();
	std::cout << "Comparison Sort: " << a.operator()() << std::endl;
	a.start();
	quickSort(set2, 0, 30);
	a.stop();
	std::cout << "Quick Sort: " << a.operator()() << std::endl;
	a.start();
	insertionSort(set3, sizeof(set3)/sizeof(set3[0]));
	a.stop();
	std::cout << "Insertion Sort: " << a.operator()() << std::endl;
	a.start();
	bubbleSort(set4, sizeof(set4) / sizeof(set4[0]));
	a.stop();
	std::cout << "Bubble Sort: " << a.operator()() << std::endl;
	a.start();
	heapSort(set5, sizeof(set5) / sizeof(set5[0]));
	a.stop();
	std::cout << "Heap Sort: " << a.operator()() << std::endl;
	a.start();
	std::sort(set6.begin(), set6.end());
	a.stop();
	std::cout << "STD Sort:" << a.operator()() << std::endl;


}

