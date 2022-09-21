#pragma once
#include <windows.h>

class NYTimer {
	public:
		LARGE_INTEGER lastUpdateTime;
		LONGLONG freq;
		NYTimer();
		void start();
		float getElapsedSeconds(bool);
		unsigned long getElapsedMs(bool);
};