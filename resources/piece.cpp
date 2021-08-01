#include "piece.h"

void piece::copy_to_2dvector(vector<vector<int>> &current_possible,int row,int col,int can_kill)
{
    vector<int> temp;
    temp.push_back(row);
    temp.push_back(col);
    temp.push_back(can_kill);
    current_possible.push_back(temp);
}

//cheking if the left of the king upto rook is nothing for castling
void piece:: check_left(RenderWindow& window,int(&game_array)[8][8],int row,int col,RectangleShape (&square)[8][8],int &can){
    int count =0;
    for(int i =1;i<4;i++){
        if(game_array[row][col-i]== 0){
            count++;
        }//if closed
    }//for loop closed
    if(count==3){    //there is no pieces in between king and rook in left
        square[row][col-2].setFillColor(Color::Yellow);
        window.draw(square[row][col-2]);
     can=1;    //it says castling is possible
    }
}


//cheking if the right of the king upto rook is nothing for castling
void piece:: check_right(RenderWindow& window,int(&game_array)[8][8],int row,int col,RectangleShape (&square)[8][8],int &can){
    int count =0;
    for(int i =1;i<3;i++){
        if(game_array[row][col+i]== 0){
            count++;
        }//if closed
    }//for loop closed
    if(count==2){       ////there is no pieces in between king and rook in right
        square[row][col+2].setFillColor(Color::Yellow);
        window.draw(square[row][col+2]);
       can=1;      //it says castling is possible
    }
}
//check if any rook or king moved: if moved, stores 1 as follows
void piece:: check_if_moved(int piece_no,int coll,int (& moved)[6]){
    if(piece_no==-1 && coll == 0){
        moved[2]=1;   // left black rook is moved
        
    }
    if(coll==7 && piece_no==-1){
        moved[3]=1;       // right black rook is moved
    }
    if(piece_no==1 && coll==0){
        moved[4]=1;      //left white rook is moved
    }
    if(piece_no==1 && coll==7){
        moved[5]=1;     //;right white rook is moved
    }
    if(piece_no==5){
        moved[0]=1;      //white king is moved
    }
    if(piece_no==-5){
        moved[1]=1;    //black king is moved
     
    }
}

//for actual castling
void piece:: do_castle(int row,int col,int (&game_array)[8][8],int p){ //p=piece_no.
    game_array[row][4]=0;
    int rok,c1,c2;   //r =rook,c1= assigns column for king,c2 =assigns col for rook
    if(p>0){
        rok=1;     //white rook
    }else{
        rok=-1;   //black rook
    }
    if(col>5){     //for right no matter black or white
        c1=6;    
        c2=5;
    }else{      //for right no matter black or white
        c1=2;
        c2=3;
    }
    if(col<5){   //left castling is done
        game_array[row][0]=0;
        game_array[row][c1]=p;
        game_array[row][c2]=rok;
    }if(col>5){   //right castling is done
        game_array[row][7]=0;
        game_array[row][c1]=p;
        game_array[row][c2]=rok;
    }
}