#include <iostream> 
#include <cmath>     // Allows you to use functions such as sin, cos, tan, pow, etc. 
using namespace std; 

// Global constants to be used in this program
const double PI = 3.14159; 
const double GRAVITY = 9.81; // Gravitational acceleration in m/s^2

// Function to determine the distance the snowball was catapulted
double launch_distance(double launch_speed, double launch_angle, double wind_speed) {
    // Step 1: Convert angle to radians
    double radians = launch_angle * (PI / 180);

    // Step 2: Calculate the first term of the distance equation
    double distance_1 = pow(launch_speed, 2) * sin(2 * radians) / GRAVITY;

    // Step 3: Calculate the second term of the distance equation
    double distance_2 = 2 * wind_speed * launch_speed * sin(radians) / GRAVITY;

    // Step 4: Return the total distance
    double distance = distance_1 + distance_2;
    return distance;
}

// Function to print a summary of the tests
void printResults(double launch_speed, double launch_angle, double wind_speed, double distance) {
    cout << "For these launch settings: " << endl;
    cout << "   speed = " << launch_speed << endl;
    cout << "   angle = " << launch_angle << endl;
    cout << "   wind speed = " << wind_speed << endl;
    cout << "The distance traveled was " << distance << endl;
    cout << endl;
}

// Main program
// Tests the launch_distance function
int main() {
    double speed, angle, windForwardCatapult, dist;

    // Test 1
    speed = 150.0; 
    angle = 45.0;
    windForwardCatapult = 17.5;
    dist = launch_distance(speed, angle, windForwardCatapult);
    printResults(speed, angle, windForwardCatapult, dist);

    // Test 2
    speed = 265.4; 
    angle = 32.9;
    windForwardCatapult = 8.1;
    dist = launch_distance(speed, angle, windForwardCatapult);
    printResults(speed, angle, windForwardCatapult, dist);

    // Test 3
    speed = 74.2;
    angle = 56.8;
    windForwardCatapult = 8.1;
    dist = launch_distance(speed, angle, windForwardCatapult);
    printResults(speed, angle, windForwardCatapult, dist);

    return 0;
}