/*
	
	Problem Description :
					     
					 1   2   3   4   5   6   7
				   #############################
				 1 #       #       #           #
				   #####   #####   #   #####   #   
				 2 #   #       #   #   #   #   #
				   #   #####   #####   #####   #
				 3 #           #   #   #   #   #   
				   #   #########   #####   #   # 
				 4 #   #                   #   #   
				   #############################  
				
				In the figure, m = 4 and n = 7. The maze is divided into sections. A section consists of 
				a closed area of the maze such that it is not possible to â€˜walkâ€™ from one section into another. 
				The given maze has 5 sections (verify this). A section is divided into units where a unit 
				is represented as one square (e.g. (2, 3)) in the figure. Each unit can have between 0 to 4 walls.

				Given a maze, you are required to 
				(a)	find the number of sections in the maze and the size (in units) of  the largest section.
				(b)	determine whether one can â€˜walkâ€™ from one unit (a, b) to another unit (c, d). 
				The unit (x, y) means the unit at row x and column y. 
				Rows and columns are numbered as shown in the figure.
	
	Solution : 
	
	Using a scale defined by the function : (M x scale) - (M -1) where scale = 3
	Given m = 4 and n = 7
	The above function will then create the following
		row = 21 
		col = 9 
	To draw maze
		for i = 2 to row i += 2
			for j = 2 to col j += 2
				read in the unit 
				convert unit to binary
				if(west)drawWest(i,j)
				if(north)drawNorth(i,j)
				if(east)drawEast(i,j)
				if(south)drawSouth(i,j)

	To count sections and find max section
		for i = 2 to row i += 2
			for j = 2 to col j += 2
				if maze[i,j] == 0 
				we are at a new section
				check if the current section is greater than the max section

*/


#include <stdio.h>
#include <stdlib.h>

#define maxUnit 15
#define ROW 3	// row scale
#define COL	3 	// col scale
#define max 50	
#define binSize 4

FILE *in;
FILE *out;

void numToBin(int[], int, int);
void buildMaze(FILE*, int**, int, int);
int **initMaze(int, int);

void printMaze(FILE *, int **, int, int);
void evalMaze(FILE*, int**, int, int);
int countSections(int **, int, int, int, int);
int findPath(int **, int, int, int, int, int, int);


int main()
{
	int m, n;

	in = fopen("input.txt","r");
	out = fopen("output.txt","w");

	if (in == NULL || out == NULL)
	{
		printf("Error opening files\n");
		return 0;
	}	

	fscanf(in,"%d %d", &m, &n);
	int **maze = initMaze(m, n), a, b, c, d;	
	int row = (m*ROW) - ( m - 1), col = (n*COL) - (n - 1), maxsec;
	
	buildMaze(in, maze,row, col);
	evalMaze(out, maze, row, col);
	fscanf(in, "%d %d %d %d", &a, &b, &c, &d);

	a *= 2;
	b *= 2;
	c *= 2;
	d *= 2;	

	if(findPath(maze,a,b,c,d,row, col)){
		printMaze(out, maze, row, col);	
	}else{
		fprintf(out, "No Path Found!\n");
	}
	
	fclose(in);
	fclose(out);
	return 0;
}


int **initMaze(int m, int n){
	int i, j, r = (m*COL) - ( m - 1), c = (n*ROW) - (n - 1);
	int **maze = malloc(sizeof(int*) * (m*COL));

	for(i = 1; i <= r; i++){

		maze[i] = malloc(sizeof(int*) * (n*ROW));

		for(j = 1; j <= c; j++){			
			maze[i][j] = 0;				
		}			
	}	
	return maze;
}


void buildMaze(FILE *in, int **maze, int m, int n){	
	void drawEast(int**, int, int);
	void drawWest(int**, int, int);
	void drawNorth(int**, int, int);
	void drawSouth(int**, int, int);

	int i, j, k, bin[binSize], unit;

	for(i = 2; i <= m; i+=2){	
		
		for(j = 2; j <= n; j+=2){
			
			fscanf(in, "%d", &unit);	// read in the values			
			numToBin(bin, unit, binSize); 	//unit to binary
			
			if(bin[0])drawWest(maze, i, j); 		// west
			if(bin[1])drawNorth(maze, i, j); 	// north
			if(bin[2])drawEast(maze, i, j); 		// east
			if(bin[3])drawSouth(maze, i, j);		// south
		}		
	}	
}



