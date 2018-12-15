// player.h
// Sam Battalio
// Lab 01


#ifndef player_h
#define player_h

#include "gfx2.h"
#include "laser.h"
#include "invader.h"
#include <vector>

class Player {
	public:
		Player(int,int);
		~Player();
		void move(char);
		void update();
		void draw();
		void drawLives(int,int);
		bool isAlive();
		int getScore();
		void setScore();
		bool checkCollision(Laser &laser);
		int getTopY();
		Laser& getLaser();
	private:
		XPoint points[3];
		Laser laser;
		int score;
		int lives;
		int s_width;
		static const int size = 20;
		static const int speed = 10;
};

#endif
