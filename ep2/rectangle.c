#include <stdio.h> //Input and Output library
#include <stdlib.h> // System comands library
#include <math.h> //Math livrary, used for taking the square and making a power. 

void calc_info_retangulo( float length, float width, float *area, float *perimeter, float *diagonal) // Name and constants of the function to make the pointers
{
    *area = length * width; // Pointer of the Area of the rectangle
    *perimeter = 2 * (length + width); // Pointer of the Perimeter of the rectangle
    *diagonal = sqrt(pow(length, 2) + pow(width, 2)); // Pointer of the Diagonal of the rectangle
}


int main() // Main function
{
    float width, length, area, perimeter, diagonal; // Variable declaration

    printf("Write the length of the rectangle: \n"); // Call to the user and instructions
    scanf("%f", &length); // Input for the Length value

    printf("Write the length of the rectangle: \n"); // Call to the user and instructions
    scanf("%f", &width); // Input for the Width value

    calc_info_retangulo(length, width, &area, &perimeter, &diagonal); // Call the function calc_info_retangulo 

    printf("The area of the rectangle is %.2f. \n", area); // Output for the first value
    printf("The perimeter of the rectangle is %.2f. \n", perimeter); // Output for the second value
    printf("The diagonal of the rectangle is %.2f. \n", diagonal); // Output for the third value

    system("pause");
    return 0;
    

}
