#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct point {
    float x;
    float y;
} point_t;

point_t create_point (float x, float y) {
    point_t new_point = {x, y};
    return new_point;
}

float distance (point_t first, point_t second) {

    float xdist = first.x - second.x;
    xdist *= xdist;
    float ydist = first.y - second.y;
    ydist *= ydist;
    float dist = sqrtf(xdist + ydist);
    return dist;
}

int main()
{
    point_t p1 = create_point(1, 1);
    point_t p2 = create_point(1, 5.5f);
    float dist = distance(p1, p2);
    printf("%f", dist);

    return 0;
}