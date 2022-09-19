#pragma once

class idConsoleSurvivorGame {
	public: 
		idConsoleSurvivorGame();
		void launchGame();
		void HideCaret(HANDLE);
		void KeyEventProc(KEY_EVENT_RECORD);
};