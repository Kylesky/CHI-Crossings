#include "Engine.hpp"

enum GAME_STATE {LAUNCHING, MAIN_MENU, OPTIONS_MENU, JOIN_GAME, PARTY_SCREEN, LOADING_TO_GAME, IN_GAME, RESULTS_SCREEN};

int main()
{
	srand(time(NULL));
	GAME_STATE state = LOADING_TO_GAME;

	//Initialize managers, window, entities, etc

	sf::RenderWindow* window = setupWindow();
	
	/*
	AssetManager assetManager = AssetManager();
	GraphicsManager graphicsManager = GraphicsManager();
	//AudioManager audioManager = AudioManager();
	ModuleHandler moduleHandler = ModuleHandler();
	//NetworkManager networkManager = NetworkManager();
	*/

	GraphicsManager::initialize(window);
	AssetManager::initialize();
	InputHandler::initialize();

	setupTimeLoop();

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
		InputHandler::update();

		switch(state){
		case LOADING_TO_GAME:
			ModuleHandler::initialize(CONTINUOUS_SIDE_SCROLLER);
			state = IN_GAME;
			break;
		case IN_GAME:
			ModuleHandler::update(secondsSinceLastLoop());
			break;
		}

		waitForFrameSync();

		//Draw everything
		GraphicsManager::clearScreen();
		switch(state){
		case IN_GAME:
			ModuleHandler::drawScreen();
			GraphicsManager::update(secondsSinceLastLoop());
			break;
		}
    }

	//shutdown everything
	AssetManager::shutdown();
	ModuleHandler::shutdown();
	InputHandler::shutdown();

    return 0;
}