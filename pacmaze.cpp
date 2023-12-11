#include <iostream>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

void intro(WINDOW* jendela, int Maxy, int Maxx){
	start_color();
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	int panjang = 82;
	int lebar = 8;
	char pacmaze[lebar][panjang] = 
	{
	"  /$$$$$$$   /$$$$$$   /$$$$$$          /$$      /$$  /$$$$$$  /$$$$$$$$ /$$$$$$$$",
	" | $$__  $$ /$$__  $$ /$$__  $$        | $$$    /$$$ /$$__  $$|_____ $$ | $$_____/",
	" | $$  ` $$| $$  ` $$| $$  `__/        | $$$$  /$$$$| $$  ` $$     /$$/ | $$      ",
	" | $$$$$$$/| $$$$$$$$| $$       /$$$$$$| $$ $$/$$ $$| $$$$$$$$    /$$/  | $$$$$   ",
	" | $$____/ | $$__  $$| $$      |______/| $$  $$$| $$| $$__  $$   /$$/   | $$__/   ",
	" | $$      | $$  | $$| $$    $$        | $$`  $ | $$| $$  | $$  /$$/    | $$      ",
	" | $$      | $$  | $$|  $$$$$$/        | $$ `/  | $$| $$  | $$ /$$$$$$$$| $$$$$$$$",
	" |__/      |__/  |__/ `______/         |__/     |__/|__/  |__/|________/|________/",
	};
	for(int k = - 82; k < (Maxx / 2) - (panjang / 2) + 2; k++){
		for(int i = 0; i < lebar; i++){
    		for (int j = 0; j < panjang; j++) {
    			if(pacmaze[i][j] == '$'){
    				wattron(jendela, A_BOLD);
					wattron(jendela, COLOR_PAIR(5));
    				mvwaddch(jendela, 3 + i, j + k, pacmaze[i][j]);
					wattroff(jendela, COLOR_PAIR(5));
					wattroff(jendela, A_BOLD);
				} else {
					wattron(jendela, A_BOLD);
     	   			wattron(jendela, COLOR_PAIR(4));
    				mvwaddch(jendela, 3 + i, j + k, pacmaze[i][j]);
					wattroff(jendela, COLOR_PAIR(4));
					wattroff(jendela, A_BOLD);
				}
     	  	}
   		}
   		wrefresh(jendela);
   		Sleep(20);
    }
    wattron(jendela, COLOR_PAIR(3));
    mvwprintw(jendela, Maxy / 2 + 4, Maxx / 2 - 8, "PRESS ANY KEY...");
    wattroff(jendela, COLOR_PAIR(3));
   	wgetch(jendela);
   	mvwprintw(jendela, Maxy / 2 + 4, Maxx / 2 - 8, "                ");
}

int menuutama(WINDOW* jendela, int Maxy, int Maxx){
	//daftar warna
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	
	//membuat box
	wattron(jendela, COLOR_PAIR(1));
	box(jendela, 0, 0);
	wattroff(jendela, COLOR_PAIR(1));
	
	//isi box
	int panjang = 82;
	int lebar = 8;
	char pacmaze[lebar][panjang] = 
	{
	"  /$$$$$$$   /$$$$$$   /$$$$$$          /$$      /$$  /$$$$$$  /$$$$$$$$ /$$$$$$$$",
	" | $$__  $$ /$$__  $$ /$$__  $$        | $$$    /$$$ /$$__  $$|_____ $$ | $$_____/",
	" | $$  ` $$| $$  ` $$| $$  `__/        | $$$$  /$$$$| $$  ` $$     /$$/ | $$      ",
	" | $$$$$$$/| $$$$$$$$| $$       /$$$$$$| $$ $$/$$ $$| $$$$$$$$    /$$/  | $$$$$   ",
	" | $$____/ | $$__  $$| $$      |______/| $$  $$$| $$| $$__  $$   /$$/   | $$__/   ",
	" | $$      | $$  | $$| $$    $$        | $$`  $ | $$| $$  | $$  /$$/    | $$      ",
	" | $$      | $$  | $$|  $$$$$$/        | $$ `/  | $$| $$  | $$ /$$$$$$$$| $$$$$$$$",
	" |__/      |__/  |__/ `______/         |__/     |__/|__/  |__/|________/|________/",
	};
	for(int i = 0; i < lebar; i++){
    	for (int j = 0; j < panjang; j++) {
   			if(pacmaze[i][j] == '$'){
   				wattron(jendela, A_BOLD);
				wattron(jendela, COLOR_PAIR(5));
   				mvwaddch(jendela, 3 + i, j + (Maxx / 2) - (panjang / 2) + 1, pacmaze[i][j]);
				wattroff(jendela, COLOR_PAIR(5));
				wattroff(jendela, A_BOLD);
			} else {
				wattron(jendela, A_BOLD);
     	   		wattron(jendela, COLOR_PAIR(4));
    			mvwaddch(jendela, 3 + i, j + (Maxx / 2) - (panjang / 2) + 1, pacmaze[i][j]);
				wattroff(jendela, COLOR_PAIR(4));
				wattroff(jendela, A_BOLD);
			}
       	}
   	}
	wattron(jendela, COLOR_PAIR(2));
	mvwprintw(jendela, ((Maxy - 2) / 2) + 2, ((Maxx - 2) / 2) - 3, "P L A Y");
	mvwprintw(jendela, ((Maxy - 2) / 2) + 4, ((Maxx - 2) / 2) - 4, "A B O U T");
	mvwprintw(jendela, ((Maxy - 2) / 2) + 6, ((Maxx - 2) / 2) - 3, "Q U I T");
	wattroff(jendela, COLOR_PAIR(2));
	
	//sistem pilihan
	int Pily1 = ((Maxy - 2) / 2) + 2;
	int Pilx1 = ((Maxx - 2) / 2) - 7;
	int Pily2 = ((Maxy - 2) / 2) + 2;
	int Pilx2 = ((Maxx - 2) / 2) + 7;
	int pilihmenu;
	int ch;
	mvwprintw(jendela, Pily1, Pilx1, ">");
	mvwprintw(jendela, Pily2, Pilx2, "<");
    wrefresh(jendela);
	while(true){
		ch = wgetch(jendela);
		if(ch == KEY_UP || ch == KEY_LEFT || ch == 'w' || ch == 'a'){
			if(Pily1 != (((Maxy - 2) / 2) + 2) && Pily2 != (((Maxy - 2) / 2) + 2)){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 -= 2;
				Pily2 -= 2;
			} else{
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 = ((Maxy - 2) / 2) + 6;
				Pily2 = ((Maxy - 2) / 2) + 6;
			}
		}
		if(ch == KEY_RIGHT || ch == KEY_DOWN || ch == 'd' || ch == 's'){
			if(Pily1 != (((Maxy - 2) / 2) + 6) && Pily2 != (((Maxy - 2) / 2) + 6)){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 += 2;
				Pily2 += 2;
			} else{
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 = ((Maxy - 2) / 2) + 2;
				Pily2 = ((Maxy - 2) / 2) + 2;
			}
		}
		mvwprintw(jendela, Pily1, Pilx1, ">");
		mvwprintw(jendela, Pily2, Pilx2, "<");
    	wrefresh(jendela);
		if(ch == '\n'){
			if(Pily1 == (((Maxy - 2) / 2) + 2) && Pily2 == (((Maxy - 2) / 2) + 2)){
				pilihmenu = 1;
			} else if(Pily1 == (((Maxy - 2) / 2) + 4) && Pily2 == (((Maxy - 2) / 2) + 4)){
				pilihmenu = 2;
			} else if(Pily1 == (((Maxy - 2) / 2) + 6) && Pily2 == (((Maxy - 2) / 2) + 6)){
				pilihmenu = 3;
			}
			break;
		}
	} 
	return pilihmenu;
}