void evalMaze(FILE *out, int **maze, int r, int c){

	int i, j, maxSec = -9999, numSec = 0, sec;

	for(i = 2; i <= r; i+=2){

		for(j = 2; j <= c; j+=2){
			sec = 0;
			if(maze[i][j] == 0){ // if the position is not visited

				numSec++; // we have a new section
				sec = countSections(maze,i, j, r, c); // find the number of units in the section
				if(sec > maxSec) maxSec = sec; // stores the max section
			}
		}
	}

	fprintf(out, "Number of sections: %d\nSize of largest section: %d\n\n", numSec, maxSec);
}



int countSections(int **maze, int i, int j, int r, int c){

	if(i < 1 || i > r || j < 1 || j > c) return 0; // if we are out of the maze
		
	if(maze[i][j] == 2)return 0; // if this path belongs to another section or
								// we already visited it

	maze[i][j] = 2; // mark the position

	int n = 0, s = 0, e = 0, w = 0;
	if (maze[i-1][j] == 0) n = countSections(maze, i-2, j, r, c); // go north
	if (maze[i+1][j] == 0) s = countSections(maze, i+2, j, r, c); // go south
	if (maze[i][j-1] == 0) e = countSections(maze, i, j-2, r, c); // go east
	if (maze[i][j+1] == 0) w = countSections(maze, i, j+2, r, c); // go west

	return 1 + n + s + e + w;
}


int findPath(int **maze, int a, int b, int c, int d, int row, int col){	

	if(a < 1 || a > row || b < 1 || b > col) return 0;

	if(maze[a][b] == 1)return 0; 	// if there is a wall
	if(maze[a][b] == 3) return 0; 	// if we already passed this position
	if(maze[c][d] == 1) return 0;	// if the postion is a wall

	maze[a][b] = 3; // mark the position

	if(a == c && b == d) return 1; // if we find a path
	if(findPath(maze,a-1, b, c, d, row, col)) return 1;	// go north
	if(findPath(maze,a+1, b, c, d, row, col)) return 1;	// go south
	if(findPath(maze,a, b-1, c, d, row, col)) return 1;	// go east
	if(findPath(maze,a, b+1, c, d, row, col)) return 1;	// go west

	maze[a][b] = 0; // reset position
	
	return 0;
}


void numToBin(int arr[], int num, int size){
	int i;
	for(i = 0; i < size; i++){
		if(num >0){
			arr[i] = num%2;
			num/=2;
		}else{
			arr[i] = 0;
		}		
	}	
}

void drawEast(int**maze, int i, int j){
	maze[i-1][j+1] = 1;
	maze[i][j+1] = 1;
	maze[i+1][j+1] = 1;
}

void drawWest(int**maze, int i, int j){
	maze[i-1][j-1] = 1;
	maze[i][j-1] = 1;
	maze[i+1][j-1] = 1;
}

void drawNorth(int**maze, int i, int j){
	maze[i-1][j-1] = 1;
	maze[i-1][j] = 1;
	maze[i-1][j+1] = 1;
}

void drawSouth(int**maze, int i, int j){
	maze[i+1][j-1] = 1;
	maze[i+1][j] = 1;
	maze[i+1][j+1] = 1;
}


void printMaze(FILE *out, int **maze, int m, int n){
	int i, j;

	fprintf(out, "      ");
	for(j = 1; j <= n; j++){
		if(j%2 == 0){
			if ((j/2)/10 > 0)
				fprintf(out, "%d  ", j/2);
			else
				fprintf(out, "%d   ", j/2);
		}
	}		
	
	fprintf(out,"\n");
	for(i = 1; i<=m; i++){

		if(i%2 == 0){
			if ((i/2)/10>0)
				fprintf(out, "%d  ", i/2);
			else 
				fprintf(out, " %d  ", i/2);
		}
		else fprintf(out, "    ");
		
		for(j = 1; j <= n; j++){

			if(maze[i][j] == 1){
				fprintf(out, "# ");
			}else if(maze[i][j] == 3){
				fprintf(out, "X ");
			}
			else fprintf(out, "  ");				
		}
		fprintf(out, "\n");
	}
}