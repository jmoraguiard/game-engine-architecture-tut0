#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

class GameState;

class GameManager
{
	public:
		GameManager();
		virtual ~GameManager();

		bool init();
		void update(float elapsed_time);
		void draw();
		void processKeyboardEvent(char key_pressed);

		void onResize(int width, int height);

		void changeState(GameState* game_state);

	private:
		GameState* game_state_;
};

#endif
