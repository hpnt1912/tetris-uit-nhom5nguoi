#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
<<<<<<< Updated upstream
=======
#include <algorithm>
#include <random>
>>>>>>> Stashed changes
using namespace std;
 
#define H 22
#define W 12
 
// ===================== BOARD =====================
char board[H][W] = {};
 
// ===================== 7 BLOCKS (1 rotation set each) =====================
// M?i kh?i có 4 tr?ng thái xoay, m?i tr?ng thái là ma tr?n 4x4
// Index: 0=I, 1=O, 2=T, 3=S, 4=Z, 5=J, 6=L
char blocks[7][4][4][4] = {
    // 0: I - Cyan
    {{{' ',' ',' ',' '},
      {'I','I','I','I'},
      {' ',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','I',' ',' '},
      {' ','I',' ',' '},
      {' ','I',' ',' '},
      {' ','I',' ',' '}},
     {{' ',' ',' ',' '},
      {'I','I','I','I'},
      {' ',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','I',' ',' '},
      {' ','I',' ',' '},
      {' ','I',' ',' '},
      {' ','I',' ',' '}}},
 
    // 1: O - Yellow
    {{{' ',' ',' ',' '},
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
      {' ',' ',' ',' '}}},
 
    // 2: T - Purple
    {{{' ',' ',' ',' '},
      {'T','T','T',' '},
      {' ','T',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','T',' ',' '},
      {'T','T',' ',' '},
      {' ','T',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','T',' ',' '},
      {'T','T','T',' '},
      {' ',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','T',' ',' '},
      {' ','T','T',' '},
      {' ','T',' ',' '},
      {' ',' ',' ',' '}}},
 
    // 3: S - Green
    {{{' ',' ',' ',' '},
      {' ','S','S',' '},
      {'S','S',' ',' '},
      {' ',' ',' ',' '}},
     {{'S',' ',' ',' '},
      {'S','S',' ',' '},
      {' ','S',' ',' '},
      {' ',' ',' ',' '}},
     {{' ',' ',' ',' '},
      {' ','S','S',' '},
      {'S','S',' ',' '},
      {' ',' ',' ',' '}},
     {{'S',' ',' ',' '},
      {'S','S',' ',' '},
      {' ','S',' ',' '},
      {' ',' ',' ',' '}}},
 
    // 4: Z - Red
    {{{' ',' ',' ',' '},
      {'Z','Z',' ',' '},
      {' ','Z','Z',' '},
      {' ',' ',' ',' '}},
     {{' ','Z',' ',' '},
      {'Z','Z',' ',' '},
      {'Z',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ',' ',' ',' '},
      {'Z','Z',' ',' '},
      {' ','Z','Z',' '},
      {' ',' ',' ',' '}},
     {{' ','Z',' ',' '},
      {'Z','Z',' ',' '},
      {'Z',' ',' ',' '},
      {' ',' ',' ',' '}}},
 
    // 5: J - Blue
    {{{' ',' ',' ',' '},
      {'J','J','J',' '},
      {' ',' ','J',' '},
      {' ',' ',' ',' '}},
     {{' ','J',' ',' '},
      {' ','J',' ',' '},
      {'J','J',' ',' '},
      {' ',' ',' ',' '}},
     {{'J',' ',' ',' '},
      {'J','J','J',' '},
      {' ',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','J','J',' '},
      {' ','J',' ',' '},
      {' ','J',' ',' '},
      {' ',' ',' ',' '}}},
 
    // 6: L - Orange
    {{{' ',' ',' ',' '},
      {'L','L','L',' '},
      {'L',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{'L','L',' ',' '},
      {' ','L',' ',' '},
      {' ','L',' ',' '},
      {' ',' ',' ',' '}},
     {{' ',' ','L',' '},
      {'L','L','L',' '},
      {' ',' ',' ',' '},
      {' ',' ',' ',' '}},
     {{' ','L',' ',' '},
      {' ','L',' ',' '},
      {' ','L','L',' '},
      {' ',' ',' ',' '}}}
};
<<<<<<< Updated upstream

int x=4,y=0,b=1;
=======
 
// ===================== GAME STATE =====================
int px = 4, py = 0;      // v? trí kh?i hi?n t?i
int curBlock = 0;         // lo?i kh?i (0-6)
int curRot = 0;           // tr?ng thái xoay (0-3)
int score = 0;
bool gameOver = false;
 
// ===================== 7-BAG RANDOMIZER =====================
int bag[7];
int bagIdx = 7; // force refill on first use
 
void fillBag() {
    for (int i = 0; i < 7; i++) bag[i] = i;
    // Fisher-Yates shuffle
    for (int i = 6; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(bag[i], bag[j]);
    }
    bagIdx = 0;
}
 
int nextBlock() {
    if (bagIdx >= 7) fillBag();
    return bag[bagIdx++];
}
 
// ===================== HELPERS =====================
>>>>>>> Stashed changes
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
<<<<<<< Updated upstream
void boardDelBlock(){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            if (blocks[b][i][j] != ' ' && y+i < H)
                board[y+i][x+j] = ' ';
=======
void hideCursor() {
    CONSOLE_CURSOR_INFO ci = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
>>>>>>> Stashed changes
}
 
// ===================== BOARD =====================
void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (i == H-1 || j == 0 || j == W-1) board[i][j] = '#';
            else board[i][j] = ' ';
        }
}
<<<<<<< Updated upstream
=======
 
bool canPlace(int bType, int rot, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[bType][rot][i][j] != ' ') {
                int tx = bx + j;
                int ty = by + i;
                if (tx < 1 || tx >= W-1 || ty >= H-1) return false;
                if (ty >= 0 && board[ty][tx] != ' ') return false;
            }
    return true;
}
 
void placeOnBoard(int bType, int rot, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[bType][rot][i][j] != ' ') {
                int tx = bx + j, ty = by + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W)
                    board[ty][tx] = blocks[bType][rot][i][j];
            }
}
 
void clearFromBoard(int bType, int rot, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[bType][rot][i][j] != ' ') {
                int tx = bx + j, ty = by + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W)
                    board[ty][tx] = ' ';
            }
}
 
// Ghost piece: tính v? trí shadow (kh?i bóng)
int ghostY() {
    int gy = py;
    while (canPlace(curBlock, curRot, px, gy + 1)) gy++;
    return gy;
}
 
// ===================== DRAW =====================
>>>>>>> Stashed changes
void draw() {
    gotoxy(0, 0);
 
    // V? ghost piece
    int gy = ghostY();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[curBlock][curRot][i][j] != ' ') {
                int tx = px + j, ty = gy + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W && board[ty][tx] == ' ')
                    board[ty][tx] = '.'; // ghost marker
            }
 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char cell = board[i][j];
            if (cell == '#') {
                setColor(8);
                cout << "[]";
            } else if (cell == ' ') {
                setColor(8);
                cout << "  ";
            } else if (cell == '.') {
                setColor(8);  // ghost - xám nh?t
                cout << "::";
            } else {
                if      (cell == 'I') setColor(11);
                else if (cell == 'O') setColor(14);
                else if (cell == 'T') setColor(13);
                else if (cell == 'S') setColor(10);
                else if (cell == 'Z') setColor(12);
                else if (cell == 'J') setColor(9);
                else if (cell == 'L') setColor(6);
                cout << "[]";
            }
        }
        // Hi?n score ? bên ph?i
        if (i == 2) { setColor(15); cout << "  SCORE"; }
        if (i == 3) { setColor(14); cout << "  " << score; }
        if (i == 5) { setColor(15); cout << "  CONTROLS"; }
        if (i == 6) { setColor(7);  cout << "  A/D: Move"; }
        if (i == 7) { setColor(7);  cout << "  W: Rotate"; }
        if (i == 8) { setColor(7);  cout << "  S: Soft drop"; }
        if (i == 9) { setColor(7);  cout << "  Space: Hard drop"; }
        if (i == 10){ setColor(7);  cout << "  Q: Quit"; }
        cout << "\n";
    }
