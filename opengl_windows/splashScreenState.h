#ifndef _SPLASH_SCREEN_STATE_H_
#define _SPLASH_SCREEN_STATE_H_

#include "gameState.h"

class SplashScreenState: public GameState
{
	public:
		SplashScreenState();
		virtual ~SplashScreenState();
		static SplashScreenState* Instance();

		virtual bool init();
		virtual void update(GameManager* game_manager, float elapsed_time);
		virtual void draw(GameManager* game_manager);
		virtual void keyboardEvent(GameManager* game_manager, char key_pressed);

		virtual void onResize(GameManager* game_manager, int width, int height);

	private:
		static SplashScreenState splash_screen_state_; //singleton

		float angle_rotation_;
};

#endif
