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
	char c;
	int event;
	const int width = 600, height = 500;
	const int MENU = 0, GAME = 1, OVER = 2;
	int state = MENU;
	char c_score[6];
	gfx_open(width,height, "Space Invaders");

	Player player(width,height);

	InvaderClump invaders(9,5);

	char title_font[] = "12x24";
	char button_font[] = "6x13";

	char title[] = "Space Invaders";
	int title_w = gfx_textpixelwidth(title, title_font);
	int title_h = gfx_textpixelheight(title,title_font);

	Button title_button(width / 2, height / 2, 100,50, "Start", button_font, GAME);

	gfx_changefont(title_font);

	while(true) {
		gfx_clear();
		if(state == MENU) {
			gfx_changefont(title_font);
			gfx_text(width / 2 - title_w / 2, height / 4 - title_h / 2, title);
			title_button.draw();

			event = gfx_event_waiting();
			if (event != 0 ) {
				c = gfx_wait();
				if(c == 1)
					state = title_button.checkClick(MENU,gfx_xpos(), gfx_ypos());
				else if (c == 'q') break;
			}
			gfx_flush();
			usleep(25000);
		}
		else if (state == GAME) {
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
			player.update(); // update player 
			player.checkCollision(invaders.getLaser());
			if(invaders.update(player.getLaser()))
				player.setScore();
			invaders.shoot();

			// check if lost
			if (invaders.hitBottom(player.getTopY()) || !player.isAlive())
				state = OVER;

			// GET INPUT
			cout << gfx_event_waiting() << endl;
			if(gfx_event_waiting()) {
				cout << "event" << endl;
				c = gfx_wait();

				player.move(c);

				if (c == 'q') break;
			}
			gfx_flush();
			usleep(25000);
			gfx_flush();
		} else if (state == OVER) { // Reset on loss
				player = Player(width, height);
				invaders = InvaderClump(9,5);
				state = MENU;
		} else {
			state = MENU;
		}
	}

	return 0;
}
