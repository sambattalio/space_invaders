// invaderClump.h
// Sam Battalio
// Lab 01
// Header for invaderClump
// Hodls all invaders in a vector
#ifndef invaderClump_h
#define invaderClump_h

#include "invader.h"
#include "laser.h"
using namespace std;

class InvaderClump {
	public:
		InvaderClump(int,int);
		~InvaderClump();
		bool update(Laser& laser);
		void draw();
		void shoot();
		bool dead();
		bool hitBottom(int);
		Laser& getLaser();
	private:
		vector<Invader> invaders;
		Laser laser;
};

#endif
