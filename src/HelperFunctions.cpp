/*
 * HelperFunctions.cpp
 *
 *  Created on: 8 sep. 2017
 *      Author: mateusz.fraszczynski
 */

#include "../include/HelperFunctions.h"
// Include UI
#include "../include/UI/AddJointWindow.h"
// Include Classes
// Include libs

extern HWND input[ INPUT_BOXES ];

bool verifyAndAddValues( DHparam * dhp ) {
	if ( dhp == NULL ) return false;
	jointParams jParams;
	for ( unsigned int i = 0 ; i < INPUT_BOXES ; i += 2 ) {
		double value = getValues( i );
		switch ( i ) {
				case 0:
					jParams.d = value;
					break;
				case 2: {
					if ( ! (value < 360 && value > -360) ) return false;
					jParams.theta = value;
					break;
				}
				case 4:
					jParams.r = value;
					break;
				case 6: {
					if ( ! (value < 360 && value > -360) ) return false;
					jParams.alpha = value;
					break;
				}
				default:
					break;
		}
	}
	dhp->addJointParams( jParams );
	return true;
}

double getValues( unsigned int index ) {
	TCHAR buff_h[ 20 ];
	TCHAR buff_l[ 20 ];
	GetWindowText( input[ index ] , buff_h , 20 );
	GetWindowText( input[ index + 1 ] , buff_l , 20 );
	string doubl_h = buff_h ;
	string doubl_l = buff_l ;
	string string_v = doubl_h + "." + doubl_l;
	double double_v = atof( string_v.c_str( ) );
	return double_v;
}