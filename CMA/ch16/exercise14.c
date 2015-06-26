int area(struct shape s)
{
    int area;

    if (s.shape_kind == RECTANGLE)
	area = s.u.rectangle.heigth * s.u.rectangle.width;
    else
	area = 3.14159 * s.u.circle.radius * s.u.circle.radius;

    return area;
}
