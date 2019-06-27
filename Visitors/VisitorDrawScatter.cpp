#include "VisitorDrawScatter.h"

void VisitorDrawScatter::visit(Dataset *dataset, Boundaries *boundaries)
{
	for (PointIterator it = dataset->beginIt(); it != dataset->endIt(); ++it)
	{
		_driver->drawPixel(boundaries->project(*it).setColor((*it).value,_colorScheme->colors,_colorScheme->size));
	}
}

