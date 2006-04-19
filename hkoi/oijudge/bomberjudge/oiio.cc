/*

 **************************************************************************
 *                                                                        *
 *   Copyright (c) 2003,  FONG Sidney Hok Nang ( sydneyfong@sjc.edu.hk )  *
 *   All rights reserved.                                                 *
 *                                                                        *
 *   Redistribution and use in source  and binary forms, with or without  *
 *   modification, are permitted provided  that the following conditions  *
 *   are met:                                                             *
 *                                                                        *
 *      * Redistributions of source code must retain the above copyright  *
 *        notice, this list of conditions and the following disclaimer.   *
 *                                                                        *
 *      * Redistributions  in  binary  form  must  reproduce  the  above  *
 *        copyright  notice, this  list of conditions and the  following  *
 *        disclaimer  in  the  documentation  and / or  other  materials  *
 *        provided with the distribution.                                 *
 *                                                                        *
 *      * The name(s)  of the  contributors  of this software may not be  *
 *        used to endorse or promote products derived from this software  *
 *        without specific prior written permission.                      *
 *                                                                        *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *
 *   "AS IS" AND ANY  EXPRESS OR IMPLIED WARRANTIES,  INCLUDING, BUT NOT  *
 *   LIMITED TO, THE  IMPLIED WARRANTIES OF  MERCHANTABILITY AND FITNESS  *
 *   FOR A  PARTICULAR  PURPOSE  ARE DISCLAIMED. IN  NO EVENT  SHALL THE  *
 *   COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *
 *   INCIDENTAL,   SPECIAL,   EXEMPLARY,    OR   CONSEQUENTIAL   DAMAGES  *
 *   (INCLUDING, BUT NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE GOODS OR  *
 *   SERVICES; LOSS OF USE, DATA, OR  PROFITS; OR BUSINESS INTERRUPTION)  *
 *   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  *
 *   STRICT  LIABILITY, OR  TORT  (INCLUDING  NEGLIGENCE  OR  OTHERWISE)  *
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  *
 *   OF THE POSSIBILITY OF SUCH DAMAGE.                                   *
 *                                                                        *
 **************************************************************************
 *                                                                        *
 *             ****       *           ****        ***   ***               *
 *            *    *  *   *      *   *    *  ***   **    *                *
 *            *           *         *       *   *  * *   *                *
 *             ****   *   *      *  *       *   *  *  *  *                *
 *                 *  *   *      *  *       *   *  *   * *                *
 *            *    *  *   *   *  *   *    *  ***   *    **                *
 *             ****   *   *****  *    ****        ***   ***               *
 *                                                                        *
 **************************************************************************

*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oiio.h"

#ifdef DEBUG
#define debugf printf
#else
#define debugf(...)
#endif

#define ASSURE(expr,err,s) if (!(expr)){debugf("Error: %s\n",s);throw(err);}

bool is_space(int c) {
	if (c == ' ' || c == '\n' || c == 13 ) return true;
	return false;
};

bool is_numeric(int c) {
	if (c >= '0' && c <= '9') return true;
	return false;
};


int checkfmt(FILE *fp, int &flags, char *fmt, int &c) {
	debugf("Checking: [%s]\n", fmt);
	// eat the formatting
	while (*fmt != 0) {
		// Get input
		c = fgetc(fp);
		if (c == EOF) return INPUT_EOF;
		// ASSURE( c != EOF , INPUT_EOF, "Premature EOF");

		// If it matches then go on
		if ( c == *fmt ) {
			debugf("[%c] [%c] ~ \n", c, *fmt);
			fmt ++;
			continue;
		};

		debugf("[%c] [%c]!!!\n", c, *fmt);

		// Otherwise check whether it is a PE

		// strip whitespaces
		while ( is_space(*fmt) ) fmt++;
		// If the format string reaches the end, we mark PE and quit
		if (*fmt == 0) {
			flags = flags | INPUT_PE;
			ungetc(c, fp);
			break;
		};
		while ( is_space(c) ) {
			c = fgetc(fp);
			if (c == EOF) return INPUT_EOF;
			// ASSURE( c != EOF , INPUT_EOF, "Premature EOF");
		};

		
		// If they aren't equal then apparently input is in wrong format
		if (*fmt != c) return INPUT_WRONG;
		ASSURE( *fmt == c , INPUT_WRONG, "Wrong input format" );

		flags = flags | INPUT_PE;
		debugf("[%c] [%c] ... %d\n", c, *fmt, flags);

		fmt++;
	};
	return INPUT_OKAY;
};

int oiscanf(FILE *fp, const char *format, ...) {
	int flags;
	va_list ap;
	try {
		int c = 1234;
		char *str;
		int ret = 0;
		char *fmt; // variable char * instead of const char *
		fmt = (char *) malloc(strlen(format));
		ASSURE(fmt != NULL, INPUT_UNKNOWN, "Memory error, cannot malloc");

		strcpy(fmt, format);
		
		flags = 0; // clear the variable first

		va_start(ap, format);

		// While %d is found in format
		while ( (str = strstr(fmt, "%d")) != NULL ) {
			// Remove the %d
			*str = 0;
			str++;
			*str = 0;
			str++;
			


			// Eat the format
			ret = checkfmt(fp, flags, fmt, c);
			// Check for errors
			ASSURE(ret != INPUT_WRONG, INPUT_WRONG, "Wrong Input");
			ASSURE(ret != INPUT_EOF, INPUT_EOF, "Premature EOF");
			

			// check for whitespace

			c = fgetc(fp);
			while (is_space(c)) {
				c = fgetc(fp);
				flags = flags | INPUT_PE;
			};

			ungetc(c, fp);

			// Eat the integer
			int k = 0;
			int ate = false;

			while (true) {
				c = fgetc(fp);
				ASSURE(c != EOF, INPUT_EOF, "Premature EOF");
				debugf("Number ate: %d\n", c);
				if (!is_numeric(c)) break;

				ate = true;
				ASSURE(k <= 214748364, INPUT_WRONG, "Wrong Input (Integer Overflow)");
				k = k * 10;
				k += c - '0';
			};

			int *tmp = va_arg(ap, int *);
			*tmp = k;

			ASSURE(ate, INPUT_WRONG, "Wrong Input (can't find %d)");
			ungetc(c, fp);

			debugf("%d\n", k);
			fmt = str;
		};
		
		// Eat the last format
		ret = checkfmt(fp, flags, fmt, c);
		// Check for errors
		ASSURE(ret != INPUT_WRONG, INPUT_WRONG, "Wrong Input");
		ASSURE(ret != INPUT_EOF, INPUT_EOF, "Premature EOF");
	} catch (int err) {
		flags = flags | err;
	};

	va_end(ap);

	if ( (flags & INPUT_WRONG) != 0) { return INPUT_WRONG; };
	if ( (flags & INPUT_EOF) != 0) { return INPUT_EOF; };
	if ( (flags & INPUT_UNKNOWN) != 0) { return INPUT_UNKNOWN; };
	if ( (flags & INPUT_PE) != 0 ) {
		return INPUT_PE;
	};

	return INPUT_OKAY;
};