int game(WINDOW* jendela, int Maxy, int Maxx){
	wclear(jendela);
	wrefresh(jendela);
	
	//daftar warna
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_CYAN);
	
	//buat box
	wattron(jendela, COLOR_PAIR(1));
	box(jendela, 0, 0);
	wattroff(jendela, COLOR_PAIR(1));
	
	//buat pilihan
	wattron(jendela, COLOR_PAIR(3));
	mvwprintw(jendela, 4, (Maxx / 2) - 12, " S E L E C T   L E V E L ");
	wattroff(jendela, COLOR_PAIR(3));
	wattron(jendela, COLOR_PAIR(2));
	mvwprintw(jendela, 8 + (4 * 0), 8 + (24 * 0), "LEVEL  1");
	mvwprintw(jendela, 8 + (4 * 0), 8 + (24 * 1), "LEVEL  2");
	mvwprintw(jendela, 8 + (4 * 0), 8 + (24 * 2), "LEVEL  3");
	mvwprintw(jendela, 8 + (4 * 0), 8 + (24 * 3), "LEVEL  4");
	mvwprintw(jendela, 8 + (4 * 0), 8 + (24 * 4), "LEVEL  5");
	mvwprintw(jendela, 8 + (4 * 1), 8 + (24 * 0), "LEVEL  6");
	mvwprintw(jendela, 8 + (4 * 1), 8 + (24 * 1), "LEVEL  7");
	mvwprintw(jendela, 8 + (4 * 1), 8 + (24 * 2), "LEVEL  8");
	mvwprintw(jendela, 8 + (4 * 1), 8 + (24 * 3), "LEVEL  9");
	mvwprintw(jendela, 8 + (4 * 1), 8 + (24 * 4), "LEVEL 10");
	wattroff(jendela, COLOR_PAIR(2));
	wrefresh(jendela);
	
	//sistem pilihan
	int Pily1 = 8 + (4 * 0);
	int Pilx1 = 8 + (24 * 0) - 4;
	int Pily2 = 8 + (4 * 0);
	int Pilx2 = 8 + (24 * 0) + 11;
	int pilihlevel;
	int ch;
	mvwprintw(jendela, Pily1, Pilx1, ">");
	mvwprintw(jendela, Pily2, Pilx2, "<");
    wrefresh(jendela);
	while(ch = wgetch(jendela)){
		if(ch == KEY_UP || ch == 'w'){
			if(Pily1 != 8 + (4 * 0) && Pily2 != 8 + (4 * 0)){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 -= 4;
				Pily2 -= 4;
			}
		}
		if(ch == KEY_DOWN || ch == 's'){
			if(Pily1 != 8 + (4 * 1) && Pily2 != 8 + (4 * 1)){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pily1 += 4;
				Pily2 += 4;
			}
		}
		if(ch == KEY_RIGHT || ch == 'd'){
			if(Pilx1 != 8 + (24 * 4) - 4 && Pilx2 != 8 + (24 * 4) + 11){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pilx1 += 24;
				Pilx2 += 24;
			} else{
				if(Pily1 != 8 + (4 * 1) && Pily2 != 8 + (4 * 1)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pilx1 = 8 + (24 * 0) - 4;
					Pilx2 = 8 + (24 * 0) + 11;
					Pily1 += 4;
					Pily2 += 4;
				}
			}
		}
		if(ch == KEY_LEFT || ch == 'a'){
			if(Pilx1 != 8 + (24 * 0) - 4 && Pilx2 != 8 + (24 * 0) + 11){
				mvwprintw(jendela, Pily1, Pilx1, " ");
				mvwprintw(jendela, Pily2, Pilx2, " ");
				Pilx1 -= 24;
				Pilx2 -= 24;
			} else{
				if(Pily1 != 8 + (4 * 0) && Pily2 != 8 + (4 * 0)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pilx1 = 8 + (24 * 4) - 4;
					Pilx2 = 8 + (24 * 4) + 11;
					Pily1 -= 4;
					Pily2 -= 4;
				}
			}
		}
		mvwprintw(jendela, Pily1, Pilx1, ">");
		mvwprintw(jendela, Pily2, Pilx2, "<");
    	wrefresh(jendela);
    	if(ch == '\b'){
    		wclear(jendela);
    		wrefresh(jendela);
    		pilihlevel = 0;
    		break;
		}
		if(ch == '\n'){
			if(Pily1 == 8 + (4 * 0) && Pilx1 == 8 + (24 * 0) - 4){
				pilihlevel = 1;
			} else if(Pily1 == 8 + (4 * 0) && Pilx1 == 8 + (24 * 1) - 4){
				pilihlevel = 2;
			} else if(Pily1 == 8 + (4 * 0) && Pilx1 == 8 + (24 * 2) - 4){
				pilihlevel = 3;
			} else if(Pily1 == 8 + (4 * 0) && Pilx1 == 8 + (24 * 3) - 4){
				pilihlevel = 4;
			} else if(Pily1 == 8 + (4 * 0) && Pilx1 == 8 + (24 * 4) - 4){
				pilihlevel = 5;
			} else if(Pily1 == 8 + (4 * 1) && Pilx1 == 8 + (24 * 0) - 4){
				pilihlevel = 6;
			} else if(Pily1 == 8 + (4 * 1) && Pilx1 == 8 + (24 * 1) - 4){
				pilihlevel = 7;
			} else if(Pily1 == 8 + (4 * 1) && Pilx1 == 8 + (24 * 2) - 4){
				pilihlevel = 8;
			} else if(Pily1 == 8 + (4 * 1) && Pilx1 == 8 + (24 * 3) - 4){
				pilihlevel = 9;
			} else if(Pily1 == 8 + (4 * 1) && Pilx1 == 8 + (24 * 4) - 4){
				pilihlevel = 10;
			}
			break;
		}
	}
	wclear(jendela);
	wrefresh(jendela);
	return pilihlevel;
}
	int pause(WINDOW* jendela, int Maxy, int Maxx, int pilihpause){
		
		init_pair(11, COLOR_CYAN, COLOR_BLACK);
		init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(13, COLOR_MAGENTA, COLOR_CYAN);
		wclear(jendela);
		wrefresh(jendela);
		start_color();
		
		//membuat box
		wattron(jendela, COLOR_PAIR(11));
		box(jendela, 0, 0);
		wattroff(jendela, COLOR_PAIR(11));
		
		//isi box
		wattron(jendela, COLOR_PAIR(13));
		mvwprintw(jendela, ((Maxy - 2) / 2) - 8, ((Maxx - 2) / 2) - 5, " P A U S E ");
		wattroff(jendela, COLOR_PAIR(13));
		wattron(jendela, COLOR_PAIR(12));
		mvwprintw(jendela, ((Maxy - 2) / 2) +1, ((Maxx - 2) / 2) - 5, "R E T U R N");
		mvwprintw(jendela, ((Maxy - 2) / 2) + 3, ((Maxx - 2) / 2) - 6, "R E S T A R T");
		mvwprintw(jendela, ((Maxy - 2) / 2) + 5, ((Maxx - 2) / 2) - 4, "L E V E L");
		wattroff(jendela, COLOR_PAIR(12));
		
		//sistem pilihan
		int Pily1 = ((Maxy - 2) / 2) + 1;
		int Pilx1 = ((Maxx - 2) / 2) - 9;
		int Pily2 = ((Maxy - 2) / 2) + 1;
		int Pilx2 = ((Maxx - 2) / 2) + 9;
		int pilihmenu;
		int ch;
		mvwprintw(jendela, Pily1, Pilx1, ">");
		mvwprintw(jendela, Pily2, Pilx2, "<");
    	wrefresh(jendela);
		while(true){
			ch = wgetch(jendela);
			if(ch == KEY_UP || ch == KEY_LEFT || ch == 'w' || ch == 'a'){
				if(Pily1 != (((Maxy - 2) / 2) + 1) && Pily2 != (((Maxy - 2) / 2) - 2)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 -= 2;
					Pily2 -= 2;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 5;
					Pily2 = ((Maxy - 2) / 2) + 5;
				}
			}
			if(ch == KEY_RIGHT || ch == KEY_DOWN || ch == 'd' || ch == 's'){
				if(Pily1 != (((Maxy - 2) / 2) + 5) && Pily2 != (((Maxy - 2) / 2) + 2)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 += 2;
					Pily2 += 2;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 1;
					Pily2 = ((Maxy - 2) / 2) + 1;
				}
			}
			mvwprintw(jendela, Pily1, Pilx1, ">");
			mvwprintw(jendela, Pily2, Pilx2, "<");
    		wrefresh(jendela);
			if(ch == '\n'){
				if(Pily1 == (((Maxy - 2) / 2) + 1) && Pily2 == (((Maxy - 2) / 2) + 1)){
					pilihpause = 1;
				} else if(Pily1 == (((Maxy - 2) / 2) + 3) && Pily2 == (((Maxy - 2) / 2) + 3)){
					pilihpause = 2;
				} else if(Pily1 == (((Maxy - 2) / 2) + 5) && Pily2 == (((Maxy - 2) / 2) + 5)){
					pilihpause = 3;
				}
				break;
			}
			if(ch == '\b' || ch == 'p'){
				pilihpause = 1;
				break;
			}
		}
		
		wclear(jendela);
		wrefresh(jendela);
		return pilihpause;
	}
	
	int win(WINDOW* jendela, int Maxy, int Maxx, int pilihwin, int score, int bonus){
		wclear(jendela);
		wrefresh(jendela);
		int total = score + bonus;
		start_color();
		init_pair(11, COLOR_CYAN, COLOR_BLACK);
		init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(13, COLOR_MAGENTA, COLOR_CYAN);
		init_pair(14, COLOR_RED, COLOR_BLACK);
		
		//membuat box
		wattron(jendela, COLOR_PAIR(11));
		box(jendela, 0, 0);
		wattroff(jendela, COLOR_PAIR(11));
		
		//isi box
		wattron(jendela, COLOR_PAIR(13));
		mvwprintw(jendela, ((Maxy - 2) / 2) - 8, ((Maxx - 2) / 2) - 14, " C O N G R A T U L A T I O N ");
		mvwprintw(jendela, ((Maxy - 2) / 2) - 6, ((Maxx - 2) / 2) - 7, " Y O U   W I N ");
		wattroff(jendela, COLOR_PAIR(13));
		wattron(jendela, COLOR_PAIR(14));
		mvwprintw(jendela, ((Maxy - 2) / 2) - 2, ((Maxx - 2) / 2) - 7, "SCORE  :  %d", score);
		mvwprintw(jendela, ((Maxy - 2) / 2) - 1, ((Maxx - 2) / 2) - 7, "BONUS  :  %d", bonus);
		mvwprintw(jendela, ((Maxy - 2) / 2), ((Maxx - 2) / 2) - 7, "TOTAL  :  %d", total);
		wattroff(jendela, COLOR_PAIR(14));
		wattron(jendela, COLOR_PAIR(12));
		mvwprintw(jendela, ((Maxy - 2) / 2) + 4, ((Maxx - 2) / 2) - 3, "N E X T");
		mvwprintw(jendela, ((Maxy - 2) / 2) + 6, ((Maxx - 2) / 2) - 6, "R E S T A R T");
		mvwprintw(jendela, ((Maxy - 2) / 2) + 8, ((Maxx - 2) / 2) - 4, "L E V E L");
		wattroff(jendela, COLOR_PAIR(12));
		
		//sistem pilihan
		int Pily1 = ((Maxy - 2) / 2) + 4;
		int Pilx1 = ((Maxx - 2) / 2) - 10;
		int Pily2 = ((Maxy - 2) / 2) + 4;
		int Pilx2 = ((Maxx - 2) / 2) + 10;
		int pilihmenu;
		int ch;
		mvwprintw(jendela, Pily1, Pilx1, ">");
		mvwprintw(jendela, Pily2, Pilx2, "<");
    	wrefresh(jendela);
		while(true){
			ch = wgetch(jendela);
			if(ch == KEY_UP || ch == KEY_LEFT || ch == 'w' || ch == 'a'){
				if(Pily1 != (((Maxy - 2) / 2) + 4) && Pily2 != (((Maxy - 2) / 2) + 4)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 -= 2;
					Pily2 -= 2;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 8;
					Pily2 = ((Maxy - 2) / 2) + 8;
				}
			}
			if(ch == KEY_RIGHT || ch == KEY_DOWN || ch == 'd' || ch == 's'){
				if(Pily1 != (((Maxy - 2) / 2) + 8) && Pily2 != (((Maxy - 2) / 2) + 8)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 += 2;
					Pily2 += 2;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 4;
					Pily2 = ((Maxy - 2) / 2) + 4;
				}
			}
			mvwprintw(jendela, Pily1, Pilx1, ">");
			mvwprintw(jendela, Pily2, Pilx2, "<");
    		wrefresh(jendela);
			if(ch == '\n'){
				if(Pily1 == (((Maxy - 2) / 2) + 4) && Pily2 == (((Maxy - 2) / 2) + 4)){
					pilihwin = 1;
				} else if(Pily1 == (((Maxy - 2) / 2) + 6) && Pily2 == (((Maxy - 2) / 2) + 6)){
					pilihwin = 2;
				} else if(Pily1 == (((Maxy - 2) / 2) + 8) && Pily2 == (((Maxy - 2) / 2) + 8)){
					pilihwin = 3;
				}
				break;
			}
		}
		
		wclear(jendela);
		wrefresh(jendela);
		return pilihwin;
	}
	
	int gameover(WINDOW* jendela, int Maxy, int Maxx, int pilihgameover){
		wclear(jendela);
		wrefresh(jendela);
		start_color();
		init_pair(11, COLOR_CYAN, COLOR_BLACK);
		init_pair(12, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(13, COLOR_MAGENTA, COLOR_CYAN);
		
		//membuat box
		wattron(jendela, COLOR_PAIR(11));
		box(jendela, 0, 0);
		wattroff(jendela, COLOR_PAIR(11));
		
		//isi box
		wattron(jendela, COLOR_PAIR(13));
		mvwprintw(jendela, ((Maxy - 2) / 2) - 7, ((Maxx - 2) / 2) - 9, " G A M E   O V E R ");
		wattroff(jendela, COLOR_PAIR(13));
		wattron(jendela, COLOR_PAIR(12));
		mvwprintw(jendela, ((Maxy - 2) / 2) + 1, ((Maxx - 2) / 2) - 6, "R E S T A R T");
		mvwprintw(jendela, ((Maxy - 2) / 2) + 4, ((Maxx - 2) / 2) - 4, "L E V E L");
		wattroff(jendela, COLOR_PAIR(12));
		
		//sistem pilihan
		int Pily1 = ((Maxy - 2) / 2) + 1;
		int Pilx1 = ((Maxx - 2) / 2) - 10;
		int Pily2 = ((Maxy - 2) / 2) + 1;
		int Pilx2 = ((Maxx - 2) / 2) + 10;
		int pilihmenu;
		int ch;
		mvwprintw(jendela, Pily1, Pilx1, ">");
		mvwprintw(jendela, Pily2, Pilx2, "<");
    	wrefresh(jendela);
		while(true){
			ch = wgetch(jendela);
			if(ch == KEY_UP || ch == KEY_LEFT || ch == 'w' || ch == 'a'){
				if(Pily1 != (((Maxy - 2) / 2) + 1) && Pily2 != (((Maxy - 2) / 2) + 1)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 -= 3;
					Pily2 -= 3;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 4;
					Pily2 = ((Maxy - 2) / 2) + 4;
				}
			}
			if(ch == KEY_RIGHT || ch == KEY_DOWN || ch == 'd' || ch == 's'){
				if(Pily1 != (((Maxy - 2) / 2) + 4) && Pily2 != (((Maxy - 2) / 2) + 4)){
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 += 3;
					Pily2 += 3;
				} else{
					mvwprintw(jendela, Pily1, Pilx1, " ");
					mvwprintw(jendela, Pily2, Pilx2, " ");
					Pily1 = ((Maxy - 2) / 2) + 1;
					Pily2 = ((Maxy - 2) / 2) + 1;
				}
			}
			mvwprintw(jendela, Pily1, Pilx1, ">");
			mvwprintw(jendela, Pily2, Pilx2, "<");
    		wrefresh(jendela);
			if(ch == '\n'){
				if(Pily1 == (((Maxy - 2) / 2) + 1) && Pily2 == (((Maxy - 2) / 2) + 1)){
					pilihgameover = 1;
				} else if(Pily1 == (((Maxy - 2) / 2) + 4) && Pily2 == (((Maxy - 2) / 2) + 4)){
					pilihgameover = 2;
				}
				break;
			}
		}
		
		wclear(jendela);
		wrefresh(jendela);
		return pilihgameover;
	}
	
	int level1(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playery = 26;
		int playerx = 3;
		int score = 0;
		int bonus = 3000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
    		"###########################################################",
    		"#*        * ######          ######   *       ######       >",
    		"#           ######          ######           ###### #######",
    		"#  ######   ######  ######  ######  ######   ######    *  #",
    		"#  ######   ######  ######  ######  ######   ########## ###",
    		"#* ###### * ###### *######  ######* ######   ######       #",
    		"#  ######   ######  ######  ######  ######   ####### ######",
    		"#  ######   ######  ######  ######  ######   ######       #",
    		"#  ######   ######  ######  ######  ######   ############ #",
    		"#  ###### * ###### *######  ######  ######   ######   *   #",
    		"#  ######   ######  ######  ######  ######  *######## #####",
    		"#  ######   ######  ######* ######  ######   ###### *     #",
    		"#  ######   ######  ######  ######  ######   ######### ####",
    		"#  ######   ######  ######  ######  ######   ######      *#",
    		"#  ######   ######  ######  ######  ######   ####### ######",
    		"#  ######   ######  ######  ######  ######   ######       #",
    		"#  ######   ######  ######  ######  ######   ########### ##",
    		"#  ######   ######  ######  ######* ###### * ######       #",
    		"#  ######   ######  ######  ######  ######   ######### ####",
    		"#  ######   ######  ######  ######  ######   ######*      #",
			"#  ######   ######  ######  ######  ######   ############ #",
			"#  ######   ######  ######  ######  ######   ######       #",
			"#  ######           ######          ######    *           #",
			"#  ######   *       ######          ######             *  #",
			"###########################################################",
			};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//gambar player
		wattron(kotak, COLOR_PAIR(4));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(4));
		wrefresh(kotak);
    	
    	//sistem
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 1");
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
			if(ch == KEY_UP || ch == 'w'){
				if(maze[playery - 3 - 1][playerx - 2] != '#'){
					if(maze[playery - 3 - 1][playerx - 2] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery -= 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_DOWN || ch == 's'){
				if(maze[playery - 3 + 1][playerx - 2] != '#'){
					if(maze[playery - 3 + 1][playerx - 2] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery += 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_RIGHT || ch == 'd'){
				if(maze[playery - 3][playerx - 2 + 1] != '#'){
					if(maze[playery - 3][playerx - 2 + 1] != '>'){
						if(maze[playery - 3][playerx - 2 + 1] == '*'){
							score += 100;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
					} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == 2100){
						score += 1000;
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
						if(bonus < 0){
							bonus = 0;
						}
						maze[playery - 3][playerx - 2] = 'O';
						for(int i = 0; i < lebar; i++){
        					for (int j = 0; j < panjang; j++) {
        						if(maze[i][j] == '*' || maze[i][j] == '>'){
        							wattron(kotak, COLOR_PAIR(4));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(4));
								} else {
									wattron(kotak, COLOR_PAIR(1));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(1));
								}
        					}
        					mvwprintw(kotak, 3 + i, panjang + 1, " ");
    					}
    					wattron(kotak, COLOR_PAIR(2));
						box(kotak, 0, 0);
    					mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
						wattroff(kotak, COLOR_PAIR(2));
						wattron(kotak, COLOR_PAIR(4));
						mvwprintw(kotak, playery, playerx, "O");
						wattroff(kotak, COLOR_PAIR(4));
						wrefresh(kotak);
						napms(2000);
						pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
						if(pilihwin == 1){
							pilihlevel = 2;
							break;
						} else if(pilihwin == 2){
							pilihlevel = 1;
							break;
						} else if(pilihwin == 3){
							pilihlevel = 0;
							break;
						}
					}
				}
			}
			if(ch == KEY_LEFT || ch == 'a'){
				if(maze[playery - 3][playerx - 2 - 1] != '#'){
					if(maze[playery - 3][playerx - 2 - 1] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playerx -= 1;
					bonus -= 5;
				}
			}
			maze[playery - 3][playerx - 2] = 'O';
			wattron(kotak, COLOR_PAIR(2));
			mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(ch == '\b' || ch == 'p'){
				pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
			}
			for(int i = 0; i < lebar; i++){
        		for (int j = 0; j < panjang; j++) {
        			if(maze[i][j] == '*' || maze[i][j] == '>'){
        				wattron(kotak, COLOR_PAIR(4));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(4));
					} else {
						wattron(kotak, COLOR_PAIR(1));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(1));
					}
        		}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wattron(kotak, COLOR_PAIR(4));
			mvwprintw(kotak, playery, playerx, "O");
			wattroff(kotak, COLOR_PAIR(4));
			wrefresh(kotak);
			
			if(pilihpause == 2){
				pilihlevel = 1;
				break;
			} else if(pilihpause == 3){
				pilihlevel = 0;
				break;
			}
		}
		return pilihlevel;
	}
	
	int level2(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(4, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		
		//deklarasi
	wrefresh(jendela);
	wrefresh(jendela);
		const int lebar = 25;
		const int panjang =  60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playery = 25;
		int playerx = 3;
		int score = 0;
		int bonus = 3000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
    		"###########################################################",
    		"#                    #                                    >",
    		"#                   *#                           *        #",
    		"#  ####   ############   ##################################",
    		"#  #* #                           *                       #",
    		"#  #  #                                                   #",
    		"#  #  ##################################################  #",
    		"#  #                                                      #",
    		"#  #                          *                           #",
    		"#  #  ###########################  ########################",
    		"#  #  #                  ########                         #",
    		"#  #  #                  ########                    ###  #",
    		"#  #  #  #  ###########  #########################    *#  #",
    		"#  #  #  #          * #  ########                #   ###  #",
    		"#  #  #  #            #  ########            *   #        #",
    		"#  #  #  ####  #####  ##  #######  ###############  #######",
    		"#  #  #     #  #       #  #######                   #     #",
    		"#  # *#     #  #       #  #######                   #  #  #",
    		"#  ######   #  #    #############  ##################  #  #",
    		"#           #  #                                       #  #",
			"#           #  #                                       #  #",
			"#########   #  #########################################  #",
			"#           #                                             #",
			"#           #      *                                     *#",
			"###########################################################",
		};
		
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(4));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(4));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	wrefresh(kotak);
    	
    	//sistem
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 2");
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
			if(ch == KEY_UP || ch == 'w'){
				if(maze[playery - 3 - 1][playerx - 2] != '#'){
					if(maze[playery - 3 - 1][playerx - 2] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery -= 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_DOWN || ch == 's'){
				if(maze[playery - 3 + 1][playerx - 2] != '#'){
					if(maze[playery - 3 + 1][playerx - 2] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery += 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_RIGHT || ch == 'd'){
				if(maze[playery - 3][playerx - 2 + 1] != '#'){
					if(maze[playery - 3][playerx - 2 + 1] != '>'){
						if(maze[playery - 3][playerx - 2 + 1] == '*'){
							score += 100;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
					} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == 1100){
						score += 1000;
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
						if(bonus < 0){
							bonus = 0;
						}
						maze[playery - 3][playerx - 2] = 'O';
						for(int i = 0; i < lebar; i++){
        					for (int j = 0; j < panjang; j++) {
        						if(maze[i][j] == '*' || maze[i][j] == '>'){
        							wattron(kotak, COLOR_PAIR(4));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(4));
								} else {
									wattron(kotak, COLOR_PAIR(1));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(1));
								}
        					}
        					mvwprintw(kotak, 3 + i, panjang + 1, " ");
    					}
    					wattron(kotak, COLOR_PAIR(2));
						box(kotak, 0, 0);
    					mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
						wattroff(kotak, COLOR_PAIR(2));
						wattron(kotak, COLOR_PAIR(4));
						mvwprintw(kotak, playery, playerx, "O");
						wattroff(kotak, COLOR_PAIR(4));
						wrefresh(kotak);
						napms(2000);
						pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
						if(pilihwin == 1){
							pilihlevel = 3;
							break;
						} else if(pilihwin == 2){
							pilihlevel = 2;
							break;
						} else if(pilihwin == 3){
							pilihlevel = 0;
							break;
						}
					}
				}
			}
			if(ch == KEY_LEFT || ch == 'a'){
				if(maze[playery - 3][playerx - 2 - 1] != '#'){
					if(maze[playery - 3][playerx - 2 - 1] == '*'){
						score += 100;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playerx -= 1;
					bonus -= 5;
				}
			}
			maze[playery - 3][playerx - 2] = 'O';
			wattron(kotak, COLOR_PAIR(2));
			mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(ch == '\b' || ch == 'p'){
				pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
			}
			for(int i = 0; i < lebar; i++){
        		for (int j = 0; j < panjang; j++) {
       		 		if(maze[i][j] == '*' || maze[i][j] == '>'){
        				wattron(kotak, COLOR_PAIR(4));
           	 		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
        	    		wattroff(kotak, COLOR_PAIR(4));
					} else {
						wattron(kotak, COLOR_PAIR(1));
           	 		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
           	 		wattroff(kotak, COLOR_PAIR(1));
					}
        		}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wattron(kotak, COLOR_PAIR(4));
			mvwprintw(kotak, playery, playerx, "O");
			wattroff(kotak, COLOR_PAIR(4));
			
			if(pilihpause == 2){
				pilihlevel = 2;
				break;
			} else if(pilihpause == 3){
				pilihlevel = 0;
				break;
			}
		}
		return pilihlevel;
	}
	
	int level3(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playery = 26;
		int playerx = 3;
		int score = 0;
		int bonus = 3000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
    		"#####################################++####################",
    		"#+           +   +   +      +               +          +  >",
    		"#       +  +   +   +*+                +          *  +    ++",
    		"#  +##+   ###########+   +#################################",
    		"#  #* #                                                   #",
    		"#  #  #                                                   #",
    		"#  #+ +#######################+++######################+  #",
    		"#+ #   +                                                  #",
    		"#  #            +             +*+              +          #",
    		"#+ #+ +##########################+ ########################",
    		"#  #  #                  +#######                         #",
    		"# +#  #                  +#######                    +++  #",
    		"#  #  #  #++###########  +#######################+    *+  #",
    		"# +#  #  #          * +  +#######                #   +++  #",
    		"#  #  #  #         +  #  +#######            *   #        #",
    		"#+ #  #  ####  ####+  #+  ######+ +#############+   +++####",
    		"#  #  #     #  #       #  ######+                   #     #",
    		"#  # *#     #  #       #  ######+                   #  +  #",
    		"#  +####++++#  #    +###########+  +#################  #  #",
    		"#           #  #                                       #  #",
			"#           #  #                                       #  #",
			"########+   +  +#######################################+  #",
			"#           #                                             #",
			"#           #                                            *#",
			"###########################################################",
		};
		
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[i][j] == '+'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	wrefresh(kotak);
    	
    	//sistem
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 3");
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
			if(ch == KEY_UP || ch == 'w'){
				if(maze[playery - 3 - 1][playerx - 2] != '#'){
					if(maze[playery - 3 - 1][playerx - 2] == '*'){
						score += 100;
					}
					if(maze[playery - 3 - 1][playerx - 2] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery -= 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_DOWN || ch == 's'){
				if(maze[playery - 3 + 1][playerx - 2] != '#'){
					if(maze[playery - 3 + 1][playerx - 2] == '*'){
						score += 100;
					}
					if(maze[playery - 3 + 1][playerx - 2] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery += 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_RIGHT || ch == 'd'){
				if(maze[playery - 3][playerx - 2 + 1] != '#'){
					if(maze[playery - 3][playerx - 2 + 1] != '>'){
						if(maze[playery - 3][playerx - 2 + 1] == '*'){
							score += 100;
						}
						if(maze[playery - 3][playerx - 2 + 1] == '+'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
					} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == 900){
						score += 1000;
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
						if(bonus < 0){
							bonus = 0;
						}
						maze[playery - 3][playerx - 2] = 'O';
						for(int i = 0; i < lebar; i++){
        					for (int j = 0; j < panjang; j++) {
        						if(maze[i][j] == '*' || maze[i][j] == '>'){
        							wattron(kotak, COLOR_PAIR(5));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(5));
								} else if(maze[i][j] == '+'){
									wattron(kotak, COLOR_PAIR(4));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(4));
								} else {
									wattron(kotak, COLOR_PAIR(1));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(1));
								}
        					}
        					mvwprintw(kotak, 3 + i, panjang + 1, " ");
    					}
						wattron(kotak, COLOR_PAIR(5));
						mvwprintw(kotak, playery, playerx, "O");
						wattroff(kotak, COLOR_PAIR(5));
    					wattron(kotak, COLOR_PAIR(2));
						box(kotak, 0, 0);
    					mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
						wattroff(kotak, COLOR_PAIR(2));
						wrefresh(kotak);
						napms(2000);
						pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
						if(pilihwin == 1){
							pilihlevel = 4;
							break;
						} else if(pilihwin == 2){
							pilihlevel = 3;
							break;
						} else if(pilihwin == 3){
							pilihlevel = 0;
							break;
						}
					}
				}
			}
			if(ch == KEY_LEFT || ch == 'a'){
				if(maze[playery - 3][playerx - 2 - 1] != '#'){
					if(maze[playery - 3][playerx - 2 - 1] == '*'){
						score += 100;
					}
					if(maze[playery - 3][playerx - 2 - 1] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playerx -= 1;
					bonus -= 5;
				}
			}
			maze[playery - 3][playerx - 2] = 'O';
			wattron(kotak, COLOR_PAIR(2));
			mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(ch == '\b' || ch == 'p'){
				pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
			}
			for(int i = 0; i < lebar; i++){
        		for (int j = 0; j < panjang; j++) {
        			if(maze[i][j] == '*' || maze[i][j] == '>'){
        				wattron(kotak, COLOR_PAIR(5));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(5));
					} else if(maze[i][j] == '+'){
						wattron(kotak, COLOR_PAIR(4));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(4));
					} else {
						wattron(kotak, COLOR_PAIR(1));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(1));
					}
        		}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
			wattron(kotak, COLOR_PAIR(5));
			mvwprintw(kotak, playery, playerx, "O");
			wattroff(kotak, COLOR_PAIR(5));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(mati == true){
				wattron(kotak, COLOR_PAIR(4));
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
    			wattroff(kotak, COLOR_PAIR(4));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				napms(1000);
				pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
				break;
			}
			if(pilihpause == 2){
				pilihlevel = 3;
				break;
			} else if(pilihpause == 3){
				pilihlevel = 0;
				break;
			}
		}
		if(pilihgameover == 1){
			pilihlevel = 3;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level4(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		
		//deklarasi
	wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playery = 12;
		int playerx = 3;
		int score = 0;
		int bonus = 3000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
    		"###########################################################",
    		"#     ##                                                  >",
			"#       ##   ##############################################",
			"#         ##                                            *+#",
    		"#           ##   ##########################################",
			"#             ##                                        *+#",
			"#               ##   ######################################",
    		"#                 ##                                    *+#",
			"#     +++           ##   ##################################",
			"#     +*+             ##                                *+#",
    		"#              +++      ##   ##############################",
			"#              +*+        ##                            *+#",
			"#                           ##   ##########################",
    		"#  +++                        ##                        *+#",
			"#  +*+     +++++++              ##   ######################",
			"#    +     +*   *+         ++     ##                    *+#",
    		"#+++++     +     +         +*++     ##   ##################",
			"#          +*   *+      +  +   ++     ##                *+#",
			"#          +++ +++      +  +     ++     ##   ##############",
    		"#                       +  + *++   ++     ##            *+#",
			"#      +++              +  +++++++   ++     ##   ##########",
			"#      +*+              +*            *++     ##        *+#",
			"#      + +              +++++++++++++++++       ##   ######",
			"#                                                       *+#",
			"###########################################################",
		};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[i][j] == '+'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	wrefresh(kotak);
    	
    	//sistem
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 4");
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
			if(ch == KEY_UP || ch == 'w'){
				if(maze[playery - 3 - 1][playerx - 2] != '#'){
					if(maze[playery - 3 - 1][playerx - 2] == '*'){
						score += 100;
					}
					if(maze[playery - 3 - 1][playerx - 2] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery -= 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_DOWN || ch == 's'){
				if(maze[playery - 3 + 1][playerx - 2] != '#'){
					if(maze[playery - 3 + 1][playerx - 2] == '*'){
						score += 100;
					}
					if(maze[playery - 3 + 1][playerx - 2] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playery += 1;
					bonus -= 5;
				}
			}
			if(ch == KEY_RIGHT || ch == 'd'){
				if(maze[playery - 3][playerx - 2 + 1] != '#'){
					if(maze[playery - 3][playerx - 2 + 1] != '>'){
						if(maze[playery - 3][playerx - 2 + 1] == '*'){
							score += 100;
						}
						if(maze[playery - 3][playerx - 2 + 1] == '+'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
					} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == 2300){
						score += 1000;
						maze[playery - 3][playerx - 2] = ' ';
						playerx += 1;
						bonus -= 5;
						if(bonus < 0) {
							bonus = 0;
						}
						maze[playery - 3][playerx - 2] = 'O';
						for(int i = 0; i < lebar; i++){
        					for (int j = 0; j < panjang; j++) {
        						if(maze[i][j] == '*' || maze[i][j] == '>'){
        							wattron(kotak, COLOR_PAIR(5));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(5));
								} else if(maze[i][j] == '+'){
									wattron(kotak, COLOR_PAIR(4));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(4));
								} else {
									wattron(kotak, COLOR_PAIR(1));
            						mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            						wattroff(kotak, COLOR_PAIR(1));
								}
        					}
        					mvwprintw(kotak, 3 + i, panjang + 1, " ");
    					}
						wattron(kotak, COLOR_PAIR(5));
						mvwprintw(kotak, playery, playerx, "O");
						wattroff(kotak, COLOR_PAIR(5));
    					wattron(kotak, COLOR_PAIR(2));
						box(kotak, 0, 0);
    					mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
						wattroff(kotak, COLOR_PAIR(2));
						wrefresh(kotak);
						napms(2000);
						pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
						if(pilihwin == 1){
							pilihlevel = 5;
							break;
						} else if(pilihwin == 2){
							pilihlevel = 4;
							break;
						} else if(pilihwin == 3){
							pilihlevel = 0;
							break;
						}
					}
				}
			}
			if(ch == KEY_LEFT || ch == 'a'){
				if(maze[playery - 3][playerx - 2 - 1] != '#'){
					if(maze[playery - 3][playerx - 2 - 1] == '*'){
						score += 100;
					}
					if(maze[playery - 3][playerx - 2 - 1] == '+'){
						mati = true;
					}
					maze[playery - 3][playerx - 2] = ' ';
					playerx -= 1;
					bonus -= 5;
				}
			}
			maze[playery - 3][playerx - 2] = 'O';
			wattron(kotak, COLOR_PAIR(2));
			mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(ch == '\b' || ch == 'p'){
				pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
			}
			for(int i = 0; i < lebar; i++){
        		for (int j = 0; j < panjang; j++) {
        			if(maze[i][j] == '*' || maze[i][j] == '>'){
        				wattron(kotak, COLOR_PAIR(5));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(5));
					} else if(maze[i][j] == '+'){
						wattron(kotak, COLOR_PAIR(4));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(4));
					} else {
						wattron(kotak, COLOR_PAIR(1));
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            			wattroff(kotak, COLOR_PAIR(1));
					}
        		}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
			wattron(kotak, COLOR_PAIR(5));
			mvwprintw(kotak, playery, playerx, "O");
			wattroff(kotak, COLOR_PAIR(5));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			if(mati == true){
				wattron(kotak, COLOR_PAIR(4));
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
            			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
    			wattroff(kotak, COLOR_PAIR(4));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				napms(1000);
				pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
				break;
			}
			if(pilihpause == 2){
				pilihlevel = 4;
				break;
			} else if(pilihpause == 3){
				pilihlevel = 0;
				break;
			}
		}
		if(pilihgameover == 1){
			pilihlevel = 4;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level5(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playery = 13;
		int playerx = 31;
		int count = 0;
		int score = 0;
		int bonus = 5000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int sumdurisemu = 9;
		int durisemux[sumdurisemu] = {3, 4, 27, 28, 58,59, 33, 34, 20};
		int durisemuy[sumdurisemu] = {12, 12, 15, 15, 15, 15, 12, 12, 12};
		
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
    		"###########################################################",
    		"#     #   #   #   #   #    #* #  *    #   *   #   *   #  *>",
    		"#+ +  # + # + # + # + # ++ #  # +#    #   +   #   +   #++ #",
			"#  #+ # # # # # # # # # #  #  #  #+ ++#   #   #   #+ +#   #",
			"# +#  # # # # # # # # # # +#  #+ #    #   #   #   #   # ++#",
			"#  # +# # # # # # # # # #  #  #  #++  #+ +#   #   # ++#   #",
			"#+ #  # # # # # # # # # #+ #  # +#    #   #   #   #   #+ +#",
			"#  #+ + # + # + # + # + #  #  #  #++ ++   #   +   #++ #   #",
			"# +#  * # * # * # * # * #* #  #+ #    *   #   *   #   *   #",
    		"#xx+++++++++++++++++++++++++  #xx+++++++++++++++++++++++++#",
    		"#                                                        *#",
    		"#*                                                        #",
    		"#++++++++++++++++++++++++xx#  ++++++++++++++++++++++++++xx#",
    		"# *#  * # * # * # * # * #  #  #  *    #   *   #   *   #   #",
    		"# +#  + # + # + # + # + #  #  #+ +    #   +   #   +   #   #",
    		"#  #  # # # # # # # # # #  #  #  #+  +#   #   #   #   #   #",
    		"#+ #  # # # # # # # # # #  #  # +#    #   #   #   #   #   #",
			"#  #  # # # # # # # # # #  #  #  #  ++#   #   #   #   #   #",
			"# +#  # # # # # # # # # #  #  #+ #    #   #   #   #   #   #",
			"#  #  # # # # # # # # # #  #  #  #++  #   #   #   #   #   #",
			"#+ #  # # # # # # # # # #  #  # +#    #   #   #   #   #   #",
			"#  #  # # # # # # # # # #  #  #  #++ +#   #   #   #   #   #",
			"# ++  # + # + # + # + # +  #  #+ #    +   #   +   #   +   #",
			"#     #   #   #   #   #    # *# *#+++ *   #   *   #   *   #",
			"###########################################################",
};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(ch = wgetch(kotak)){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 5");
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		if(ch == ERR) {
    			if(count != 1000){
    				mvwprintw(kotak, 1, 21, " ");
    				wrefresh(kotak);
    				count++;
				} else {
    				for(int i = 0; i < sumdurisemu; i++){
    					if(maze[durisemuy[i] - 3][durisemux[i] - 2] == 'x'){
    						maze[durisemuy[i] - 3][durisemux[i] - 2] = ' ';
						} else if(maze[durisemuy[i] - 3][durisemux[i] - 2] == ' '){
							maze[durisemuy[i] - 3][durisemux[i] - 2] = 'x';
						} else if(maze[durisemuy[i] - 3][durisemux[i] - 2] == 'O'){
							maze[durisemuy[i] - 3][durisemux[i] - 2] = 'x';
							mati = true;
							break;
						}
					}
					count = 0;
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[i][j] == '*' || maze[i][j] == '>'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[playery - 3 - 1][playerx - 2] != '#'){
						if(maze[playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						}
						if(maze[playery - 3 - 1][playerx - 2] == '+' || maze[playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[playery - 3 + 1][playerx - 2] != '#'){
						if(maze[playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						}
						if(maze[playery - 3 + 1][playerx - 2] == '+' || maze[playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[playery - 3][playerx - 2 + 1] != '#'){
						if(maze[playery - 3][playerx - 2 + 1] != '>'){
							if(maze[playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							}
							if(maze[playery - 3][playerx - 2 + 1] == '+' || maze[playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							}
							maze[playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
						} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == 3000){
							score += 1000;
							maze[playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[i][j] == '*' || maze[i][j] == '>'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = 6;
								break;
							} else if(pilihwin == 2){
								pilihlevel = 5;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[playery - 3][playerx - 2 - 1] != '#'){
						if(maze[playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						}
						if(maze[playery - 3][playerx - 2 - 1] == '+' || maze[playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[i][j] == '*' || maze[i][j] == '>'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = 5;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = 5;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level6(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playerx = 21;
		int playery = 13;
		int count = 0;
		int score = 0;
		int bonus = 5000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int level = 6;
		int summakan = 30;
		int sumdurisemu = 9;
		int durisemux[sumdurisemu] = {3, 4, 27, 28, 58,59, 33, 34, 20};
		int durisemuy[sumdurisemu] = {12, 12, 15, 15, 15, 15, 12, 12, 12};
		
		WINDOW* kotak = newwin(29, 63, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[lebar][panjang] = {
		   //23456789012345678901234567890123456789012345678901234567890
    		"###########################################################",
    		"#     +   +   +   +   +    +* +  *   ++   *   +   *   +  *>",
    		"#+ +  + + + + + + + + + ++ +  + ++    +   +   +   +   +   #",
			"#  ++ + + + + + + + + + +  +  +  +  +++   +   +   +   +   #",
			"# ++  + + + + + + + + + + ++  ++ +    +   +   +   +   +   #",
			"#  + ++ + + + + + + + + +  +  +  +++  +   +   +   +   +   #",
			"#+ +  + + + + + + + + + ++ +  + ++    +   +   +   +   +   #",
			"#  ++ + + + + + + + + + +  +  +  +++ ++   +   +   +   +   #",
			"# ++  * + * + * + * + * +* +  ++ +    *   +   *   +   *   #",
    		"#  +++++++++++++++++++++++++  +  +++++++++++++++++++++++++#",
    		"#                                                        *#",
    		"#*                                                        #",
    		"#++++++++++++++++++++++++  +  ++++++++++++++++++++++++++  #",
    		"# *+  * + * + * + * + * +  +  +  *    +   *   +   *   +   #",
    		"# ++  + + + + + + + + + +  +  ++ +    +   +   +   +   +   #",
    		"#  +  + + + + + + + + + +  +  +  ++  ++   +   +   +   +   #",
    		"#+ +  + + + + + + + + + +  +  + ++    +   +   +   +   +   #",
			"#  +  + + + + + + + + + +  +  +  +  +++   +   +   +   +   #",
			"# ++  + + + + + + + + + +  +  ++ +    +   +   +   +   +   #",
			"#  +  + + + + + + + + + +  +  +  +++  +   +   +   +   +   #",
			"#+ +  + + + + + + + + + +  +  + ++    +   +   +   +   +   #",
			"#  +  + + + + + + + + + +  +  +  +++ ++   +   +   +   +   #",
			"# ++  + + + + + + + + + +  +  ++ +    +   +   +   +   +   #",
			"#     +   +   +   +   +    + *+ *++++ *   +   *   +   *   #",
			"###########################################################",
};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[i][j] == '*' || maze[i][j] == '>'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 6", level);
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
    		if(ch == ERR) {
    			if(count != 1000){
    				mvwprintw(kotak, 1, 21, " ");
    				wrefresh(kotak);
    				count++;
				} else {
    				for(int i = 0; i < sumdurisemu; i++){
    					if(maze[durisemuy[i] - 3][durisemux[i] - 2] == 'x'){
    						maze[durisemuy[i] - 3][durisemux[i] - 2] = ' ';
						} else if(maze[durisemuy[i] - 3][durisemux[i] - 2] == ' '){
							maze[durisemuy[i] - 3][durisemux[i] - 2] = 'x';
						} else if(maze[durisemuy[i] - 3][durisemux[i] - 2] == 'O'){
							maze[durisemuy[i] - 3][durisemux[i] - 2] = 'x';
							mati = true;
							break;
						}
					}
					count = 0;
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[i][j] == '*' || maze[i][j] == '>'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}	
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[playery - 3 - 1][playerx - 2] != '#'){
						if(maze[playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						}
						if(maze[playery - 3 - 1][playerx - 2] == '+' || maze[playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[playery - 3 + 1][playerx - 2] != '#'){
						if(maze[playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						}
						if(maze[playery - 3 + 1][playerx - 2] == '+' || maze[playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[playery - 3][playerx - 2 + 1] != '#'){
						if(maze[playery - 3][playerx - 2 + 1] != '>'){
							if(maze[playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							}
							if(maze[playery - 3][playerx - 2 + 1] == '+' || maze[playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							}
							maze[playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
						} else if(maze[playery - 3][playerx - 2 + 1] == '>' && score == (summakan * 100)){
							score += 1000;
							maze[playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[i][j] == '*' || maze[i][j] == '>'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}			
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = level + 1;
								break;
							} else if(pilihwin == 2){
								pilihlevel = level;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[playery - 3][playerx - 2 - 1] != '#'){
						if(maze[playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						}
						if(maze[playery - 3][playerx - 2 - 1] == '+' || maze[playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						}
						maze[playery - 3][playerx - 2] = ' ';
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[i][j] == '*' || maze[i][j] == '>'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[i][j] == '+' || maze[i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = level;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = level;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level7(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playerx = 28;
		int playery = 15;
		int count = 0;
		int score = 0;
		int bonus = 7000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int world = 0;
		int level = 7;
		int summakan = 41;
		int sumdurisemu1 = 16;
		int durisemux1[sumdurisemu1] = {29, 30, 33, 34, 29, 30, 33, 34, 29, 30, 33, 34, 29, 30, 33, 34};
		int durisemuy1[sumdurisemu1] = {9, 9, 9, 9, 14, 14, 14, 14, 18, 18, 18, 18, 24, 24, 24, 24};
		int sumdurisemu2 = 16;
		int durisemux2[sumdurisemu2] = {29, 30, 33, 34, 29, 30, 33, 34, 29, 30, 33, 34, 29, 30, 33, 34};
		int durisemuy2[sumdurisemu2] = {9, 9, 9, 9, 14, 14, 14, 14, 18, 18, 18, 18, 24, 24, 24, 24};
		int sumportal = 1;
		int portalx[sumportal] = {35};
		int portaly[sumportal] = {15};
		
		WINDOW* kotak = newwin(lebar + 4, panjang + 3, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[2][lebar][panjang] = 
		{
			{
    			"###########################################################",
    			"#          +     +     +     +     +     +     +          #",
    			"#       +     +     +     +     +     +     +     +       #",
    			"#      #############################################      #",
    			"#      ##                    ##                   ##      #",
    			"#     +##  *   *             ##            *   *  ##+     #",
    			"#      ##          ######++xx##xx++######         ##      #",
    			"#   +  ##  *    ###          ##         ###    *  ##  +   #",
    			"#      ##     ###            ##           ###     ##      #",
    			"#  +   ##   ###      ##################     ###   ##    + #",
    			"#      ##  ###    ####       ##       ####   ###  ##      #",
    			"# +    ##  ###   ##      ++xx##xx++      ##  ###  ##     +#",
    			"#      ##  ### * ##  *  ++ **##**@++  *  ##* ###  ##      #",
    			"#+     ##  ###   ##      ++######++      ##  ###  ##    + #",
    			"#      ##  ###    ###        ##        ###   ###  ##      #",
    			"# +    ##  ###      #####++  ##  ++#####    ###   ##   +  #",
    			"#      ##    ###             ##            ###    ##      #",
    			"#  +   ##  *   ###           ##          ###   *  ##  +   #",
    			"#      ##        #########################        ##      #",
    			"#    + ##  *   *             ##            *   *  ##+     #",
				"#      ##                    ##                   ##      #",
				"#      ##################++  ##  ++#################      #",
				"#         +     +     +      ##         +     +           #",
				"#            +     +         ##      +     +     +        #",
				"###########################################################",
			},
    		{
    			"###########################################################",
    			"#          +     +     +     +     +     +     +          #",
    			"#       +     +     +     +     +     +     +     +       #",
    			"#      #############################################      #",
    			"#      ##                    ##                   ##      #",
    			"#     +##  *   *             ##            *   *  ##+     #",
    			"#      ##          ######++xx##xx++######         ##      #",
    			"#   +  ##  *    ###          ##         ###    *  ##  +   #",
    			"#      ##     ###            ##           ###     ##      #",
    			"#  +   ##   ###      ##################     ###   ##    + #",
    			"#      ##  ###    ####       ##       ####   ###  ##      #",
    			"# +    ##  ###   ##      ++xx##xx++      ##  ###  ##     +#",
    			"#      ##  ### * ##  *  ++***>#**@++  *  ##* ###  ##      #",
    			"#+     ##  ###   ##      ++######++      ##  ###  ##    + #",
    			"#      ##  ###    ###        ##        ###   ###  ##      #",
    			"# +    ##  ###      #####++  ##  ++#####    ###   ##   +  #",
    			"#      ##    ###             ##            ###    ##      #",
    			"#  +   ##  *   ###           ##          ###   *  ##  +   #",
    			"#      ##        #########################        ##      #",
    			"#    + ##  *   *             ##            *   *  ##+     #",
				"#      ##                    ##                   ##      #",
				"#      ##################++  ##  ++#################      #",
				"#         +     +     +      ##         +     +           #",
				"#            +     +         ##      +     +     +        #",
				"###########################################################",
			}
		};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 7", level);
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
    		if(ch == ERR) {
    			if(world == 0){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu1; i++){
    						if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'x'){
    							maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = ' ';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == ' '){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'O'){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				} else if(world == 1){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu2; i++){
    						if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'x'){
    							maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = ' ';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == ' '){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'O'){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[world][playery - 3 - 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '+' || maze[world][playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[world][playery - 3 + 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '+' || maze[world][playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[world][playery - 3][playerx - 2 + 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 + 1] != '>'){
							if(maze[world][playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '+' || maze[world][playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '@'){
								maze[world][playery - 3][playerx - 2] = ' ';
								if(world == 0){
									world = 1;
								} else if(world == 1){
									world = 0;
								}
							}
							for(int i = 0; i < sumportal; i++){
								if(playerx == portalx[i] && playery == portaly[i]){
									maze[world][playery - 3][playerx - 2] = '@';
									break;
								} else {
									maze[world][playery - 3][playerx - 2] = ' ';
								}
							}
							playerx += 1;
							bonus -= 5;
						} else if(maze[world][playery - 3][playerx - 2 + 1] == '>' && score == (summakan * 100)){
							score += 1000;
							maze[world][playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[world][playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = level + 1;
								break;
							} else if(pilihwin == 2){
								pilihlevel = level;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[world][playery - 3][playerx - 2 - 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '+' || maze[world][playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[world][playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = level;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, " ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = level;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
		
	}
	
int level8(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playerx = 3;
		int playery = 9;
		int count = 0;
		int score = 0;
		int bonus = 7000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int world = 0;
		int level = 8;
		int summakan = 30;
		int sumdurisemu1 = 1;
		int durisemux1[sumdurisemu1] = {28};
		int durisemuy1[sumdurisemu1] = {15};
		int sumdurisemu2 = 1;
		int durisemux2[sumdurisemu2] = {28};
		int durisemuy2[sumdurisemu2] = {15};
		int sumportal = 1;
		int portalx[sumportal] = {34};
		int portaly[sumportal] = {15};
		
		WINDOW* kotak = newwin(lebar + 4, panjang + 3, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[2][lebar][panjang] = 
		{
			{
    			"###########################################################",
    			"#        ####                *                            #",
    			"#    #####                                          + + + #",
    			"#  ###        ###############################        + +  #",
    			"####       ###+           *                 +####     +   #",
    			"#       ##+                                     +##       #",
    			"#     ##+       ###########################       +##     #",
    			"#    #+      ##+            *             +##      +##    #",
    			"#  ##+     ##+                              +##     +#    #",
    			"# #+      #+      ####################        +#     +#   #",
    			"#+      ##+     ##+                  +##       +#     #   #",
    			"#      #+     ##+      +########+       +#      #     #   #",
    			"#    ##+     #+     ##+   x   * @+##  *  +#  *  #     # * #",
    			"#    #      #+ *  ##      ######++       +#     #   * #   #",
    			"#    # *   #+     ##+         *        +##      #     #   #",
    			"# *  #     #+      #####################       +#     #   #",
    			"#    #+     ##+                             +###     +#   #",
    			"#     ##+     ###+            *          +###      +##    #",
    			"#      ##+       #########################        +##     #",
    			"#        ##+               *                    +##       #",
				"#     +    ####+                            +####     +   #",
				"#    + +       ##############################        + +  #",
				"#   + + +                                           + + + #",
				"#                            *                            #",
				"###########################################################",
			},
    		{
    			"###########################################################",
    			"#        ####                                             #",
    			"#    #####                                          + + + #",
    			"#  ###        ###############################        + +  #",
    			"####       ++##                             ##+++     +   #",
    			"#       ##+*                                   *+##       #",
    			"#     ###       ###########################       ###     #",
    			"#    ##      ++#                          +++      ###    #",
    			"#  ###     ##+*                            *+##     ##    #",
    			"# ##      ##      #+#################+        ##     ##   #",
    			"# #     ###     ##+*                 *+##      ##     #   #",
    			"# #    ##     ###      ##########       ##      #     #   #",
    			"# #  ###     ##     +##   x *   @###     ##     #     #   #",
    			"# #  #      ##     +*     #########      ##     #     #   #",
    			"# #  #     ##      #+#                 *+##     #     #   #",
    			"# #  #     #+*     ####################+       ##     #   #",
    			"# #  #+*    #+#                             ####     ##   #",
    			"# #   ++#     ####                      *+###      ###    #",
    			"# #+*  ###       #######################++        ###    ##",
    			"#  ++#   ###                                   *+##     ###",
				"#   ##     ####################################++     *+###",
				"#    ##                                              #++###",
				"#      ####################################################",
				"#                                                         >",
				"###########################################################",
			}
		};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 8", level);
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
    		if(ch == ERR) {
    			if(world == 0){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu1; i++){
    						if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'x'){
    							maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = ' ';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == ' '){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'O'){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				} else if(world == 1){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu2; i++){
    						if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'x'){
    							maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = ' ';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == ' '){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'O'){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[world][playery - 3 - 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '+' || maze[world][playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[world][playery - 3 + 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '+' || maze[world][playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[world][playery - 3][playerx - 2 + 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 + 1] != '>'){
							if(maze[world][playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '+' || maze[world][playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '@'){
								maze[world][playery - 3][playerx - 2] = ' ';
								if(world == 0){
									world = 1;
								} else if(world == 1){
									world = 0;
								}
							}
							for(int i = 0; i < sumportal; i++){
								if(playerx == portalx[i] && playery == portaly[i]){
									maze[world][playery - 3][playerx - 2] = '@';
									break;
								} else {
									maze[world][playery - 3][playerx - 2] = ' ';
								}
							}
							playerx += 1;
							bonus -= 5;
						} else if(maze[world][playery - 3][playerx - 2 + 1] == '>' && score == (summakan * 100)){
							score += 1000;
							maze[world][playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[world][playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = level + 1;
								break;
							} else if(pilihwin == 2){
								pilihlevel = level;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[world][playery - 3][playerx - 2 - 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '+' || maze[world][playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[world][playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = level;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, "  ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = level;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
		
	}
	
	int level9(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playerx = 13;
		int playery = 25;
		int count = 0;
		int score = 0;
		int bonus = 7000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int world = 0;
		int level = 9;
		int summakan = 48;
		int sumdurisemu1 = 6;
		int durisemux1[sumdurisemu1] = {9, 52, 9, 26, 35, 52};
		int durisemuy1[sumdurisemu1] = {6, 6, 23, 23, 23, 23};
		int sumdurisemu2 = 6;
		int durisemux2[sumdurisemu2] = {9, 26, 35, 22, 39, 55};
		int durisemuy2[sumdurisemu2] = {6, 11, 11, 14, 15, 16};
		int sumportal = 1;
		int portalx[sumportal] = {59};
		int portaly[sumportal] = {25};
		
		WINDOW* kotak = newwin(lebar + 3, panjang + 3, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[2][lebar][panjang] = 
		{
			{  //23456789012345678901234567890123456789012345678901234567890
    			"###########################################################",
				"#         ####           +      +           ####          #",
				"#  *    ###  *###    *    + ++ +    *    ###   ###     *  #",
				"#    ##x#       ###        ++++        ###   *   #x##     #",
				"#  ####           ###     ++++++     ###           ####   #",
				"# ###               ###    ++++    ###               #### #",
				"# ##         +        ####      ####         +        *## #",
				"# ##  *    +   +      *  #      #          +   +       ## #",
				"# ##         +          #   ++   #  *        +         ## #",
				"#  ##                  #          #                   ##  #",	
				"#   ##       *        #   + + + +  #         *       ##   #",
				"# *  ###  ++  ++  +++#    *  *  *   #+++  ++  ++  ###   * #",
				"#  ##   ++  ++  ++   #  +  +  +  +  #   ++  ++  ++   ##   #",
				"# ##                 #              #                 ##  #",
				"# #    *          *  #    +  +  +   #    *        *   ### #",
				"# #        + +       #     *   *    #       + +        ## #",
				"# #       + + +       #   +  +  +  #       + + +       ## #",
				"# #        + +         #          #         + +        ## #",
				"# ##   *           *    #    +   #     *           *   ## #",
				"#  ###                   #      #                   ####  #",
				"#    ##x##           ###x##    ##x###           ##x##     #",
				"#        #####   #####              #####   #####         #",
				"#           #######         ++         #######           @#",
				"###########################################################",
			},
    		{  //23456789012345678901234567890123456789012345678901234567890
    			"###########################################################",
				"#         ####           +      +           ####          >",
				"#  *    ###   ###    *    + ++ +    *    ###   ###     *  #",
				"#    ##x#       ###        ++++        ###       ####     #",
				"#  ####           ###     ++++++     ###           ####   #",
				"# ###               ###    ++++    ###*             *#### #",
				"# ##   *     +     *  ####      ####         +         ## #",
				"# ##       + + +         #      #          + + +       ## #",
				"# ##     + + + + +      x        x       + + + + +     ## #",
				"#  ##                  #          #                   ##  #",	
				"#   ##       *        #            #         *       ##   #",
				"#    ###  ++  ++  ++x#              #   ++  ++  ++ ###    #",
				"#  ##   ++  ++  ++   #              #x++  ++  ++  +##     #",
				"# ##                 #              #                x##  #",
				"# #   *           *  #              #   *         *   ### #",
				"# #        + +       #              #       + +        ####",
				"# #      +     +      #            #      +     +      ####",
				"# #      +     +       #          #       +     +      ##*#",
				"# ##       + +          # *++++* #          + +       ##  #",
				"#  ##*             *     #++++++#     *          *####    #",
				"#    #####           ####  ++++  ###           #####      #",
				"#        #####+++#####    + ++ +    #####+++####          #",
				"#                                                        @#",
				"###########################################################",
			}
		};
		
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 8", level);
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
    		if(ch == ERR) {
    			if(world == 0){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu1; i++){
    						if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'x'){
    							maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = ' ';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == ' '){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'O'){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				} else if(world == 1){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu2; i++){
    						if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'x'){
    							maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = ' ';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == ' '){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'O'){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[world][playery - 3 - 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '+' || maze[world][playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[world][playery - 3 + 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '+' || maze[world][playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[world][playery - 3][playerx - 2 + 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 + 1] != '>'){
							if(maze[world][playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '+' || maze[world][playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '@'){
								maze[world][playery - 3][playerx - 2] = ' ';
								if(world == 0){
									world = 1;
								} else if(world == 1){
									world = 0;
								}
							}
							for(int i = 0; i < sumportal; i++){
								if(playerx == portalx[i] && playery == portaly[i]){
									maze[world][playery - 3][playerx - 2] = '@';
									break;
								} else {
									maze[world][playery - 3][playerx - 2] = ' ';
								}
							}
							playerx += 1;
							bonus -= 5;
						} else if(maze[world][playery - 3][playerx - 2 + 1] == '>' && score == (summakan * 100)){
							score += 1000;
							maze[world][playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[world][playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = level + 1;
								break;
							} else if(pilihwin == 2){
								pilihlevel = level;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[world][playery - 3][playerx - 2 - 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '+' || maze[world][playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[world][playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = level;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, "  ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = level;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level10(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		
		//daftar warna
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_RED);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_CYAN, COLOR_BLACK);
		
		//deklarasi
		wrefresh(jendela);
		bool mati = false;
		const int lebar = 25;
		const int panjang = 60;
		const int mapx = (Maxx / 2) - (panjang / 2) + 1;
		const int mapy = (Maxy / 2) - (lebar / 2) + 1;
		int playerx = 54;
		int playery = 7;
		int count = 0;
		int score = 0;
		int bonus = 7000;
		int ch;
		int pilihpause = 0;
		int pilihwin = 0;
		int pilihgameover = 0;
		int world = 0;
		int level = 10;
		int summakan = 50;
		int sumdurisemu1 = 12;
		int durisemux1[sumdurisemu1] = {31, 32, 56, 57, 19, 20, 31, 32, 26, 27, 42, 43};
		int durisemuy1[sumdurisemu1] = {4, 4, 7, 7, 8, 8, 14, 14, 16, 16, 20, 20};
		int sumdurisemu2 = 7;
		int durisemux2[sumdurisemu2] = {17, 18, 27, 28, 26, 41, 42};
		int durisemuy2[sumdurisemu2] = {8, 8, 14, 14, 16, 20, 20};
		int sumportal = 1;
		int portalx[sumportal] = {59};
		int portaly[sumportal] = {14};
		
		WINDOW* kotak = newwin(lebar + 4, panjang + 3, mapy - 4, mapx - 3);
		keypad(kotak, TRUE);
		char maze[2][lebar][panjang] = 
		{	   //        111111111122222222223333333333444444444455555555556
			{  //23456789012345678901234567890123456789012345678901234567890
    			"###########################################################",//3
				"#                       + #+*xx                           #",//4
				"# ##################### + ##+####################  #####  #",//5
				"# #                  *# + #+                 +##  ######  #",//6
				"# # ################# # + ##+ #############+ +#  ###O xx  #",//7
				"# # +            xx*+ # + #+            * #+ +##  ######  #",//8
				"# # # ############### # + ##+#########+   #+ +###   ####  #",//9
				"# # +               + # + #+              #+*+##  ######  #",//10
				"# # ############# ### # + ##  #################  ###  ##  #",//11
				"# #               #*# #                                   #",//12
				"# ############# ##+ + #   #################################",//13
				"#               #*        ##*xx                          @#",//14
				"##############  ######################################### #",//15
				"#*                  *   xx  *#                            #",//16
				"##########+   ######    ##   #  #######################   #",//17
				"#*          ########    ##   #  ##                    +   #",//18
				"######+   ##########    ##   #  ##*  +#############   #   #",//19
				"#*       ######++###    ##   #  ## * ++*xx       +#  *+   #",//20
				"####+   ######+++###    ##   #  ##  *+#######    #+ * #   #",//21
				"#*       ######++###    ##   #  ##               +#*  +   #",//22
				"######+   ##########    ##   #  ###################   #   #",//23
				"#*          ########    ##   #                        +   #",//24
				"##########+   ######    ##   ##########################   #",//25
				"#*                     *##*                               #",//26
				"###########################################################",//27
			}, //        111111111122222222223333333333444444444455555555556
    		{  //23456789012345678901234567890123456789012345678901234567890
    			"###########################################################",//3
				"#*                      ++            ++           *+++   >",//4
				"#  +################### ++ ########## ++ #######   #####  #",//5
				"#  #+               *## ++ #  *     # ++     +++  ######  #",//6
				"#  +#  ############  +# ++ #  ####  # ++#### ##  ###++##  #",//7
				"#  #+  +       xx*+  ## ++ #  #++#  # ++     +++  ######  #",//8
				"#  +#  #  #+#+#+#+#  +# ++ #  #++#  # ++ #######   *####  #",//9
				"#  #+  +          +  ## ++ #  #++#    ++     +++  ###+##  #",//10
				"#  +#  #######+ +##  +# ++ #  #############  ##  ###++##  #",//11
				"#  #+            #+  ##    #                 ++           #",//12
				"#  +##########+ +##  +#####################################",//13
				"#               ##+      xx*## *   ##      ##      ##    @#",//14
				"##############  ############## ++  ++  ++  ++  ++  ++  ####",//15
				"#*              +++   * x * ## ##      ##      ##      +++#",//16
				"##########+   ######   +#+  #+ ############################",//17
				"#*          ########   #+#  ## +#                         #",//18
				"######+   #####+++##   +#+  #+ ##  *#############+   #+   #",//19
				"#*       ####++++###   #+#  ## +# * ++*xx        #*  +#   #",//20
				"####+   ####++++++##   +#+  #+ ##*  #########    + * #+   #",//21
				"#*       ####++++###   #+#  ## +#                #  *+#   #",//22
				"######+   #####+++##   +#+  #+ ##################+   #+   #",//23
				"#*          ########   #+#  ##                       +#   #",//24
				"##########+   ######   +#+  ##++#######################   #",//25
				"#*                   * #+# *                              #",//26
				"###########################################################",//27
			}
		};
		//gambar maze
		for(int i = 0; i < lebar; i++){
        	for (int j = 0; j < panjang; j++) {
        		if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        			wattron(kotak, COLOR_PAIR(5));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(5));
				} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
					wattron(kotak, COLOR_PAIR(4));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(4));
				} else {
					wattron(kotak, COLOR_PAIR(1));
            		mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            		wattroff(kotak, COLOR_PAIR(1));
				}
        	}
        	mvwprintw(kotak, 3 + i, panjang + 1, " ");
    	}
		wattron(kotak, COLOR_PAIR(5));
		mvwprintw(kotak, playery, playerx, "O");
		wattroff(kotak, COLOR_PAIR(5));
    	wattron(kotak, COLOR_PAIR(2));
		box(kotak, 0, 0);
    	
    	//gambar score
    	mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
    	wattroff(kotak, COLOR_PAIR(2));
    	
    	//sistem
    	wtimeout(kotak, 0);
    	while(true){
    		wattron(jendela, COLOR_PAIR(3));
    		mvwprintw(jendela, 1, 2,"Level 8", level);
    		wattroff(jendela, COLOR_PAIR(3));
    		wrefresh(jendela);
    		ch = wgetch(kotak);
    		if(ch == ERR) {
    			if(world == 0){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu1; i++){
    						if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'x'){
    							maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = ' ';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == ' '){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
							} else if(maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] == 'O'){
								maze[world][durisemuy1[i] - 3][durisemux1[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				} else if(world == 1){
    				if(count != 1000){
    					mvwprintw(kotak, 1, 21, " ");
    					wrefresh(kotak);
    					count++;
					} else {
    					for(int i = 0; i < sumdurisemu2; i++){
    						if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'x'){
    							maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = ' ';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == ' '){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
							} else if(maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] == 'O'){
								maze[world][durisemuy2[i] - 3][durisemux2[i] - 2] = 'x';
								mati = true;
								break;
							}
						}
						count = 0;
					}
				}
				if(mati == true){
					break;
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
			}else if(ch != ERR){
				if(ch == KEY_UP || ch == 'w'){
					if(maze[world][playery - 3 - 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 - 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '+' || maze[world][playery - 3 - 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 - 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery -= 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_DOWN || ch == 's'){
					if(maze[world][playery - 3 + 1][playerx - 2] != '#'){
						if(maze[world][playery - 3 + 1][playerx - 2] == '*'){
							score += 100;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '+' || maze[world][playery - 3 + 1][playerx - 2] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3 + 1][playerx - 2] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playery += 1;
						bonus -= 5;
					}
				}
				if(ch == KEY_RIGHT || ch == 'd'){
					if(maze[world][playery - 3][playerx - 2 + 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 + 1] != '>'){
							if(maze[world][playery - 3][playerx - 2 + 1] == '*'){
								score += 100;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '+' || maze[world][playery - 3][playerx - 2 + 1] == 'x'){
								mati = true;
							} else if(maze[world][playery - 3][playerx - 2 + 1] == '@'){
								maze[world][playery - 3][playerx - 2] = ' ';
								if(world == 0){
									world = 1;
								} else if(world == 1){
									world = 0;
								}
							}
							for(int i = 0; i < sumportal; i++){
								if(playerx == portalx[i] && playery == portaly[i]){
									maze[world][playery - 3][playerx - 2] = '@';
									break;
								} else {
									maze[world][playery - 3][playerx - 2] = ' ';
								}
							}
							playerx += 1;
							bonus -= 5;
						} else if(maze[world][playery - 3][playerx - 2 + 1] == '>' && score == (summakan * 100)){
							score += 1000;
							maze[world][playery - 3][playerx - 2] = ' ';
							playerx += 1;
							bonus -= 5;
							if(bonus < 0) {
								bonus = 0;
							}
							maze[world][playery - 3][playerx - 2] = 'O';
							for(int i = 0; i < lebar; i++){
        						for (int j = 0; j < panjang; j++) {
        							if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        								wattron(kotak, COLOR_PAIR(5));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(5));
									} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
										wattron(kotak, COLOR_PAIR(4));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(4));
									} else {
										wattron(kotak, COLOR_PAIR(1));
            							mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            							wattroff(kotak, COLOR_PAIR(1));
									}
        						}
        						mvwprintw(kotak, 3 + i, panjang + 1, " ");
    						}
							wattron(kotak, COLOR_PAIR(5));
							mvwprintw(kotak, playery, playerx, "O");
							wattroff(kotak, COLOR_PAIR(5));
    						wattron(kotak, COLOR_PAIR(2));
							box(kotak, 0, 0);
    						mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
							wattroff(kotak, COLOR_PAIR(2));
							wrefresh(kotak);
							napms(2000);
							pilihwin = win(jendela, Maxy, Maxx, pilihwin, score, bonus);
							if(pilihwin == 1){
								pilihlevel = level + 1;
								break;
							} else if(pilihwin == 2){
								pilihlevel = level;
								break;
							} else if(pilihwin == 3){
								pilihlevel = 0;
								break;
							}
						}
					}
				}
				if(ch == KEY_LEFT || ch == 'a'){
					if(maze[world][playery - 3][playerx - 2 - 1] != '#'){
						if(maze[world][playery - 3][playerx - 2 - 1] == '*'){
							score += 100;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '+' || maze[world][playery - 3][playerx - 2 - 1] == 'x'){
							mati = true;
						} else if(maze[world][playery - 3][playerx - 2 - 1] == '@'){
							maze[world][playery - 3][playerx - 2] = ' ';
							if(world == 0){
								world = 1;
							} else if(world == 1){
								world = 0;
							}
						}
						for(int i = 0; i < sumportal; i++){
							if(playerx == portalx[i] && playery == portaly[i]){
								maze[world][playery - 3][playerx - 2] = '@';
								break;
							} else {
								maze[world][playery - 3][playerx - 2] = ' ';
							}
						}
						playerx -= 1;
						bonus -= 5;
					}
				}
				maze[world][playery - 3][playerx - 2] = 'O';
				wattron(kotak, COLOR_PAIR(2));
				mvwprintw(kotak, 1, 1, "SCORE:	%d", score);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(ch == '\b' || ch == 'p'){
					pilihpause = pause(jendela, Maxy, Maxx, pilihpause);
				}
				for(int i = 0; i < lebar; i++){
        			for (int j = 0; j < panjang; j++) {
        				if(maze[world][i][j] == '*' || maze[world][i][j] == '>' || maze[world][i][j] == '@'){
        					wattron(kotak, COLOR_PAIR(5));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(5));
						} else if(maze[world][i][j] == '+' || maze[world][i][j] == 'x'){
							wattron(kotak, COLOR_PAIR(4));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(4));
						} else {
							wattron(kotak, COLOR_PAIR(1));
            				mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
            				wattroff(kotak, COLOR_PAIR(1));
						}
        			}
        			mvwprintw(kotak, 3 + i, panjang + 1, " ");
    			}
				wattron(kotak, COLOR_PAIR(5));
				mvwprintw(kotak, playery, playerx, "O");
				wattroff(kotak, COLOR_PAIR(5));
    			wattron(kotak, COLOR_PAIR(2));
				box(kotak, 0, 0);
				wattroff(kotak, COLOR_PAIR(2));
				wrefresh(kotak);
				if(mati == true){
					break;
				}
				if(pilihpause == 2){
					pilihlevel = level;
					break;
				} else if(pilihpause == 3){
					pilihlevel = 0;
					break;
				}
			} 
		}
		
		if(mati == true){
			wattron(kotak, COLOR_PAIR(4));
			for(int i = 0; i < lebar; i++){
       			for (int j = 0; j < panjang; j++) {
       	   			mvwaddch(kotak, 3 + i, 2 + j, maze[world][i][j]);
   				}
        		mvwprintw(kotak, 3 + i, panjang + 1, "  ");
    		}
    		wattroff(kotak, COLOR_PAIR(4));
    		wattron(kotak, COLOR_PAIR(2));
			box(kotak, 0, 0);
			wattroff(kotak, COLOR_PAIR(2));
			wrefresh(kotak);
			napms(1000);
			pilihgameover = gameover(jendela, Maxy, Maxx, pilihgameover);
		}
		
		if(pilihgameover == 1){
			pilihlevel = level;
		} else if(pilihgameover == 2){
			pilihlevel = 0;
		}
		return pilihlevel;
	}
	
	int level11(WINDOW* jendela, int Maxy, int Maxx, int pilihlevel){
		start_color();
		init_pair(1, COLOR_CYAN, COLOR_MAGENTA);
		init_pair(2, COLOR_YELLOW, COLOR_BLACK);
		
		wclear(jendela);
		wattron(jendela, COLOR_PAIR(1));
		mvwprintw(jendela, (Maxy / 2) - 5, (Maxx / 2) - 11, " C O M I N G   S O O N ");
		wattron(jendela, COLOR_PAIR(1));
		wattron(jendela, COLOR_PAIR(2));
		mvwprintw(jendela, (Maxy / 2) - 2, (Maxx / 2) - 16, "This level is not yet available.");
		mvwprintw(jendela, (Maxy / 2) - 1, (Maxx / 2) - 17, "Thank you for playing our game  ;)");
		wattron(jendela, COLOR_PAIR(2));
		wrefresh(jendela);
		wgetch(jendela);
		wclear(jendela);
		
		return 0;
	}
	
void help(WINDOW* jendela, int Maxy, int Maxx){
	wclear(jendela);
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_CYAN);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	keypad(jendela, TRUE);
	int ch;
	
		wattron(jendela, COLOR_PAIR(1));
	box(jendela, 0, 0);
	wattroff(jendela, COLOR_PAIR(1));
	wattron(jendela, COLOR_PAIR(2));
	mvwprintw(jendela, 3, (Maxx / 2) - 11, " H O W  T O  P L A Y ");
	mvwprintw(jendela, 12, (Maxx / 2) - 7, " C O N T R O L ");
	mvwprintw(jendela, 22, (Maxx / 2) - 6, " C R E D I T ");
	wattroff(jendela, COLOR_PAIR(2));
	
	wattron(jendela, COLOR_PAIR(3));
	mvwprintw(jendela, 5, (Maxx / 2) - 32, "Move the 'O' character using the arrow keys go to the finish '>'.");
	mvwprintw(jendela, 6, (Maxx / 2) - 22, "Eat all the food '*' to open the finish gate.");
	mvwprintw(jendela, 7, (Maxx / 2) - 46, "Avoid characters from dangerous '+' thorns, if the character touches the thorns you will die.");
	mvwprintw(jendela, 8, (Maxx / 2) - 24, "Also watch out for spines that can disappear 'x'.");
	mvwprintw(jendela, 9, (Maxx / 2) - 24, "Enter the '@' portal to teleport to another place.");
	mvwprintw(jendela, 14, (Maxx / 2) - 25, "|           UP           |      UP KEY / 'w'      |");
	mvwprintw(jendela, 15, (Maxx / 2) - 25, "|          DOWN          |     DOWN KEY / 'S'     |");
	mvwprintw(jendela, 16, (Maxx / 2) - 25, "|         RIGHT          |     RIGHT KEY / 'a'    |");
	mvwprintw(jendela, 17, (Maxx / 2) - 25, "|          LEFT          |     LEFT KEY / 'd'     |");
	mvwprintw(jendela, 18, (Maxx / 2) - 25, "|         PAUSE          |     BACKSPACE / 'p'    |");
	mvwprintw(jendela, 19, (Maxx / 2) - 25, "|          BACK          |       BACKSPACE        |");
	mvwprintw(jendela, 20, (Maxx / 2) - 25, "|         CHOOSE         |       ENTER KEY        |");
	mvwprintw(jendela, 24, (Maxx / 2) - 11, "Daffa Muhammad Al-Fatih");
	mvwprintw(jendela, 25, (Maxx / 2) - 7, "Rofik Ramadani");
	mvwprintw(jendela, 26, (Maxx / 2) - 11, "Ghaisan Wildan Bathsya");
	wattroff(jendela, COLOR_PAIR(3));
	wrefresh(jendela);
	do{
		ch = wgetch(jendela);
	} while(ch != '\n' && ch != '\b');
	wclear(jendela);
}

void quit(WINDOW* jendela, int Maxy, int Maxx){
	wclear(jendela);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	wattron(jendela, COLOR_PAIR(3));
    mvwprintw(jendela, Maxy / 2, Maxx / 2 - 11, "THANK YOU FOR PLAYING");
    wattroff(jendela, COLOR_PAIR(3));
    wrefresh(jendela);
    Sleep(2000);
	endwin();
    exit(0);
}

int main(){
	initscr();
	noecho();
    curs_set(0);
	refresh();
	
	//buat window
	int Maxy, Maxx;
	getmaxyx(stdscr, Maxy, Maxx);
	WINDOW* jendela = newwin(Maxy, Maxx, 0, 0);
	keypad(jendela, TRUE);
	int pilihmenu;
	int pilihlevel;
	intro(jendela, Maxy, Maxx);
	while(true){
		pilihmenu = menuutama(jendela, Maxy, Maxx);
		if(pilihmenu == 1){
			while(true){
				pilihlevel = game(jendela, Maxy, Maxx);
				if(pilihlevel == 0){
					break;
				}
				while(true){
					if(pilihlevel == 1){
						pilihlevel = level1(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 2){
						pilihlevel = level2(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 3){
						pilihlevel = level3(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 4){
						pilihlevel = level4(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 5){
						pilihlevel = level5(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 6){
						pilihlevel = level6(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 7){
						pilihlevel = level7(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 8){
						pilihlevel = level8(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 9){
						pilihlevel = level9(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 10){
						pilihlevel = level10(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 11){
						pilihlevel = level11(jendela, Maxy, Maxx, pilihlevel);
					}
					if(pilihlevel == 0){
						break;
					}
				}
			}
		} else if(pilihmenu == 2){
			help(jendela, Maxy, Maxx);
		} else if(pilihmenu == 3){
			quit(jendela, Maxy, Maxx);
		}
	}
	
	return 0;
}

