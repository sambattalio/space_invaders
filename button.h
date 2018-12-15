// button.h
// Sam Battalio
// Lab 01
// used for button handling on title page

class Button {
	public:
		Button(int,int,int,int, char *, char *, int);
		~Button();
		int checkClick(int,int,int);
		void draw();
	private:
		int x,y;
		int width, height;
		int state;
		int text_w, text_h;
		char font[20];
		char text[20];
};
