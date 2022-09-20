#include "Entities/Entity.h"
#include "Entities/Player.h"

class GameManager {
	public:
        static const int maxEntities = 100;
		GameManager();
		void RunGameLoop();
        Entity * entities[maxEntities];
        Player * player;

};