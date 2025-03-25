#include <iostream>
#include <windows.h>
using namespace std;
#define w 20
#define h 15

int dir;
char snake = '0';
int x = 5;
int y = 6;
char sn = '0';
char tail = '0';
char fd = '*';
int fdx = rand() % (w - 2 + 1) + 2;
int fdy = rand() % (h - 2 + 1) + 2;
int score = 0;
int prescore = 0;
int tlc;
int xaray[50];
int yaray[50];
int lp;


char field[h][w];


void init(){
	for(int i = 0;i < h;i++){
		for(int j = 0; j<w; j++){
			field[j][i] = '#';
			field[j+1][i] = '\n';
		}
	}
	
	for(int i = 1; i < h-1;i++){
		for(int j = 2; j<w-1;j++){
			field[j][i] = ' ';
		}
	}
	field[w+1][h] = '\t';
}

void display(){
	for(int i = 0;i<h;i++){
		for(int j = 0; j<w; j++){
			cout<<field[j+1][i];
		}
	}
}
	 
int main() {
	setlocale(LC_ALL, "RU");

	while(1){
		Sleep(2);
		system("cls");
		init();
		if(lp>49)
			lp = score;
		
		field[x][y] = sn;
		if(score>prescore){
			field[xaray[lp-score]][yaray[lp-score]] = tail;
			for(int i = lp-score; i<lp; i++){
			field[xaray[i]][yaray[i]] = tail;
			}	
		}
		
		
		
		field[fdx][fdy] = fd;
		display();
		xaray[lp] = x;
		yaray[lp] = y;
		if(dir==1){x--; sn = '<';}
		if(dir==2){x++; sn = '>';}
		if(dir==3){y--; sn = '^';}
		if(dir==4){y++; sn = 'v';}
		if(x == fdx && y == fdy){
			fdx = rand() % (18 - 1 + 1) + 1;
			fdy = rand() % (14 - 1 + 1) + 1;
			field[fdx][fdy] = fd;
			score++;
		}
	
		
		Sleep(100);
		
		
		if (GetKeyState('A') & 0x8000){ dir = 1;}
		if (GetKeyState('D') & 0x8000){ dir = 2;}
		if (GetKeyState('W') & 0x8000){ dir = 3;}
		if (GetKeyState('S') & 0x8000){ dir = 4;}
		if(x == w || x == 0){
			break;
			
		}
		if(y == h || y == 0){
			break;
			
		}
		lp++;
	}
	
		system("cls");
		cout<< "###################\n"
		       "###### ti lox #####\n"
		       "      ########     \n"
		       "      ########     \n"
		       "      ########     \n"
			   "      ########     \n"
			   "      ########     \n"
			   "      ########     \n"
			   "      ########     \n"
			   "      ########     \n"
			   "###################\n"
			   "###################\n"
			   "###################\n"
			   "###################\n"
			   "                   \n"
			<< "###### score ######\n"
			<< "######   " << score << "  ######\n";
			   		       
	return 0;
}
