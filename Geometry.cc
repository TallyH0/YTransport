#include "Geometry.h"

bool YGeometry::In_anode(const electron e)
{
	if( ANODE_SIZE < fabs(e.x) && fabs(e.x) < ANODE_SIZE + SPACING && ANODE_SIZE < fabs(e.y) && fabs(e.y) < ANODE_SIZE + SPACING)
	return true;
	else return false;

	return false;
}
