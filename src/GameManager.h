class GameManager {
	public:
        static const int maxEntities = 100;
		GameManager();
        Entity * entities[maxEntities];
        Player * player;
		InputHandler inputHandler;
		void RunGameLoop();
        int validEntityCount = 0;
};