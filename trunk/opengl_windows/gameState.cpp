#ifdef _WIN32
#include <windows.h>
#endif

#include "gameState.h"

#include "gameManager.h"

GameState::GameState() {

}

GameState::~GameState() {

}

void GameState::changeState(GameManager* game_manager, GameState* game_state) {
	game_manager->changeState(game_state);
}


