// laser.h
// Sam Battalio
// Lab 01

#ifndef laser_h
#define laser_h

#include "gfx2.h"

class Laser {
	public:
		Laser();
		Laser(int,int,int);
		~Laser();
		void update();
		void draw();
		void setDead();
		bool isDead();
		int getX();
		int getY();
		int getSize();
		static const int size = 10;
	private:
		int x,y;
		int dir;
		static const int speed = 11;
		bool dead;
};

#endif
