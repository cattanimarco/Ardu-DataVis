#include "../Display.h"

#ifndef GRAFICI_GFX_HEAT_H
#define GRAFICI_GFX_HEAT_H

Color cHeat[11] = {
	{0, 0, 0},
	{10, 0, 0},
	{75, 0, 0},
	{140, 0, 0},
	{215, 0, 0},
	{255, 11, 0},
	{255, 95, 0},
	{255, 160, 0},
	{255, 255, 0},
	{252, 255, 29},
	{255, 255, 255},
};

ColorPalette csHeat(&cHeat[0], 11);

#endif //GRAFICI_GFX_HEAT_H