#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>

#include "splashScreenState.h"

SplashScreenState SplashScreenState::splash_screen_state_;

SplashScreenState::SplashScreenState() {
	angle_rotation_ = 0;		
}

SplashScreenState::~SplashScreenState() {

}

SplashScreenState* SplashScreenState::Instance() {
	return (&splash_screen_state_);
}

bool SplashScreenState::init() {
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//angle_rotation_ = 0;

	return true;
}

void SplashScreenState::update(GameManager* game_manager, float elapsed_time) {
		
	const float SPEED = 15.0f;

	angle_rotation_ += SPEED * elapsed_time;
	if (angle_rotation_ > 360.0f)
		angle_rotation_ -= 360.0f;

}

void SplashScreenState::draw(GameManager* game_manager) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(angle_rotation_, 0, 0, 1);

	glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, -0.5f, -4.0f);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, -4.0f);
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
		glVertex3f(0.0f, 0.5f, -4.0f);
	glEnd();

}

void SplashScreenState::keyboardEvent(GameManager* game_manager, char key_pressed) {
	
	switch(key_pressed)
	{
		case VK_F1:
			changeState(game_manager, SplashScreenState::Instance());
			break;
	}

}

void SplashScreenState::onResize(GameManager* game_manager, int width, int height) {
	
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, float(width) / float(height), 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