<<<<<<< Updated upstream
}
bool canMove(int dx, int dy){
    for (int i = 0 ; i < 4 ; i++)
        for (int j = 0 ; j < 4 ; j++)
            if (blocks[b][i][j] != ' '){
                int tx = x + j + dx;
                int ty = y + i + dy;
                if ( tx<1 || tx >= W-1 || ty >= H-1) return false;
                if ( board[ty][tx] != ' ') return false;
=======
 
    // Xóa ghost kh?i board sau khi v?
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (blocks[curBlock][curRot][i][j] != ' ') {
                int tx = px + j, ty = gy + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W && board[ty][tx] == '.')
                    board[ty][tx] = ' ';
>>>>>>> Stashed changes
            }
}
 
// ===================== REMOVE LINES =====================
void removeLines() {
    for (int i = H-2; i > 0; i--) {
        bool full = true;
        for (int j = 1; j < W-1; j++)
            if (board[i][j] == ' ') { full = false; break; }
        if (full) {
            score += 100;
            for (int ii = i; ii > 1; ii--)
                for (int j = 1; j < W-1; j++)
                    board[ii][j] = board[ii-1][j];
            for (int j = 1; j < W-1; j++) board[1][j] = ' ';
            i++; // ki?m tra l?i dòng này
        }
    }
}
 
