#ifndef OUTERMESDL_H_INCLUDED
#define OUTERMESDL_H_INCLUDED

/* ++ outermeSDL version 1.2 - last update 11/30/2017 ++

 error code -3; TTFs failed to load
 error code -2: SDL_ttf failed to initialize
 error code -1: SDL_img failed to initialize
  error code 0: No error
  error code 1: SDL system failed to initialize
  error code 2: Window could not be created
  error code 3: Renderer failed to initialize
  error code 4: TTF font failed to load
  error code 5: tilemap failed to load
  error code 6: Media could not load/optimize
*/

#define SDL_MAIN_HANDLED 1
#include "SDL/SDL.h"       //This is included because it's an SDL2 program... duh
#include "SDL/SDL_image.h" //This is included so we can use PNGs.
#include "SDL/SDL_ttf.h"   //This is included for text stuff
#include <stdio.h>         //This is included because it's fundamental always. Even if it ain't needed
#include <string.h>        //This is included for strncat and other string functions
#include <stdlib.h>        //This is included for calloc, rand(), and a lot of other stuff
#include <math.h>          //This is included for log10
#include <time.h>          //This is included for time() as the seed for rand()

#define bool char
#define false 0
#define true 1

#define boolString(bool) bool ? "true" : "false"

//#define SAVE_FILE_NAME "SAVUVUTU.bin"
//#define SAVE_FILE_LINES 54
//#define CONFIG_FILE_NAME "sorceryConfig.ini"
#define FONT_FILE_NAME "Px437_ITT_BIOS_X.ttf"
#define FRAMERATE 60
#define TILE_SIZE 32
#define WIDTH_IN_TILES 20
#define HEIGHT_IN_TILES 15

#define ANYWHERE_QUIT -1

typedef enum
{
    type_na,  //0
    type_chest,  //1
    type_npc,  //2
    type_boss,  //3
    type_player,  //4
} entityType;

typedef struct
{
    int x;  //
    int y;  //
    int w;  //
    int h;  //
    int tileIndex;  //
    SDL_Rect* clipRect;  // 16? bytes (4 ints)
    entityType type;
} sprite;

int initSDL(char* windowName, char* tilesetFilePath, char* fontFilePath, int windowWidth, int windowHeight, int fontSize);  //inits SDL and related stuff
bool loadIMG(char* imgPath, SDL_Texture** dest);  //loads an image from a file into a texture
bool loadTTFont(char* filePath, TTF_Font** dest, int sizeInPts);  //loads a .ttf file into an SDL font
int* loadTextTexture(char* text, SDL_Texture** dest, int maxW, SDL_Color color, int isBlended);  //loads a texture from inputted text
void initSprite(sprite* spr, int x, int y, int size, int tileIndex, entityType type);  //initializes a new sprite
void drawTilemap(int startX, int startY, int endX, int endY, bool updateScreen);  //draws a tilemap to the screen
void drawTile(int id, int xCoord, int yCoord, int width, SDL_RendererFlip flip);  //draws a tile to the screen
void drawText(char* input, int x, int y, int maxW, int maxH, SDL_Color color, bool render);  //draws text to the screen
SDL_Keycode waitForKey();  //waits for a player to press any key, returns the key that was pressed
void closeSDL();  //closes SDL and related stuff
int checkArrayForIVal(int value, int array[], size_t arraySize);  //finds an int in an int array
char* removeChar(char input[], char removing, size_t length, bool foreToBack);  //removes the the first specified character from a string
int createFile(char* filePath);  //creates a file if it doesn't exist; if it does, clears it out
bool checkFile(char* filePath, int desiredLines);  //checks if a file exists with a certain number of lines. 0 for any.
int appendLine(char* filePath, char* stuff);  //appends a line to a file
char* readLine(char* filePath, int lineNum, char** output);  //reads a certain line from a file

char* intToString(int value, char * result);  //turns inputted int into a string
int digits(int num);  //gets the number of digits an int has
int pwrOf10(int power);  //gets 10 ^ input
void freeThisMem(void** x);  //frees memory of any type/object/whatever and nulls its pointer.

SDL_Window* mainWindow;
SDL_Surface* mainScreen;
SDL_Texture* tilesetTexture;
SDL_Renderer* mainRenderer;
TTF_Font* mainFont;
int tilemap[HEIGHT_IN_TILES][WIDTH_IN_TILES];
bool canDrawTiles;
bool canDrawText;

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

#endif // OUTERMESDL_H_INCLUDED
