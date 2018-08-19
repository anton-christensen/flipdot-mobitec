#ifndef __FLIP_TETRIS__
#define __FLIP_TETRIS__

#include "screenprogram.h"
#include <Arduino.h>

class FlipTetris : public ScreenProgram {
  private:
    unsigned long lastUpdate;
    unsigned char placedBlocks[PANEL_HEIGHT][PANEL_WIDTH];
    unsigned char currentPiece[4][4];
    int x,y;
    bool running;

  public:

    FlipTetris(FlipScreen* _sign) : ScreenProgram(_sign) {
	    lastUpdate = 0;
	    running = true;
    }

    void start() {
		sign->clear();
		sign->flip();

		for(int i = 0; i < PANEL_HEIGHT; i++) {
			for(int j = 0; j < PANEL_WIDTH; j++) {
				placedBlocks[i][j] = BLACK;
			}
		}

		newPiece();
    }

    void stop() {
    	sign->clear();
    }

    void loop(char* input) {

    	if(input != NULL && strcmp(" ", input) == 0)
    		rotatePiece();
    	if(input != NULL && strcmp("left", input) == 0)
    		move(-1,0);
    	if(input != NULL && strcmp("right", input) == 0)
    		move(1,0);

    	if(millis()-lastUpdate > 100) {
	    	lastUpdate = millis();
			move(0,1);
			render();
    	}

    }


    void render() {
    	for(int i = 0; i < PANEL_HEIGHT; i++)
    		for(int j = 0; j < PANEL_WIDTH; j++)
    			sign->putPixel(j,i,placedBlocks[i][j]);
		for(int i = 0; i < 4; i++)
    		for(int j = 0; j < 4; j++)
    			if(currentPiece[i][j] == WHITE)
    			sign->putPixel(j+y,i+x,currentPiece[i][j]);
    	sign->flip();
    }

    void move(int _x, int _y) {
    	if(collision(_x, _y)) {
			if(_y == 1) {
				if(y < 1) {
					//you lose!  new game.
					running = false;
				}
				else {
					int i,j;
					//new block time! add this one to the list!
					for(i=0; i<4; i++)
						for(j=0; j<4; j++)
							if(currentPiece[i][j] != BLACK)
								placedBlocks[x+i][y+j] = currentPiece[i][j];

					//check for cleared row!
					for(j=0; j < PANEL_WIDTH; j++) {
						bool filled=true;
						for(i=0; i < PANEL_HEIGHT; i++)
							if(placedBlocks[i][j] == BLACK)
								filled=false;

						if(filled) {
							removeRow(j);
						}
					}
					newPiece();
				}
			}
		}
		else {
			x += _x;
			y += _y;
		}
    }
    bool collision(int nx, int ny) {
		int px=x+nx;
		int py=y+ny;

		int i,j,_x,_y;

		for(i=0; i< 4; i++)
			for(j=0; j< 4; j++)
				if(currentPiece[i][j] != BLACK)
					if(px + i < 0 || px + i > PANEL_HEIGHT -1||
						py + j < 0 || py + j > PANEL_WIDTH -1)
						return true;

		for(_x=0; _x< PANEL_HEIGHT; _x++)
			for(_y=0; _y< PANEL_WIDTH; _y++)
				if(_x >= px && _x < px + 4)
					if(_y >= py && _y < py +4)
						if(placedBlocks[_x][_y] != BLACK)
							if(currentPiece[_x - px][_y - py] != BLACK)
								return true;

		return false;
	}
	void removeRow(int row) {
		int _x,_y;

		for(_y=row; _y>0; _y--)
			for(_x=0; _x < PANEL_HEIGHT; _x++)
				placedBlocks[_x][_y]=placedBlocks[_x][_y-1];
	}
    void rotatePiece() {
    	int i, j, temp[4][4];

		//copy &rotate the piece to the temporary array
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				temp[3-j][i]=currentPiece[i][j];

		//check collision of the temporary array with map borders
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				if(temp[i][j] != BLACK)
					if(x + i < 0 || x + i > PANEL_HEIGHT - 1 ||
						y + j < 0 || y + j > PANEL_WIDTH - 1)
						return;

		//check collision of the temporary array with the blocks on the map
		for(int _x=0; _x< PANEL_HEIGHT; _x++)
			for(int _y=0; _y< PANEL_WIDTH; _y++)
				if(_x >= x && _x < x + 4)
					if(_y >= y && _y < y +4)
						if(placedBlocks[x][y] != BLACK)
							if(temp[_x - x][_y - y] != BLACK)
								return;

		//end collision check

		//successful!  copy the rotated temporary array to the original piece
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				currentPiece[i][j]=temp[i][j];
    }

    void newPiece() {
    	for(int i = 0; i < 4; i++)
    		for(int j = 0; j < 4; j++)
    			currentPiece[i][j] = BLACK;

    	x = PANEL_HEIGHT / 2 - 2;
		y = -1;

		int newblock = rand()%7;

		switch (newblock)
		{
		case 0: //Tower!
			{
				currentPiece[1][0]=WHITE;
				currentPiece[1][1]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[1][3]=WHITE;
				y=0;
			}break;
		case 1: //Box!
			{
				currentPiece[1][1]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[2][1]=WHITE;
				currentPiece[2][2]=WHITE;
			}break;
		case 2: //Pyramid!
			{
				currentPiece[1][1]=WHITE;
				currentPiece[0][2]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[2][2]=WHITE;
			}break;
		case 3://Left Leaner
			{
				currentPiece[0][1]=WHITE;
				currentPiece[1][1]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[2][2]=WHITE;
			}break;
		case 4://Right Leaner
			{
				currentPiece[2][1]=WHITE;
				currentPiece[1][1]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[0][2]=WHITE;
			}break;
		case 5://Left Knight
			{
				currentPiece[1][1]=WHITE;
				currentPiece[2][1]=WHITE;
				currentPiece[2][2]=WHITE;
				currentPiece[2][3]=WHITE;
			}break;
		case 6://Right Knight
			{
				currentPiece[2][1]=WHITE;
				currentPiece[1][1]=WHITE;
				currentPiece[1][2]=WHITE;
				currentPiece[1][3]=WHITE;
			}break;
		}
    }

};

#endif