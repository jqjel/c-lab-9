#include <iostream> 
#include <cmath>     //allows you to use functions such as sin, cos, tan, pow, etc. 
using namespace std; 

// global constants to be used in this program
const double PI = 3.14159; 
const double GRAVITY = 9.81; // gravitational acceleration in m/s^2

// function to determine the distance the snowball was catapulted
// TODO: copy your launch_distance function code here

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

// Main program
// Calculates the optimum angle and speed to launch a snowball into Ohio Stadium!
int main() { 
  // Declare variables (such as to track the best angle and distance)
  double distanceToStadium = 7560; // in meters
  double closestDifference = -1.0; // set this to be negative to start
  double bestSpeed;
  double bestAngle;
  int angle = 0; 

  double maxAngle = 90; // the maximum angle the catapult can launch at
  double maxSpeed = 270; // the maximum speed the catapult can launch at
  double windAtCatapult;

  // Get how fast the wind is blowing
  cout << "How fast is the wind blowing in the direction of the catapult? (in m/s) ";
  cin >> windAtCatapult;


  // The angles from zero the maximum angle specified above
  while (angle <= maxAngle) {

     ++angle;

    // The speeds range from zero to the maximum speed specified above
    for (int speed = 0; speed <= maxSpeed; ++speed) {

      

      // Calculate launch distance given angle and speed
      double dist = launch_distance(speed, angle, windAtCatapult);
      // Note: speed and angle here are integer types, but when they are passed to 
      // launch_distance, they are converted into doubles. That is okay for 
      // what we are doing here (it's not a bug), but it's something to be careful
      // of when writing future programs!

      // Calculate how far from the target the snowball landed
      double distanceAway = abs(dist-distanceToStadium); 

      // if this is the first distance calculated, then set this combination
      // to be the new "best combination" (because there is nothing to compare it to, yet)
      if (closestDifference < 0.0) {
        closestDifference = distanceAway;
        bestAngle = angle;
        bestSpeed = speed;
      }
      // otherwise, check to see if this snowball landed closer to the target;
      // if it did, update these paramters to be the new "best combination"
      if (distanceAway < closestDifference){
          closestDifference = distanceAway;
          bestAngle = angle;
          bestSpeed = speed;
      }
    }
  }

  /* 
    Check to see if the catapult can reach Ohio Stadium. 
    Ohio Stadium is pretty big, so as long as the closest 
    difference is within 20 meters the snowball will make it!
  */
  double maxDifference = 20.0;  // maximum difference the snowball can land 
                                // and still hit Ohio Stadium

  if (closestDifference <= maxDifference) {
    // Display the best angle and speed choice for the catapult
    cout << "To reach Ohio Stadium, launch the snowball at " << bestAngle; 
    cout << " degrees and " << bestSpeed << " m/s. The snowball will land ";
    cout << closestDifference << " meters away from Ohio Stadium!" << endl;
    cout << endl;
  }
  else {
    cout << "Unfortunately, the wind conditions are such that we can't reach ";
    cout << "Ohio Stadium right now. The closest we can get is " ;
    cout << closestDifference << " meters away from Ohio Stadium." << endl; 
    cout << endl;
  }

  return 0; 
} 
