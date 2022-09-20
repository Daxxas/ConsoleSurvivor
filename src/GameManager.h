class GameManager {
	public:
        static const int maxEntities = 100;
		GameManager();
        Entity * entities[maxEntities];
        Player * player;
		void RunGameLoop();
		void DetectLastInputFromPlayer();
		bool IsVKeyPressed(int);
};