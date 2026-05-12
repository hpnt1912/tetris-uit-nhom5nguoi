#include <iostream>
#include <conio.h>
#include <windows.h>
<<<<<<< Updated upstream
#include <ctime>
=======
>>>>>>> Stashed changes
using namespace std;
#define H 20
#define W 15
char board[H][W] = {} ;
char blocks[][4][4] = {
        {{' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '}},
        {{' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '},
         {' ','I',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'I','I','I','I'},
         {' ',' ',' ',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','O','O',' '},
         {' ','O','O',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','T',' ',' '},
         {'T','T','T',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ','S','S',' '},
         {'S','S',' ',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'Z','Z',' ',' '},
         {' ','Z','Z',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {'J',' ',' ',' '},
         {'J','J','J',' '},
         {' ',' ',' ',' '}},
        {{' ',' ',' ',' '},
         {' ',' ','L',' '},
         {'L','L','L',' '},
         {' ',' ',' ',' '}}
};

int x=4,y=0,b=1;
<<<<<<< Updated upstream
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
=======
>>>>>>> Stashed changes
void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void boardDelBlock(){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
<<<<<<< Updated upstream
            if (blocks[b][i][j] != ' ' && y+i < H)
=======
            if (blocks[b][i][j] != ' ' && y+j < H)
>>>>>>> Stashed changes
                board[y+i][x+j] = ' ';
}
void block2Board(){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            if (blocks[b][i][j] != ' ' )
                board[y+i][x+j] = blocks[b][i][j];
}
void initBoard(){
    for (int i = 0 ; i < H ; i++)
        for (int j = 0 ; j < W ; j++)
            if ((i==H-1) || (j==0) || (j == W-1)) board[i][j] = '#';
            else board[i][j] = ' ';
}
<<<<<<< Updated upstream
void draw() {
    gotoxy(0, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char cell = board[i][j];
            if (cell == '#') {
                setColor(8); // Màu xám cho tường
                cout << "[]";
            }
            else if (cell == ' ') {
                cout << "  "; // Hai dấu cách để tạo ô vuông trống
            }
            else {
                // Đặt màu dựa trên ký tự khối (I, O, T, S, Z, J, L)
                if (cell == 'I') setColor(11); // Cyan
                else if (cell == 'O') setColor(14); // Yellow
                else if (cell == 'T') setColor(13); // Purple
                else if (cell == 'S') setColor(10); // Green
                else if (cell == 'Z') setColor(12); // Red
                else if (cell == 'J') setColor(9);  // Blue
                else if (cell == 'L') setColor(6);  // Orange

                cout << "[]"; // Vẽ khối bằng cặp ngoặc vuông cho rõ
            }
        }
        cout << endl;
    }
=======
void draw(){
    gotoxy(0,0);
    for (int i = 0 ; i < H ; i++, cout<<endl)
        for (int j = 0 ; j < W ; j++)
            cout<<board[i][j];
>>>>>>> Stashed changes
}
bool canMove(int dx, int dy){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            if (blocks[b][i][j] != ' '){
                int tx = x + j + dx;
                int ty = y + i + dy;
                if ( tx<1 || tx >= W-1 || ty >= H-1) return false;
                if ( board[ty][tx] != ' ') return false;
            }
    return true;
}
<<<<<<< Updated upstream
void rotateBlock() {
    char temp[4][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            temp[j][3 - i] = blocks[b][i][j];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (temp[i][j] != ' ') {
                int tx = x + j, ty = y + i;
                if (tx < 1 || tx >= W - 1 || ty >= H - 1 || board[ty][tx] != ' ') 
                    return; 
            }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            blocks[b][i][j] = temp[i][j];
}
=======
>>>>>>> Stashed changes
void removeLine(){
    int j;
    for (int i = H-2; i >0 ; i-- ){
        for (j = 0; j < W-1 ; j++)
            if (board[i][j] == ' ') break;
        if (j == W-1){
            for (int ii = i; ii >0 ; ii-- )
                for (int j = 0; j < W-1 ; j++ ) board[ii][j] = board[ii-1][j];
            i++;
            draw();
<<<<<<< Updated upstream
            _sleep(100);
=======
            _sleep(200);
>>>>>>> Stashed changes
        }
    }
}

int main()
{
    srand(time(0));
    b = rand() % 7;
    system("cls");
    initBoard();
    while (1){
        boardDelBlock();
        if (kbhit()){
            char c = getch();
            if (c=='a' && canMove(-1,0)) x--;
            if (c=='d' && canMove(1,0) ) x++;
            if (c=='x' && canMove(0,1))  y++;
<<<<<<< Updated upstream
            if (c == 'w') rotateBlock();
=======
>>>>>>> Stashed changes
            if (c=='q') break;
        }
        if (canMove(0,1)) y++;
        else {
            block2Board();
            removeLine();
<<<<<<< Updated upstream
            x = W/2; y = 0; b = rand() % 7;
        }
        block2Board();
        draw();
        _sleep(300);
    }
    return 0;
}
=======
            x = 5; y = 0; b = rand() % 7;
        }
        block2Board();
        draw();
        _sleep(200);
    }
    return 0;
}
>>>>>>> Stashed changes
