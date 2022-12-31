// Online C compiler to run C program online
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <time.h>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition1; // used for goto
COORD CursorPosition2; // used for goto

void gotoXY1(int x1, int y1) 
{ 
	CursorPosition1.X = x1; 
	CursorPosition1.Y = y1; 
	SetConsoleCursorPosition(console,CursorPosition1); 
}

void gotoXY2(int x2,int y2) 
{ 
	CursorPosition2.X = x2; 
	CursorPosition2.Y = y2; 
	SetConsoleCursorPosition(console,CursorPosition2); 
}

char map[61][41];
int px1 = 10,py1 = 58;
int px2 = 30,py2 = 58;
char input1,input2;
void generate(){
    for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 40;j++){
                if(i == 0 || i == 59 || j == 0 || j == 39){
                    map[i][j] = '#';
                }
                else{
                    map[i][j] = ' ';
                }
            }
    }
    
}

void print(){
    for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 40;j++){
                printf("%c",map[i][j]);
            }
            printf("\n");
            
    }
}


void validate1(){
	
	int x = 0;
	x = rand()%26 + 'a';
	input1 = x;
}

void validate2(){
	int y = 0;
	y = rand()%26 + 'a';
	input2 = y;
}

void play(){
    // char x;
    print();
    gotoXY1(px1,py1) ; printf("X");
    gotoXY1(px2,py2) ; printf("Y");
    validate1();
	Sleep(100);
	validate2();
    while(py1 != 1 && py2 != 1){
        gotoXY1(50,30); printf("%c %c",input1,input2);
        char x = getch();
        if(x == input1){
        	gotoXY1(px1,py1) ; printf(" ");
        	 py1--;
			gotoXY1(px1,py1) ; printf("X");
			validate1();
		}
        if(x == input2){
        	gotoXY1(px2,py2) ; printf(" ");
        	py2--;
			gotoXY1(px2,py2) ; printf("Y");
			validate2();
		};
	}
    if(py1 == 1) printf("Jose Menang");
    else if(py2 == 1) printf("Joseph Menang");
    
    
}


int main() {
	srand(time(0));fx
    generate();
    play();
    return 0;
}
