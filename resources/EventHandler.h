#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>

#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "knight.h"
#include"piece.h"
using namespace sf;

class EventHandler
{
	
    int clicked_piece;//to know clicked piece
    int row_no,col_no; //to know location of clicked piece:
    chessboard c1;
	pawn p1;
	rook r1;
	knight n1;
	bishop b1;
	queen q1;
	king k1;
	piece pi1;

	int moved[6]={0,0,0,0,0,0};  //0=whiteking, 1=blackking,2=leftblackrook, 3=rightblackrook, 4=leftwhiterook,5=rightwhiterook
	int can=0;    // which king can castle which side //1=w_left_side 2=w_right 3=b_left 4=b_right

	Texture tex;//to display pieces:
	Sprite sp;

	vector<vector<int>> current_possible;//to store the information of all possible moves of particular piece:

	bool white_castled =false;
	bool black_castled =false;

    Event event1;
		




   
public:

   //passing game window, game_array and base squares:
   void event_function(RenderWindow &window,int (&game_array)[8][8],RectangleShape (&square)[8][8],int (&clicked_square)[2]);
   
    


};//EventHandler class: