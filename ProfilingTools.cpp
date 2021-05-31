// ProfilingTools.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>

class Timer
{
public:
	Timer()
	{
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		Stop();
	}
	void Stop()
	{
		auto EndTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(EndTimePoint).time_since_epoch().count();
		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << "Time taken "<< ms;
		
		
	}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};
int main()
{
    std::cout << "Hello World!\n";
		int value = 0;
	{
		Timer t;


		for (int i = 0; i < 10000000; i++)
			value += 2;
	}
	std::cout << value;
	

}
