#include <chrono>
#include <fstream>
class HRTimer
{
public:
	HRTimer(const char *ch)
	{
		c = ch;
		m_StartTimePoint = std::chrono::high_resolution_clock::now();
	}
	~HRTimer()
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

		std::ofstream ofs("Timeoutput1.txt", std::ios_base::out | std::ios_base::app);
		ofs << '\n' << c << "   " << ms << "Time taken " << duration << " in ms :" << ms;
		ofs.close();
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
	const char *c;
};
