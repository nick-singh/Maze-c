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




	Full Problem : 
					Maze

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

				The figure shows the layout of a maze consisting of m rows and n columns (m, n <= 50). In the figure, m = 4 and n = 7. The maze is divided into sections. A section consists of a closed area of the maze such that it is not possible to ‘walk’ from one section into another. The given maze has 5 sections (verify this). A section is divided into units where a unit is represented as one square (e.g. (2, 3)) in the figure. Each unit can have between 0 to 4 walls.

				Given a maze, you are required to 
				(a)	find the number of sections in the maze and the size (in units) of  the largest section.
				(b)	determine whether one can ‘walk’ from one unit (a, b) to another unit (c, d). The unit (x, y) means the unit at row x and column y. Rows and columns are numbered as shown in the figure.

				Data is supplied as follows: 

				The first line contains the values for m and n, in that order.

				Each of the next m lines describes the n units in each row. Each unit is described by a number, u, from 0 to 15. The value of u is determined by which walls, if any, surround the unit; 0 means the unit has no walls. The values 1, 2, 4 and 8 are added to u for a wall to the west, north, east and south, respectively. For example, a value of 9 (1 + 8) means there is a wall to the west and one to the south (e.g. unit (2, 2)). Note that inner walls are defined twice, for example, as the south wall of one unit and the north wall of the unit below. Data for the maze shown would be supplied as follows:

				4 7
				11 6 11 6 3 10 6
				7 9 6 13 5 15 5
				1 10 12 7 13 7 5
				13 11 10 8 10 12 13

				Read the data and print the maze. Print the number of sections and the size of the largest section. For the given maze, the answers should be:

				Number of sections: 5
				Size of largest section: 9

				The next data line contains values for a, b, c and  d. Determine if it is possible to ‘walk’ from unit (a, b) to unit (c, d). If it is possible, print the maze, with x’s indicating the path. If it is not possible, print an appropriate message. For example, given the data

				1  2  2  1

				your program should print:


				     1   2   3   4   5   6   7
				   #############################
				 1 #     x #       #           #
				   ##### x #####   #   #####   #   
				 2 # x # x x x #   #   #   #   #
				   # x ##### x #####   #####   #
				 3 # x x x x x #   #   #   #   #   
				   #   #########   #####   #   # 
				 4 #   #                   #   #   
				   #############################  


				You may print your maze using any (reasonable) scale you wish.
