#include "Engine.hpp"

enum GAME_STATE {LOADING_TO_GAME, MAIN_MENU, OPTIONS_MENU, JOIN_GAME, PARTY_SCREEN, IN_GAME, RESULTS_SCREEN};

int main()
{
	GAME_STATE state = LOADING_TO_GAME;

	//Initialize managers, window, entities, etc

	//GraphicsManager graphicsManager();
	//AssetManager assetManager();
	//AudioManager audioManager();
	//ModuleManager moduleManager();

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
		
		//Process all user inputs

		//Process all game logic

		waitForFrameSync();

		//Draw everything
    }

    return 0;
}