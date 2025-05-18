/*

 *************************************************************************
 *                                                                       *
 *  Copyright (c) 2003,  FONG Sidney Hok Nang ( sydneyfong@sjc.edu.hk )  *
 *  All rights reserved.                                                 *
 *                                                                       *
 *  Redistribution and use in source  and binary forms, with or without  *
 *  modification, are permitted provided  that the following conditions  *
 *  are met:                                                             *
 *                                                                       *
 *     * Redistributions of source code must retain the above copyright  *
 *       notice, this list of conditions and the following disclaimer.   *
 *                                                                       *
 *     * Redistributions  in  binary  form  must  reproduce  the  above  *
 *       copyright  notice, this  list of conditions and the  following  *
 *       disclaimer  in  the  documentation  and / or  other  materials  *
 *       provided with the distribution.                                 *
 *                                                                       *
 *     * The name(s)  of the  contributors  of this software may not be  *
 *       used to endorse or promote products derived from this software  *
 *       without specific prior written permission.                      *
 *                                                                       *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *
 *  "AS IS" AND ANY  EXPRESS OR IMPLIED WARRANTIES,  INCLUDING, BUT NOT  *
 *  LIMITED TO, THE  IMPLIED WARRANTIES OF  MERCHANTABILITY AND FITNESS  *
 *  FOR A  PARTICULAR  PURPOSE  ARE DISCLAIMED. IN  NO EVENT  SHALL THE  *
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *
 *  INCIDENTAL,   SPECIAL,   EXEMPLARY,    OR   CONSEQUENTIAL   DAMAGES  *
 *  (INCLUDING, BUT NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE GOODS OR  *
 *  SERVICES; LOSS OF USE, DATA, OR  PROFITS; OR BUSINESS INTERRUPTION)  *
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  *
 *  STRICT  LIABILITY, OR  TORT  (INCLUDING  NEGLIGENCE  OR  OTHERWISE)  *
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  *
 *  OF THE POSSIBILITY OF SUCH DAMAGE.                                   *
 *                                                                       *
 *************************************************************************
 *                                                                       *
 *             ****       *           ****        ***   ***              *
 *            *    *  *   *      *   *    *  ***   **    *               *
 *            *           *         *       *   *  * *   *               *
 *             ****   *   *      *  *       *   *  *  *  *               *
 *                 *  *   *      *  *       *   *  *   * *               *
 *            *    *  *   *   *  *   *    *  ***   *    **               *
 *             ****   *   *****  *    ****        ***   ***              *
 *                                                                       *
 *************************************************************************

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "oiio.h"

// Comment this if you don't want verbose messages
// #define DEBUG

// Some return code constants
#define WRONG_ANSWER 2
#define SYSTEM_ERROR 255
#define PRESENTATION_ERROR 1
#define ACCEPTED 0

// #define DEBUG
#ifndef DEBUG
#define printf(...)
#endif

// #define printf(...)

// Well, I made it a bit larger in case i make stupid off-by-N errors...
#define MAP_SIZE 100


// Some macros
#define ASSURE(expr,err,s) if (!(expr)){printf("Error: %s\n",s);throw(err);}

using namespace std;

int correct_moves;
int bombs;
int map_h, map_w;
int presentation_error = false;
char map[MAP_SIZE][MAP_SIZE];


bool adjacent(int a, int b, int c, int d) {
	if (abs(a-c) == 0 && abs(b-d) == 1) return true;
	if (abs(a-c) == 1 && abs(b-d) == 0) return true;
	return false;
};

bool walkable(int a, int b) {
	if (map[a-1][b-1] == '0') return true; // array map is zero based
	if (map[a-1][b-1] == '1') {
		if (bombs <= 0) return false;
		bombs --;
		return true;
	};
	// something gone wrong here...
	printf("Map value not 0 or 1!\n");
	exit(255);
};

int main(int argc, char *argv[]) {
	FILE *fp1,*fp2,*fp3;

	if (argc != 4) return SYSTEM_ERROR;

	int scanf_result;

	// Correct Output (number of moves)
	fp3 = fopen(argv[3], "r");
	if (fp3 == NULL) return SYSTEM_ERROR;
	fscanf(fp3, "%d", &correct_moves);
	fclose(fp3);


	// Input Data
	fp1 = fopen(argv[1], "r");
	fscanf(fp1, "%d %d %d", &bombs, &map_h, &map_w);
	memset(map,0,sizeof(map));
	for (int i = 0 ; i < map_h; i++) {
		fgetc(fp1); // eat line
		for (int j = 0 ; j < map_w ; j ++ ) {
			map[i][j] = fgetc(fp1);
		};
	};
	fclose(fp1);

	// Check User Output
	try {
		int user_moves;
		fp2 = fopen(argv[2], "r");
		scanf_result = oiscanf(fp2, "%d\n", &user_moves);
		ASSURE(scanf_result != INPUT_WRONG, WRONG_ANSWER, "Wrong Format");
		ASSURE(scanf_result != INPUT_EOF, WRONG_ANSWER, "Premature EOF");
		if (scanf_result == INPUT_PE) presentation_error = true;

		ASSURE(user_moves == correct_moves, WRONG_ANSWER,\
				"Incorrect Number Of Moves");

		// Initial Position:

		int a,b,c,d; // a,b = new position, c,d = previous position

		// Get First one
		scanf_result = oiscanf(fp2, "%d %d\n", &c, &d);
		ASSURE(scanf_result == INPUT_PE || scanf_result == INPUT_OKAY, scanf_result, "Error reading input");
		if (scanf_result == INPUT_PE) presentation_error = true;

		// Check if starting point is valid
		ASSURE(c == 1 && d == 1, WRONG_ANSWER, "Incorrect starting point");

		// 2nd and thereafter
		for (int i = 1 ; i <= correct_moves; i++ ) {

			// Read the co-ordinates
			scanf_result = oiscanf(fp2, "%d %d\n", &a, &b);
			ASSURE(scanf_result != INPUT_WRONG, WRONG_ANSWER, "Wrong Format");
			ASSURE(scanf_result != INPUT_EOF, WRONG_ANSWER, "Premature EOF");
			if (scanf_result == INPUT_PE) presentation_error = true;
			
#ifdef DEBUG
			printf("Move (%d,  %d) ... ", a, b);
#endif

			// check whether new position is in the map
			ASSURE(a > 0 && b > 0 && a <= map_h && b <= map_w, WRONG_ANSWER,\
					"Invalid Co-ordinates");

			// check whether new position is adjacent
			ASSURE(adjacent(a,b,c,d), WRONG_ANSWER, "Non-adjacent Move");

			// check whether the new position is "walkable"
			ASSURE(walkable(a,b), WRONG_ANSWER, "Unwalkable Wall");

#ifdef DEBUG
			// Debug use only ;-p
			if (map[a-1][b-1] == '1') 
				printf("Okay! (bombs - 1)\n"); 
			else 
				printf("Okay!\n");
#endif

			// set the current position to become previous position.
			c = a;
			d = b;
		};

		// Check whether the final destination is correct.
		ASSURE(c == map_h && d == map_w , WRONG_ANSWER, "Wrong Destination");

		// check whether there is more output at the end

		c = getc(fp2);
		if (c != EOF) {
			while (c == ' ' || c == '\n' || c == 13) {
				c = getc(fp2);
			};
			ASSURE(c == EOF, WRONG_ANSWER, "Stuff after correct output");

			// EOF reached => only spaces at the end
			presentation_error = true;
		};

		// Close the file
		fclose(fp2);

	} catch ( int k ) {
		// Close the file first
		fclose(fp2);
		printf("Catch: [Returning: (%d)]\n", k);
		return k;
	};

	if (presentation_error) {
		printf("Presentation Error\n");
		return PRESENTATION_ERROR;
	};

	printf("Accepted\n");
	return ACCEPTED;
};

// End of Code

