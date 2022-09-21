#pragma once

#include <windows.h>
#include <string>
#include "NYTimer.h"
#include "GameManager.h"
#include "Renderer.h"
class ConsoleSurvivorGame {
	public:
		NYTimer timer;
		ConsoleSurvivorGame();
		void launchGame();
		void HideCaret(HANDLE&);
        void PrepareWindowStyle(HANDLE&);
	private:
		void DisplayArena();
};