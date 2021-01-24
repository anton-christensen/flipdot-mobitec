#ifndef __FLIP_SNAKE__
#define __FLIP_SNAKE__

#include "screenprogram.h"
#include <Arduino.h>
#include <queue>

class FlipSnake : public ScreenProgram {
  private:
    unsigned long lastUpdate;
    bool running;

    enum direction{up, down, left, right};

    std::queue<int> inputQueue;


    int length = 4;
    int direction = right;
    unsigned short pos;
    unsigned short foodPos = 0xFFFF;
    unsigned short body[PANEL_HEIGHT*PANEL_WIDTH];

  public:

    FlipSnake(FlipScreen* _sign) : ScreenProgram(_sign) {
		while(!inputQueue.empty()) inputQueue.pop();
		reset();
    }

	void reset() {
	    lastUpdate = 0;
	    running = true;
	   	
	   	pos = (PANEL_WIDTH/2) << 8 | (PANEL_HEIGHT/2);
	    for(int i = 0; i < length; i++) {
	    	body[i] = pos;
	    }
	    for(int i = length; i < PANEL_WIDTH*PANEL_HEIGHT; i++) {
	    	body[i] = 0xFFFF;
	    }

	    foodPos = random(PANEL_WIDTH) << 8 | random(PANEL_HEIGHT);
		sign->clear();
	    sign->putPixel(foodPos >> 8, foodPos & 0xFF, WHITE);
	}

    void start() {
		sign->clear();
		sign->flip();

	    sign->putPixel(foodPos >> 8, foodPos & 0xFF, WHITE);
    }

    void stop() {
    	sign->clear();
    }

    void loop(char* input) {
    	if(running) {
	    	if(input != NULL && strcmp("up", input) == 0 && (inputQueue.empty() ? direction != down : inputQueue.back() != down))
	    		inputQueue.push(up);
	    	if(input != NULL && strcmp("down", input) == 0 && (inputQueue.empty() ? direction != up : inputQueue.back() != up))
	    		inputQueue.push(down);
	    	if(input != NULL && strcmp("left", input) == 0 && (inputQueue.empty() ? direction != right : inputQueue.back() != right))
	    		inputQueue.push(left);
	    	if(input != NULL && strcmp("right", input) == 0 && (inputQueue.empty() ? direction != left : inputQueue.back() != left))
	    		inputQueue.push(right);

	    	if(millis()-lastUpdate > 100-length) {
				if(!inputQueue.empty()) {
					direction = inputQueue.front();
					inputQueue.pop();
				}

		    	lastUpdate = millis();
				move();
				if(gotfood()) {
					// move food
				    foodPos = random(PANEL_WIDTH) << 8 | random(PANEL_HEIGHT);
				    sign->putPixel(foodPos >> 8, foodPos & 0xFF, WHITE);

					// increase length
				    length++;
				}
				if(hitBody()) {
					// blink
					// show score
					sign->clear();
					sign->write("GAME OVER");
					running = false;
				}
				sign->flip();
	    	}
    	}
		else {
			if(input != NULL)
				reset();
		}
    }

    void move() {
    	int x = pos >> 8;
    	int y = pos & 0xFF;

    	switch(direction) {
    		case up:
    			y--;
    			if(y < 0) y+= PANEL_HEIGHT;
    			break;
    		case down:
    			y++;
    			if(y >= PANEL_HEIGHT) y-= PANEL_HEIGHT;
    			break;
    		case right:
    			x++;
    			if(x >= PANEL_WIDTH) x-= PANEL_WIDTH;
    			break;
    		case left:
    			x--;
    			if(x < 0) x+= PANEL_WIDTH;
    			break;
    	}
    	pos = x << 8 | (y & 0xFF);


    	sign->putPixel(body[length-1] >> 8, body[length-1] & 0xFF, BLACK);
    	for(int i = length-1; i > 0; i--) {
    		body[i] = body[i-1];
	    	sign->putPixel(body[i] >> 8, body[i] & 0xFF, WHITE);
    	}
    	body[0] = pos;
	    sign->putPixel(pos >> 8, pos & 0xFF, WHITE);
    }
    bool hitBody() {
    	for(int i = 1; i < length; i++) {
    		if(body[i] == pos)
    			return true;
    	}
    	return false;
	}
	bool gotfood() {
	    return pos == foodPos;
	}
};

#endif