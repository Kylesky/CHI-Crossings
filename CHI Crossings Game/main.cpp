#include "Engine.hpp"

enum GAME_STATE {LAUNCHING, MAIN_MENU, OPTIONS_MENU, JOIN_GAME, PARTY_SCREEN, LOADING_TO_GAME, IN_GAME, RESULTS_SCREEN};

int main()
{
	GAME_STATE state = LOADING_TO_GAME;

	//Initialize managers, window, entities, etc

	AssetManager assetManager = AssetManager();
	//GraphicsManager graphicsManager = GraphicsManager();
	//AudioManager audioManager = AudioManager();
	ModuleHandler moduleHandler = ModuleHandler();

	setupTimeLoop();
	sf::RenderWindow* window = setupWindow();

    while (window->isOpen()) //Main game loop
    {
		//Process all window messages/events
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
		
		//Process all user inputs and game logic
		switch(state){
		case LOADING_TO_GAME:
			moduleHandler.initialize(CONTINUOUS_SIDE_SCROLLER);
			state = IN_GAME;
			break;
		case IN_GAME:
			moduleHandler.update(secondsSinceLastLoop());
			break;
		}

		waitForFrameSync();

		//Draw everything
    }

	//shutdown everything
	assetManager.shutdown();

    return 0;
}