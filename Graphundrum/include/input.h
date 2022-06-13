/*
    Graphundrum
    Copyright (C) 2015-2016 Demonic Benefactor <demonic@tutanota.de>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef __input__
#define __input__

typedef struct {
	int x;
	int y;
} position;

typedef struct {
	int close;
	position mousePosition;
	int mouseLeft;
	int mouseRight;
	int mouseMiddle;
	
	int esc;
	int left;
	int right;
	int up;
	int down;
	int space;
} inputEvents;

void Graph_handleInput(inputEvents *Events);

#endif
