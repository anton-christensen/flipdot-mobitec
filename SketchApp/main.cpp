/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int scale = 20;
const int padding = 2;
const int SCREEN_WIDTH = 112*(scale+padding);
const int SCREEN_HEIGHT = 20*(scale+padding);
bool state[112][20];

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture( std::string path );

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
IPaddress ipaddress;
UDPsocket udpsock;


bool init() {
	bool success = true;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else {
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL ) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if(SDLNet_Init() < 0) {
					printf( "SDL_net could not initialize! SDL_net Error: %s\n", SDLNet_GetError() );
					success = false;
				}
				else {
					SDLNet_ResolveHost(&ipaddress, "flipdot.local", 1234);
					// create a UDPsocket on any available port (client)

					udpsock=SDLNet_UDP_Open(0);
					if(!udpsock) {
					    printf("SDLNet_UDP_Open: %s\n", SDLNet_GetError());
					    exit(2);
					}
				}
			}
		}
	}

	return success;
}

bool loadMedia() {
	return true;
}

void close() {
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems

	SDLNet_UDP_Close(udpsock);
	udpsock=NULL; 
	
	SDLNet_Quit();
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture( std::string path ) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else {
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

bool pointInRect(int x, int y, SDL_Rect rect) {
	return x >= rect.x && x <= rect.x+rect.w && y >= rect.y && y <= rect.y+rect.h;
}

bool setState(int x, int y, unsigned char state) {
	// create a new UDPpacket to hold 1024 bytes of data
	UDPpacket *packet;

	packet=SDLNet_AllocPacket(3);
	if(!packet) {
	    printf("SDLNet_AllocPacket: %s\n", SDLNet_GetError());
	    // perhaps do something else since you can't make this packet
	}
	else {
		packet.data[0] = x;
		packet.data[1] = y;
		packet.data[2] = 0;
	    // do stuff with this new packet
	    // SDLNet_FreePacket this packet when finished with it
	}

	
	// send a packet using a UDPsocket, using the packet's channel as the channel
	//UDPsocket udpsock;
	//UDPpacket *packet;
	int numsent;

	numsent=SDLNet_UDP_Send(udpsock, packet->channel, packet);
	if(!numsent) {
	    printf("SDLNet_UDP_Send: %s\n", SDLNet_GetError());
	    // do something because we failed to send
	    // this may just be because no addresses are bound to the channel...
	}
}

int main( int argc, char* args[] ) {
	//Start up SDL and create window
	if( !init() ) {
		printf( "Failed to initialize!\n" );
	}
	else {
		//Load media
		if( !loadMedia() )
			printf( "Failed to load media!\n" );
		else {	
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while( !quit ) {
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 ) {
					//User requests quit
					if( e.type == SDL_QUIT )
						quit = true;
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0x44, 0x44, 0x44, 0xFF );
				SDL_RenderClear( gRenderer );

				int x, y;
				Uint32 mouseState = SDL_GetMouseState(&x, &y);
				
				//Render red filled quad
				for(int i = 0; i < 112; i++)
					for(int j = 0; j < 20; j++)
					{
						if(mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE)) {
							for(int I = 0; I < 112; I++)
								for(int J = 0; J < 20; J++)
									state[I][J] = 0;
						}
						SDL_Rect fillRect = { i*(scale+padding), j*(scale+padding), scale, scale };
						if(pointInRect(x,y,fillRect)) {
							if(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT)) {
								state[i][j] = true;
								SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
							}
							else if(mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT)) {
								state[i][j] = false;
								SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );		
							}
							else
								SDL_SetRenderDrawColor( gRenderer, 0x88, 0x88, 0x88, 0xFF );		
						}
						else {
							if(state[i][j])
								SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );		
							else
								SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );		
						}


						SDL_RenderFillRect( gRenderer, &fillRect );
					}

				//Update screen
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
