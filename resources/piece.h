#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include<vector>
using namespace std;

using namespace sf;

class piece
{
  public:
  void copy_to_2dvector(vector<vector<int>> &current_possible,int row,int col,int can_kill);
  void check_left(RenderWindow& window,int(&game_array)[8][8],int row,int col,RectangleShape (&square)[8][8],int &can);
  void check_right(RenderWindow& window,int(&game_array)[8][8],int row,int col,RectangleShape (&square)[8][8],int &can);
  //check if any rook or king moved
  void check_if_moved(int piece_no,int row,int (& moved)[6]);
  //for actual casling
  void do_castle(int row,int col,int (&game_array)[8][8],int p);
};