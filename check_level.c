/*
 * Copyright 2011-2019 Thierry FOURNIER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License.
 *
 */
int check_level(int points) {
	/**/ if(                   points <    99)
		return 1;
	else if(points >=   100 && points <   199)
		return 2;
	else if(points >=   200 && points <   299)
		return 2;
	else if(points >=   300 && points <   399)
		return 3;
	else if(points >=   400 && points <   499)
		return 4;
	else if(points >=   500 && points <   599)
		return 5;
	else if(points >=   600 && points <   699)
		return 6;
	else if(points >=   700 && points <   799)
		return 7;
	else if(points >=   800 && points <   899)
		return 8;
	else if(points >=   900 && points <   999)
		return 9;
	else if(points >=  1000 && points <  1099)
		return 10;
	else if(points >=  1100 && points <  1199)
		return 11;
	else if(points >=  1200)
		return 12;
	return 12;
}
