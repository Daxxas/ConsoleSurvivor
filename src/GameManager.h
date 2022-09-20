



class GameManager {
	public:
        static const int maxEntities = 100;
        Entity * entities[maxEntities];
        Player * player;
		InputHandler * inputHandler;
		NYTimer * timer;
        int validEntityCount = 0;
public:
		GameManager();
		void RunGameLoop();
};