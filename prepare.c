/*
	libxbee - a C library to aid the use of Digi's XBee wireless modules
	          running in API mode (AP=2).

	Copyright (C) 2009	Attie Grande (attie@attie.co.uk)

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.	If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>

#include "internal.h"
#include "ll.h"
#include "xbee_int.h"
#include "conn.h"
#include "pkt.h"

EXPORT INIT void xbee_init(void) {
	if ((xbeeList = ll_alloc()) == NULL) {
		fprintf(stderr, "libxbee: failed to initialize xbeeList...\n");
	}
	if ((conList = ll_alloc()) == NULL) {
		fprintf(stderr, "libxbee: failed to initialize conList...\n");
	}
	if ((pktList = ll_alloc()) == NULL) {
		fprintf(stderr, "libxbee: failed to initialize pktList...\n");
	}
}

EXPORT FINI void xbee_fini(void) {
	if (xbeeList) {
		ll_free(xbeeList, (void(*)(void*))xbee_shutdown);
	}
	if (conList) {
		ll_free(conList, (void(*)(void*))xbee_conEnd);
	}
	if (pktList) {
		ll_free(pktList, (void(*)(void*))xbee_pktFree);
	}
}