// ===================== SPAWN =====================
bool spawnBlock() {
    curBlock = nextBlock();
    curRot = 0;
    px = W/2 - 2;
    py = 0;
    if (!canPlace(curBlock, curRot, px, py)) {
        gameOver = true;
        return false;
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
            _sleep(100);
        }
    }
}

int main()
{
    srand(time(0));
    b = rand() % 7;
=======
 
// ===================== GAME OVER SCREEN =====================
void showGameOver() {
    system("cls");
    setColor(12);
    cout << "\n\n";
    cout << "  ========================\n";
    cout << "       GAME  OVER!\n";
    cout << "  ========================\n";
    setColor(14);
    cout << "\n  Final Score: " << score << "\n\n";
    setColor(15);
    cout << "  Press any key to exit...\n";
    setColor(7);
    getch();
}
 
// ===================== MAIN =====================
int main() {
    srand((unsigned)time(0));
    hideCursor();
>>>>>>> Stashed changes
    system("cls");
    initBoard();
    spawnBlock();
 
    DWORD lastFall = GetTickCount();
    int fallInterval = 500; // ms m?i bu?c r?t xu?ng
 
    while (!gameOver) {
        // --- INPUT ---
        if (kbhit()) {
            char c = getch();
<<<<<<< Updated upstream
            if (c=='a' && canMove(-1,0)) x--;
            if (c=='d' && canMove(1,0) ) x++;
            if (c=='x' && canMove(0,1))  y++;
            if (c == 'w') rotateBlock();
            if (c=='q') break;
        }
        if (canMove(0,1)) y++;
        else {
            block2Board();
            removeLine();
            x = W/2; y = 0; b = rand() % 7;
=======
            clearFromBoard(curBlock, curRot, px, py);
 
            if (c == 'a' || c == 75) { // trái
                if (canPlace(curBlock, curRot, px-1, py)) px--;
            }
            else if (c == 'd' || c == 77) { // ph?i
                if (canPlace(curBlock, curRot, px+1, py)) px++;
            }
            else if (c == 's' || c == 80) { // soft drop
                if (canPlace(curBlock, curRot, px, py+1)) {
                    py++;
                    score++;
                    lastFall = GetTickCount();
                }
            }
            else if (c == ' ') { // HARD DROP
                int drop = 0;
                while (canPlace(curBlock, curRot, px, py+1)) { py++; drop++; }
                score += drop * 2;
                placeOnBoard(curBlock, curRot, px, py);
                removeLines();
                spawnBlock();
                lastFall = GetTickCount();
                placeOnBoard(curBlock, curRot, px, py);
                draw();
                continue;
            }
            else if (c == 'w') { // xoay
                int newRot = (curRot + 1) % 4;
                if (canPlace(curBlock, newRot, px, py)) curRot = newRot;
                // Wall kick don gi?n
                else if (canPlace(curBlock, newRot, px+1, py)) { curRot = newRot; px++; }
                else if (canPlace(curBlock, newRot, px-1, py)) { curRot = newRot; px--; }
            }
            else if (c == 'q') break;
 
            placeOnBoard(curBlock, curRot, px, py);
        }
 
        // --- AUTO FALL ---
        DWORD now = GetTickCount();
        if (now - lastFall >= (DWORD)fallInterval) {
            clearFromBoard(curBlock, curRot, px, py);
            if (canPlace(curBlock, curRot, px, py+1)) {
                py++;
            } else {
                placeOnBoard(curBlock, curRot, px, py);
                removeLines();
                spawnBlock();
                placeOnBoard(curBlock, curRot, px, py);
                draw();
                lastFall = GetTickCount();
                continue;
            }
            placeOnBoard(curBlock, curRot, px, py);
            lastFall = now;
>>>>>>> Stashed changes
        }
 
        // --- RENDER ---
        draw();
        Sleep(16); // ~60fps cap
    }
 
    if (gameOver) showGameOver();
    setColor(7);
    return 0;
}
