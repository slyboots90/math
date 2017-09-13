/*
 * DHparam.h
 *
 *  Created on: 4 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#ifndef DHPARAM_H_
#define DHPARAM_H_

#include "Matrix.h"
#include <stdio.h>
#include <vector>

using namespace std;

#define PI 3.14159265

enum angleUnit {
	Degrees,
	Radians
};

enum jointType {
	Rotational,
	Linear
};

struct jointParams {
	double d;				// segment offset
	double theta;			// angle of joint
	double r;				// segment length
	double alpha;			// twist angle
	angleUnit unit;			// angel unit
	jointType type;			// type of joint
};

class DHparam {

	shared_ptr < vector < jointParams > > transformations;
	shared_ptr < Matrix > singleHomogeneousTransformation( unsigned int );
	bool validateParams( jointParams );
	shared_ptr < Matrix > transformation( unsigned int );
	void designateCoordinates( void );

	struct xyzRelativeToBase {
		double x;
		double y;
		double z;
	} end_coordination;

public:
	DHparam();
	virtual ~DHparam();
	bool addJointParams( jointParams );
	bool removeLastJointParams( void );
	const jointParams * getJointParams( unsigned int );
	unsigned int getNoOfJoints( void );
	double getPositionX( void );
	double getPositionY( void );
	double getPositionZ( void );
};

#endif /* DHPARAM_H_ */
