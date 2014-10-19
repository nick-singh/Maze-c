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