
#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H
#include <chrono>
#include "AbstractEntity.h"

class TimeManager {
public:
	static TimeManager& GetInstance();
	void Start();
	void Update();
	unsigned int GetElapsedTime() const;
	unsigned int GetStartedTime() const;

private:
	TimeManager& operator=(const TimeManager&) { return TimeManager::GetInstance(); };
	TimeManager(const TimeManager&) {};

	static TimeManager instance;
	TimeManager() {};
	~TimeManager() {};
	std::chrono::time_point<std::chrono::system_clock> start, previous_end, end;
};

#endif //TIMEMANAGER_H