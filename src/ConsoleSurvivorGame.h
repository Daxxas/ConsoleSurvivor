class ConsoleSurvivorGame {
	public:
		static const int TARGET_FPS = 60;
		static const int MS_PER_GAME_TICK = 1000 / TARGET_FPS; // 16.67 at 60fps
		NYTimer timer;
		ConsoleSurvivorGame();
		void launchGame();
		void HideCaret(HANDLE&);
        void PrepareWindowStyle(HANDLE&);
	private:
		void DisplayArena();
};