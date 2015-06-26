#include <stdio.h>

#define PI 3.14f

int main(void)
{
    float radius = 0.0f, volume = 0.0f;
    
    printf("Enter radius: ");
    scanf("%f", &radius);

    volume = radius * radius * radius * (4.0f / 3.0f) * PI;
    
    printf("The volume of a sphere of radius %.2f is %.2f.", radius, volume);
    
    return 0;
}
