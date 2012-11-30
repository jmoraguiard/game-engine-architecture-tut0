#ifndef _GAME_STATE_H
#define _GAME_STATE_H

class GameManager;

class GameState
{
	public:
		GameState();
		virtual ~GameState();

		virtual bool init() = 0;
		virtual void update(GameManager* game_manager, float elapsed_time) = 0;
		virtual void draw(GameManager* game_manager) = 0;
		virtual void keyboardEvent(GameManager* game_manager, char key_pressed) = 0;

		virtual void onResize(GameManager* game_manager, int width, int height) = 0;

		void changeState(GameManager* game_manager, GameState* game_state);
};

#endif
