#pragma once

class idConsoleSurvivorGame {
	public: 
		idConsoleSurvivorGame();
		void HideCaret(HANDLE);
		void KeyEventProc(KEY_EVENT_RECORD);
		void HandleInput();
		void ErrorExit(LPSTR);
		void launchGame();
        void PrepareWindowStyle();
};