#ifndef GRAFICI_GFX_DATA_DECORATOR_INTERPOLATOR_H
#define GRAFICI_GFX_DATA_DECORATOR_INTERPOLATOR_H

#include "../Data.h"

#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

class DataSetInterpolator : public DataSet
{
public:
	void begin(DataSet *dataSet, int interpolationSteps);
	void end(void);
	DataPoint getDataPoint(int index);
	void refresh();
	int size(void);

private:
	DataSet *dataSet;
	int numElem;
};

void DataSetInterpolator::begin(DataSet *dataSet, int interpolationSteps)
{
	this->dataSet = dataSet;
	numElem = interpolationSteps;
}

void DataSetInterpolator::end(void)
{
}

DataPoint DataSetInterpolator::getDataPoint(int index)
{
	int bin = 0;
	DataPoint p;

	if (index < numElem)
	{
		p.x = (1.0 * index) / (numElem - 1);
		// check that we are in the correct bin
		while (p.x > dataSet->getDataPoint(bin + 1).x)
		{
			bin++;
			if (bin == dataSet->size())
			{
				bin--;
				break;
			}
		}
		float fractBetween = (p.x - dataSet->getDataPoint(bin).x) / (dataSet->getDataPoint(bin + 1).x - dataSet->getDataPoint(bin).x);
		p.y = dataSet->getDataPoint(bin + 1).y * fractBetween + dataSet->getDataPoint(bin).y * (1.0 - fractBetween);
		p.z = dataSet->getDataPoint(bin + 1).z * fractBetween + dataSet->getDataPoint(bin).z * (1.0 - fractBetween);
	}

	return p;
}

int DataSetInterpolator::size(void)
{
	return numElem;
}

void DataSetInterpolator::refresh(void)
{
	dataSet->refresh();
}

#endif //GRAFICI_GFX_DATA_DECORATOR_INTERPOLATOR_H