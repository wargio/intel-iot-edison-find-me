#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

void bellaRoba(float ax, float ay, float ad, float bx, float by, float bd, float cx, float cy, float cd, float *x, float *y);

int main(int argc, char* argv[]){
	float ax, ay, a, bx, by, b, cx, cy, c, x, y;
	if(argc != 10){
		printf("%s <ax> <ay> <da> <bx> <by> <db> <cx> <cy> <dc>\n", argv[0]);
		return 1;
	}

	ax=	atof(argv[1]);
	ay=	atof(argv[2]);
	a=	atof(argv[3]);
	bx=	atof(argv[4]);
	by=	atof(argv[5]);
	b=	atof(argv[6]);
	cx=	atof(argv[7]);
	cy=	atof(argv[8]);
	c=	atof(argv[9]);
/*
	x = ((cy - ay) / (by - ay)) * (b*b - a*a - bx*bx + ax*ax - by*by + ay*ay) + cx*cx - ax*ax + cy*cy - ay*ay - c*c + a*a;
	x = (-x) / (2 * (cx - ax) - ((cy - ay) / (by - ay))*(bx - ax));
	y = ((b*b - a*a) / (2 * (by - ay))) - ((bx*bx - ax*ax) / (2 * (by - ay))) - ((by + ay) / 2) - x*((bx - ax) / (by - ay));
*/
	bellaRoba(ax, ay, a, bx, by, b, cx, cy, c, &x, &y);
	printf("%.2f %.2f\n", x, y);
	return 0;
}

void bellaRoba(float ax, float ay, float ad, float bx, float by, float bd, float cx, float cy, float cd, float *x, float *y){
	float minA, minB, minC, pA, pB, pC, e;
	*x = 0.f;
	*y = 0.f;
	minA = pow(*x - ax, 2) + pow(*y - ay, 2) - ad*ad;
	minB = pow(*x - bx, 2) + pow(*y - by, 2) - bd*bd;
	minC = pow(*x - cx, 2) + pow(*y - cy, 2) - cd*cd;

	do{
		e = abs(minA)/ad + abs(minB)/bd + abs(minC)/cd;

		*x += 1.0f;

		minA = pow(*x - ax, 2) + pow(*y - ay, 2) - ad*ad;
		minB = pow(*x - bx, 2) + pow(*y - by, 2) - bd*bd;
		minC = pow(*x - cx, 2) + pow(*y - cy, 2) - cd*cd;

	} while ((abs(minA)/ad + abs(minB)/bd + abs(minC)/cd) < e);
	*x -= 1.0f;
	minA = pow(*x - ax, 2) + pow(*y - ay, 2) - ad*ad;
	minB = pow(*x - bx, 2) + pow(*y - by, 2) - bd*bd;
	minC = pow(*x - cx, 2) + pow(*y - cy, 2) - cd*cd;
	do{
		e = abs(minA)/ad + abs(minB)/bd + abs(minC)/cd;

		*y += 1.0f;

		minA = pow(*x - ax, 2) + pow(*y - ay, 2) - ad*ad;
		minB = pow(*x - bx, 2) + pow(*y - by, 2) - bd*bd;
		minC = pow(*x - cx, 2) + pow(*y - cy, 2) - cd*cd;

	} while ((abs(minA)/ad + abs(minB)/bd + abs(minC)/cd) < e);
	*y -= 1.0f;
}

/*
  Napoleone
  Y
Frequency:2.412 GHz (Channel 1)
Address: E8:FC:AF:A6:0C:F2
Quality=59/70  Signal level=-50 dBm  3.063458
  X
Quality=58/70  Signal level=-52 dBm  3.936612


SkywardHackaton (ok)
Address: 30:46:9A:1E:77:50
  Y
Frequency:2.412 GHz (Channel 1)
Quality=63/70  Signal level=-32 dBm 0.385666
  X
Quality=52/70  Signal level=-58 dBm 7.854574

SDK-IOT
Address: 00:22:6B:F6:79:AF
  Y
Frequency:2.462 GHz (Channel 11)
Quality=53/70  Signal level=-52 dBm 3.856665 + 9db
  X
Quality=57/70  Signal level=-53 dBm 4.327249 + 9db
*/
