#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#define MAZE_SIZE 21

char maze[MAZE_SIZE][MAZE_SIZE + 1];
char path[(MAZE_SIZE*MAZE_SIZE)];
int r = 0;

void get_maze(char* file_name){
	FILE* maze_file = fopen(file_name, "r");
	if(maze_file == NULL) {
		printf("Datei konnte nicht geoeffnet werden.\n");
	}else {
		for(int i = 0; i < MAZE_SIZE+1; ++i){
			fscanf(maze_file, "%[#!@ ]%*[\n]", maze[i]);
		}
	fclose(maze_file);
	}
}

void print_maze(){
	int i, j;
	for (i = 0; i < MAZE_SIZE; ++i) {
		for (j = 0; j < MAZE_SIZE; ++j) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
}

void print_path(){	
	printf("Path: ");
	for(int i = 0; i <= ((MAZE_SIZE*MAZE_SIZE)-1); ++i){
		printf("%c", path[i]);
	}
	printf("\n");
}

void clear() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#endif
	
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void pause(unsigned int milliseconds) {
	clock_t start = clock();
	while (1000.0f * (clock() - start) / CLOCKS_PER_SEC < milliseconds);
}

bool solve_maze(unsigned int x, unsigned int y){
	int time = 250;
	clear();
	if(maze[y][x] == '!'){
		print_maze();
		print_path();
		pause(time);
		return true;
	}
		
	path[r] = 'v';
	++r;
	if(maze[y+1][x] == ' '|| (maze[y+1][x] == '!')){
		if (maze[y][x] == '@'){
		}else{maze[y][x] = 'v';}
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x,y+1);
	}
	
	path[r] = '>';
	++r;
	if(maze[y][x+1] == ' ' || maze[y][x+1] == '!'){
		if (maze[y][x] == '@'){	
		}else{maze[y][x] = '>';}
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x+1,y);
	}
	
	path[r] = '^';
	++r;
	if(maze[y-1][x] == ' ' || maze[y-1][x] == '!'){
		if (maze[y][x] == '@'){
		}else{maze[y][x] = '^';}
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x,y-1);
	}
	
	path[r] = '<';
	++r;
	if(maze[y][x-1] == ' ' || maze[y][x-1] == '!'){
		if (maze[y][x] == '@'){
		}	else{maze[y][x] = '<';}

		print_maze();
		print_path();
		pause(time);
		return solve_maze(x-1,y);
	}
	

	//---------------------------------------------------------------
	
	if(maze[y][x+1] == 'v' || maze[y][x+1] == '>' || maze[y][x+1] == '^' || maze[y][x+1] == '<'){
		maze[y][x] = 'x';
		path[r] = 'x';
		++r;
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x+1,y);
	}
	
	
	if(maze[y+1][x] == 'v' || maze[y+1][x] == '>' || maze[y+1][x] == '^' || maze[y+1][x] == '<'){
		maze[y][x] = 'x';
		path[r] = 'x';
		++r;
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x,y+1);
		
	}
	
	if(maze[y-1][x] == 'v' || maze[y-1][x] == '>' || maze[y-1][x] == '^' || maze[y-1][x] == '<'){
		maze[y][x] = 'x';
		path[r] = 'x';
		++r;
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x,y-1);
		
	}
	
	if(maze[y][x-1] == 'v' || maze[y][x-1] == '>' || maze[y][x-1] == '^' || maze[y][x-1] == '<'){
		maze[y][x] = 'x';
		path[r] = 'x';
		++r;
		print_maze();
		print_path();
		pause(time);
		return solve_maze(x-1,y);
	}
	
	else{return 0;}
}

int main(){

/*	
	get_maze("Labyrinth.txt");
	assert(solve_maze(19, 20));
	
	get_maze("Labyrinth.txt");
	assert(solve_maze(19, 19));

	get_maze("Labyrinth.txt");
	assert(solve_maze(18, 19));
*/
	get_maze("Labyrinth.txt");
	assert(solve_maze(1, 1));
	
	return 0;
}