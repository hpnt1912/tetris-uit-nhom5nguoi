#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;
 
#define H 22
#define W 12
char board[H][W]; //game boarch luu trang thai cac o
//code nguoi 1
//class cha cho tat ca cac block tetris
class Piece {
public:
	int x, y, rot; //x: vi tri ngang, y: vi tri doc, rot: trang thai xoay (0-3)
	
	//contructor: block moi spawn o phia tren
	Piece() : x(4), y(0), rot(0) {}
	
	//ham xoay block
	virtual void rotate() = 0;
	//ve block len board
	virtual char getShape(int i, int j) = 0;
	
	//destructor giai phong con tro da hinh
	virtual ~Piece() {}
};

//code nguoi 2
// ===== DERIVED PIECES =====

//block I
class IPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
        static char shape[4][4][4] = {
            {
                {' ',' ',' ',' '},
                {'I','I','I','I'},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','I',' ',' '},
                {' ','I',' ',' '},
                {' ','I',' ',' '},
                {' ','I',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {'I','I','I','I'},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','I',' ',' '},
                {' ','I',' ',' '},
                {' ','I',' ',' '},
                {' ','I',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

//block O
class OPiece : public Piece {
public:
    void rotate() override {
        rot = 0;
    }

    char getShape(int i, int j) override {
        static char shape[4][4][4] = {
            {
                {' ',' ',' ',' '},
                {' ','O','O',' '},
                {' ','O','O',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {' ','O','O',' '},
                {' ','O','O',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {' ','O','O',' '},
                {' ','O','O',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {' ','O','O',' '},
                {' ','O','O',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

//block T
class TPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
        static char shape[4][4][4] = {
            {
                {' ',' ',' ',' '},
                {'T','T','T',' '},
                {' ','T',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','T',' ',' '},
                {'T','T',' ',' '},
                {' ','T',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','T',' ',' '},
                {'T','T','T',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','T',' ',' '},
                {' ','T','T',' '},
                {' ','T',' ',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

//block S
class SPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
    	static char shape[4][4][4] = {
        {
                {' ',' ',' ',' '},
                {' ','S','S',' '},
                {'S','S',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'S',' ',' ',' '},
                {'S','S',' ',' '},
                {' ','S',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {' ','S','S',' '},
                {'S','S',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'S',' ',' ',' '},
                {'S','S',' ',' '},
                {' ','S',' ',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

//block Z
class ZPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
    	static char shape[4][4][4] = {
        {
                {' ',' ',' ',' '},
                {'Z','Z',' ',' '},
                {' ','Z','Z',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ','Z',' '},
                {' ','Z','Z',' '},
                {' ','Z',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ',' ',' '},
                {'Z','Z',' ',' '},
                {' ','Z','Z',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ','Z',' '},
                {' ','Z','Z',' '},
                {' ','Z',' ',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

//block J
class JPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
    	static char shape[4][4][4] = {
        {
                {' ',' ',' ',' '},
                {'J','J','J',' '},
                {' ',' ','J',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','J',' ',' '},
                {' ','J',' ',' '},
                {'J','J',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'J',' ',' ',' '},
                {'J','J','J',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','J','J',' '},
                {' ','J',' ',' '},
                {' ','J',' ',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

class LPiece : public Piece {
public:
    void rotate() override {
        rot = (rot + 1) % 4;
    }

    char getShape(int i, int j) override {
        static char shape[4][4][4] = {
        {
                {' ',' ',' ',' '},
                {'L','L','L',' '},
                {'L',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {'L','L',' ',' '},
                {' ','L',' ',' '},
                {' ','L',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ',' ','L',' '},
                {'L','L','L',' '},
                {' ',' ',' ',' '},
                {' ',' ',' ',' '}
            },
            {
                {' ','L',' ',' '},
                {' ','L',' ',' '},
                {' ','L','L',' '},
                {' ',' ',' ',' '}
            }
        };

        return shape[rot][i][j];
    }
};

// ===== END DERIVED PIECES =====
 
// ===================== GAME STATE =====================
int px = 4, py = 0;      // v? trí kh?i hi?n t?i
Piece* curPiece = nullptr; //block hien tai dang roi
int score = 0; //diem hien tai
bool gameOver = false; //trang thai game
 int fallInterval = 500; //toc do roi (ms)
// ==========int fallInterval = 500;=========== 7-BAG RANDOMIZER =====================
int bag[7]; //random 7 block
int bagIdx = 7; // force refill on first use, refill luc khoi tao
 
 //tao lai 7 block va cho ra ngau nhien
void fillBag() {
    for (int i = 0; i < 7; i++) bag[i] = i;
    // Fisher-Yates shuffle
    for (int i = 6; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(bag[i], bag[j]);
    }
    bagIdx = 0;
}
 
//tao dung cac loai block
Piece* createPiece(int type) {
    switch(type) {
    case 0: return new IPiece();
    case 1: return new OPiece();
    case 2: return new TPiece();
    case 3: return new SPiece();
    case 4: return new ZPiece();
    case 5: return new JPiece();
    case 6: return new LPiece();
    }
    return nullptr;
}

//lay block tiep theo tu bag
Piece* nextBlock() {
    if (bagIdx >= 7) fillBag();
    return createPiece(bag[bagIdx++]);
}
 
// ===================== HELPERS =====================
//doi mau
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//dua con tro toi vi tri x,y
void gotoxy(int x, int y) {
    COORD c = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//an con tro
void hideCursor() {
    CONSOLE_CURSOR_INFO ci = {1, FALSE};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ci);
}
 
// ===================== BOARD =====================
//khoi tao board va tuong bao quanh
void initBoard() {
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (i == H-1 || j == 0 || j == W-1) board[i][j] = '#';
            else board[i][j] = ' ';
        }
}
//kiem tra block co dat hop le tai vi tri moi ko
bool canPlace(Piece* piece, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (curPiece->getShape(i,j) != ' ') {
                int tx = bx + j;
                int ty = by + i;
                if (tx <= 0 || tx >= W-1 || ty >= H-1)return false;
                if (ty >= 0 && board[ty][tx] != ' ') return false;
            }
    return true;
}
//ve block len board
void placeOnBoard(Piece* piece, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){
            char shapeChar = piece->getShape(i, j);
            if (shapeChar != ' ') {
                int tx = bx + j, ty = by + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W)
                    board[ty][tx] = shapeChar;
            }
        }
}
//xoa block tam thoi de tinh toan di chuyen
void clearFromBoard(Piece* piece, int bx, int by) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (piece->getShape(i, j) != ' ') {
                int tx = bx + j, ty = by + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W)
                    board[ty][tx] = ' ';
            }
}
 
//tim vi tri cuoi cung cua block
int ghostY() {
    int gy = py;
    while (canPlace(curPiece, px, gy + 1)) gy++;
    return gy;
}
 
//code am thanh cho game
void moveSound() {
    Beep(700, 30);
}

void rotateSound() {
    Beep(1000, 50);
}

void clearLineSound() {
    Beep(1200, 80);
    Beep(1400, 80);
}

void dropSound() {
    Beep(500, 60);
}

void gameOverSound() {
    Beep(400, 200);
    Beep(300, 200);
    Beep(200, 300);
}

// ===================== DRAW =====================
//render toan bo giao dien game
void draw() {
    gotoxy(0, 0);
    setColor(7);
    // V? ghost piece
    int gy = ghostY();
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (curPiece->getShape(i,j) != ' ') {
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
 
    // Xóa ghost kh?i board sau khi v?
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (curPiece->getShape(i,j) != ' ') {
                int tx = px + j, ty = gy + i;
                if (ty >= 0 && ty < H && tx >= 0 && tx < W && board[ty][tx] == '.')
                    board[ty][tx] = ' ';
            }
            setColor(7);
}
 // TESTED FEATURES:
// - Score increases after clearing lines
// - Game speed increases after line clear
// - Minimum fall interval capped at 100ms
// ===================== REMOVE LINES =====================
//kiem tra va xoa dong day
void removeLines() {
    for (int i = H-2; i > 0; i--) {
        bool full = true;
        for (int j = 1; j < W-1; j++)
            if (board[i][j] == ' ') { full = false; break; }
        if (full) {
            // Board sends clear-line event here
            // Increase score and game speed after line clear
            score += 100;
            clearLineSound();
            if (fallInterval > 100)
                fallInterval -= 20;
            for (int ii = i; ii > 1; ii--)
                for (int j = 1; j < W-1; j++)
                    board[ii][j] = board[ii-1][j];
            for (int j = 1; j < W-1; j++) board[1][j] = ' ';
            i++; // ki?m tra l?i dòng này
        }
    }
}
 
// ===================== SPAWN =====================
//tao block moi o vi tri spawn mac dinh
bool spawnBlock() {
    //reset goc xoay
    if (curPiece) delete curPiece;

    curPiece = nextBlock();

    px = W / 2 - 2;
    py = 0;

    curPiece->rot = 0;
    //neu spawn trung thi gameover
    if (!canPlace(curPiece, px, py)) {
        gameOver = true;
        return false;
    }

    return true;
}
 
//in man hinh ket thuc game
// ===================== GAME OVER SCREEN =====================
void showGameOver() {
	gameOverSound();
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
	//khoi tao random va giao dien
    srand((unsigned)time(0));
    hideCursor();
    system("cls");
    initBoard();
    spawnBlock();
 
    DWORD lastFall = GetTickCount();

    while (!gameOver) {
        // --- INPUT ---
        if (kbhit()) {
            char c = getch();
            clearFromBoard(curPiece, px, py);
 
            if (c == 'a' || c == 75) { // trai
                if (canPlace(curPiece, px-1, py)){
                	px--;
                	moveSound();
				}
            }
            else if (c == 'd' || c == 77) { // phai
                if (canPlace(curPiece, px+1, py)){
                	px++;
                	moveSound();
				}
            }
            else if (c == 's' || c == 80) { // soft drop
                if (canPlace(curPiece, px, py+1)) {
                    py++;
                    score++;
                    lastFall = GetTickCount();
                }
            }
            else if (c == ' ') { // HARD DROP
                int drop = 0;
                while (canPlace(curPiece, px, py+1)) { py++; drop++; }
                score += drop * 2;
                dropSound();
                placeOnBoard(curPiece, px, py);
                removeLines();
                spawnBlock();
                lastFall = GetTickCount();
                placeOnBoard(curPiece, px, py);
                draw();
                Sleep(50);
                continue;
            }
            else if (c == 'w') { // xoay
                int oldRot = curPiece->rot;
                curPiece->rot = (curPiece->rot + 1) % 4; // C?p nh?t g�c xoay m?i tru?c d? test
                
                if (canPlace(curPiece, px, py)) {
                	rotateSound();
                    // H?p l?, gi? nguy�n g�c xoay m?i
                }
                // Wall kick don gi?n
                else if (canPlace(curPiece, px + 1, py)) { px++; rotateSound(); }
                else if (canPlace(curPiece, px - 1, py)) { px--; rotateSound(); }
                else {
                    // N?u k?t m?i hu?ng, h?y b? xoay v� tr? v? g�c cu
                    curPiece->rot = oldRot; 
                }
            }
            //an q thi ket thuc game
            else if (c == 'q'){
            	gameOver = true;
            	break;
			}
 
            placeOnBoard(curPiece, px, py);
        }
 
        // --- AUTO FALL ---
        DWORD now = GetTickCount();
        if (now - lastFall >= (DWORD)fallInterval) {
           clearFromBoard(curPiece, px, py);
            if (canPlace(curPiece, px, py+1)) {
                py++;
            } else {
                placeOnBoard(curPiece, px, py);
                removeLines();
                spawnBlock();
                placeOnBoard(curPiece, px, py);
                draw();
                lastFall = GetTickCount();
                continue;
            }
            placeOnBoard(curPiece, px, py);
            lastFall = now;
        }
 
        // --- RENDER ---
        draw();
        Sleep(30);
    }
 
    if (gameOver) showGameOver();
    setColor(7);
    if (curPiece) delete curPiece;
    return 0;
}
