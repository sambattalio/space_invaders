// invader.h
// Sam Battalio
// Lab 01
// Header file for invader enemy
//
#ifndef invader_h
#define invader_h

#include "laser.h"

class Invader {
	public:
		Invader(int,int,int);
		~Invader();
		void draw();
		void move();
		bool checkCollision(Laser &laser);
		int moveTimer;
		int getX();
		int getY();
		static const int size = 3;
		static const int width = size * 11;
		static const int height = size * 8;
	private:
		int x,y; // top left x y
		int across;
		int moveCount;
		int dir;
		int animTimer;
		static const int R = 0, G = 255, B = 0;
};

#endif
