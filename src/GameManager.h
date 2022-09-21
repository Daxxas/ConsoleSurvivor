class GameManager {
	public:
        static const int maxEntities = 100;
        Entity * entities[maxEntities];
        Player * player;
		InputHandler * inputHandler;
		NYTimer timer;
        int validEntityCount = 0;
        int baseMsBetweenPlayerMovements = 250;
public:
    void RunGameLoop();

//Singleton pattern
public:
    static GameManager& Instance() {
        static GameManager S;
        return S;
    }

private:
    GameManager();
    ~GameManager();
};