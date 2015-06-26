#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};
struct color make_color(int red;
			int green;
			int blue;
    );

int main(void)
{
    int r, g, b;
    struct color c;
    printf("Enter color intensities: ");
    scanf("%d %d %d", &r, &g, &b);

    c = make_color(r,g,b);
    
    printf("Red: %d, Green: %d, Blue: %d\n", c.red, c.green, c.blue);
    
    return 0;
}
struct color make_color(int red,
			int green,
			int blue)
{
    struct color new_color;

    if (red < 0)
	red = 0;
    else if (red > 255)
	red = 255;
    new_color.red = red;
 
    if (green < 0)
	green = 0;
    else if (green > 255)
	green = 255;
    new_color.green = green;
    
    if (blue < 0)
	blue = 0;
    else if (blue > 255)
	blue = 255;
    new_color.blue = blue;

    return new_color;
}
