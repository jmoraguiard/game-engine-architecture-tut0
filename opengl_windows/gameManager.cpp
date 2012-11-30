#ifdef _WIN32
#include <windows.h>
#endif

#include "gameManager.h"

#include "gameState.h"
#include "splashScreenState.h"

GameManager::GameManager() {
	game_state_ = NULL;
	changeState( SplashScreenState::Instance() );
}

GameManager::~GameManager() {

}

bool GameManager::init() {
	return game_state_->init();
}

void GameManager::update(float elapsed_time) {
	game_state_->update(this, elapsed_time);
}

void GameManager::draw() {
	game_state_->draw(this);
}

void GameManager::processKeyboardEvent(char key_pressed) {
	game_state_->keyboardEvent(this, key_pressed);
}

void GameManager::onResize(int width, int height) {
	game_state_->onResize(this, width, height);
}

void GameManager::changeState(GameState* game_state) {
	if (game_state != game_state_) {
		game_state_ = game_state;
		game_state_->init();
	}
}



