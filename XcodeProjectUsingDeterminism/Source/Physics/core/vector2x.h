/*
 *  vector2x.h
 *  waves2
 *
 *  Created by arun on 01/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef VECTOR2X_H
#define VECTOR2X_H

#include "pxMath.h"
#include "vector2.h"
class vector2x
{
public:
	intx x, y;
	
	vector2x()						{	x=y=0;					}
	vector2x(int xx, int yy)		{	x=xx;	y=yy;			}
	vector2x(float xx, float yy)	{	x=FTOX(xx);	y=FTOX(yy);	}
	vector2x(const vector2x& v)		{	x=v.x;	y=v.y;			}
    vector2x(const vector2f& v)     {   x=FTOX(v.x); y=FTOX(v.y);   }
	~vector2x(){}
	
	void operator=(const vector2x& v)	{	x=v.x; y=v.y;	}
    bool operator==(const vector2x& v)	{	return (x==v.x && y==v.y);	}
	vector2x operator-()				{	return vector2x(-x, -y);	}
	vector2x operator+(const vector2x& v) 	{	return vector2x(x+v.x, y+v.y);	}
	vector2x operator-(const vector2x& v)	{	return vector2x(x-v.x, y-v.y);	}
	void operator+=(const vector2x& v) 	{	x+=v.x; y+=v.y;	}
	void operator-=(const vector2x& v)	{	x-=v.x; y-=v.y;	}
	vector2x operator*(const int n)			{	return vector2x(MULTX(x, n), MULTX(y, n));	}
	vector2x operator*(const float n)		{	return vector2x(MULTX(x, FTOX(n)), MULTX(y, FTOX(n)));	}
	
	void setx(int xx, int yy)			{	x=xx;	y=yy;	}
	void zerox()						{	x=y=0;	}
	
	__int64_t lengthSquaredx()				{	return MULTX64(x, x)+MULTX64(y, y);			}
	unsigned int lengthx()						{	return pxMath::SQRT(lengthSquaredx());	}
	__int64_t dotx(const vector2x& v)		{	return MULTX(x, v.x)+MULTX(y, v.y);		}
	
//	vector2x cross(const vector2x& v)
//	{
//		vector3x res;
//		res.x=MULTX(y, v.z)-MULTX(z, v.y);
//		res.y=MULTX(z, v.x)-MULTX(x, v.z);
//		res.z=MULTX(x, v.y)-MULTX(y, v.x);
//		return res;
//	}
	
	int normalizex()
	{
		__int64_t n, oon;
		n=lengthSquaredx();
		if(n==0 || n==FX_ONE) return 0;
		
		n=pxMath::SQRT(n);
		oon = FX_ONE;
		
        float oonf = 1.0f/XTOF(n);
        x = FTOX(XTOF(x)*oonf);
        y = FTOX(XTOF(y)*oonf);
        return FTOX(oonf);
//        oon=DIVX(oon, n);
//
//        x=MULTX(x, oon);
//        y=MULTX(y, oon);
		
//        return oon;
	}
	
};

#endif
