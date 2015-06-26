#include <stdio.h>

struct point { int x, y; };

struct rectangle { struct point upper_left, lower_right; };

int area(struct rectangle);
struct point center(struct rectangle);

int main(void)
{
    struct rectangle r;
    struct point c;
    int a;

    printf("Enter x and y coordinates of upper left corner: ");
    scanf("%d %d", &r.upper_left.x,&r.upper_left.y);
    printf("Enter x and y coordinates of lower right corner: ");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);

    a = area(r);
    c = center(r);

    printf("Area of rectangle: %d\nCenter point: (%d, %d)\n", a, c.x, c.y);

    return 0;
}

int area(struct rectangle rect)
{
    int width = rect.lower_right.x - rect.upper_left.x;
    int heigth = rect.upper_left.y - rect.lower_right.y;

    return width * heigth;
}

struct point center(struct rectangle rect)
{
    int x = (rect.lower_right.x - rect.upper_left.x) / 2;
    int y = (rect.upper_left.y - rect.lower_right.y) / 2;

    return (struct point) { x, y};
}
