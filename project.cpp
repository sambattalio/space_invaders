// project.cpp
// Sam Battalio
// Final project basically just space invaders but i made it

#include <iostream>
#include <unistd.h>
#include <vector>
#include <stdio.h> // sprintf
#include "gfx2.h"
#include "invader.h" // ADD the INCIF / ANIMATE
#include "player.h"
#include "laser.h"
#include "invaderClump.h"
#include "button.h"
using namespace std;

int main()
{
	// Init variables
	char c;
	int event;
	int old_score;
	// set screen dimensions
	const int width = 600, height = 500;
	// Set state variables
	const int MENU = 0, GAME = 1, OVER = 2, QUIT = 3;
	int state = MENU;

	// init score char array
	char c_score[6];

	// open window
	gfx_open(width,height, "Space Invaders");

	// init player and invaders class
	Player player(width,height);
	InvaderClump invaders(9,5);

	// set fonts for title and button
	char title_font[] = "12x24";
	char button_font[] = "6x13";

	// setup title variables
	char title[] = "Space Invaders";
	int title_w = gfx_textpixelwidth(title, title_font);
	int title_h = gfx_textpixelheight(title,title_font);

	// init buttons for main menu
	Button title_button(width / 2, height / 2, 100,50, (char*)"Start", button_font, GAME);
	Button quit_button(width / 2, height / 2 + 60, 100, 50, (char*)"Quit", button_font, QUIT);

	// Loop until game over
	while(true) {
		gfx_clear(); // clear previous draw
		if(state == MENU) { // if on menu
			gfx_changefont(title_font);
			gfx_text(width / 2 - title_w / 2, height / 4 - title_h / 2, title);
			title_button.draw();
			quit_button.draw();

			event = gfx_event_waiting();
			if (event != 0 ) {
				c = gfx_wait();
				if(c == 1){
					state = title_button.checkClick(MENU,gfx_xpos(), gfx_ypos());
					if(state == MENU)
						state = quit_button.checkClick(MENU,gfx_xpos(), gfx_ypos());
				}
				else if (c == 27) break;
			}
			gfx_flush();
			usleep(25000);
		}
		else if (state == GAME) { // if in game
			// Print score 
			gfx_text(0,10, "Score: ");
			sprintf(c_score, "%.1i",player.getScore());
			gfx_text(40,10,c_score);

			// show lives
			gfx_text(100,10,"Lives: ");
			player.drawLives(140,6);

			invaders.draw();
			player.draw(); // draw player

			// update
			player.update(); // update player's laser
			player.checkCollision(invaders.getLaser()); // check if hit
			if(invaders.update(player.getLaser())) // update invaders / check if hit
				player.setScore(); // if hit update score
			invaders.shoot(); // shoot if can for invader

			// check if won;
			if (invaders.dead()) // if all invaders gone reset
				state = OVER;
			// check if lost
			if (invaders.hitBottom(player.getTopY()) || !player.isAlive()) // if player lost reset
				state = OVER;

			if(state == OVER)
				old_score = player.getScore();

			// GET INPUT
			if(gfx_event_waiting()) {
				c = gfx_wait();

				player.move(c); // move player based on input

				if (c == 27) break;
			}
			gfx_flush();
			usleep(25000); // sleep
		} else if (state == OVER) { //reset
			player = Player(width, height);
			invaders = InvaderClump(9,5);

			state = MENU;
		} else if (state == QUIT) { // break if quit
			break;
		}	else {
			state = MENU;
		}
	}

	return 0;
}
