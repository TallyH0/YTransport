#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <cmath>
#include "YTransport.h"
#include "electron.h"

#define SPACING 2
#define ANODE_SIZE 0.5

class electron;

class YGeometry
{
	public:
	YGeometry() {};
	bool In_anode(const electron);	
};

#endif
