#include <stdio.h>

int main(void)
{
    int height, length, width, volume, weigth;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);
    volume = height * length * width;
    weigth = (volume + 165) / 166;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weigth (pounds): %d\n", weigth);

    return 0;
}
