#include <iostream>
using namespace std;

// function to estimate wait time at the CCTC
int waitTime (int numBuses, int numPeople) {

    // declare a variable to store the value of the estimated wait time
    int estWaitTime = 0;

    // if there are enough buses for people, then the wait is short
    if (numPeople / numBuses < 50) {
        estWaitTime = 5;
    }
    // otherwise, if everyone can fit on this bus or the next bus, then the wait will be a little longer
    else if (numPeople / numBuses < 100) {
        estWaitTime = 15; 
    }
    // otherwise, the wait will be long
    else {
        estWaitTime = -1;
    }

return estWaitTime;
}

// function to print a message with the wait time for the bus
void printMessage(int estWaitTime) {
    // special case: the wait time is long
    if (estWaitTime == -1) {
        cout << "Bummer! There's a LOT of people waiting for buses right now." << endl; 
        cout << "You're probably going to have to wait at least 30 minutes." << endl;
    }
    // otherwise, print the estimated wait time
    else {
        cout << "Your estimated wait time at the bus stop is: ";
        cout << estWaitTime << endl;
    }
}



int main() {
    
    // declare variables for how many buses are nearby and how many people are waiting for the bus
    int numBusesNearby;
    int numPeopleWaiting; 

    // declare variable to store the estimated wait time
    int timeToWait; 


    // ---------------------------------------------------- //
    //            test cases for the functions              //
    // ---------------------------------------------------- //

    // test case 1: short wait

    cout << "TEST CASE 1: Short Wait" << endl;

    numBusesNearby = 2; 
    numPeopleWaiting = 35;

    // call the function to get the estimated wait time 
    timeToWait = waitTime(numBusesNearby, numPeopleWaiting); 

    // call the function to print the message to the user
    printMessage(timeToWait);



    // test case 2: medium wait

    cout << "TEST CASE 2: Medium Wait" << endl;

    numBusesNearby = 1; 
    numPeopleWaiting = 70;

    // call the function to get the estimated wait time 
    timeToWait = waitTime(numBusesNearby, numPeopleWaiting); 

    // call the function to print the message to the user
    printMessage(timeToWait);
    


    // test case 3: long wait

    cout << "TEST CASE 3: Long Wait" << endl;

    numBusesNearby = 3; 
    numPeopleWaiting = 500;

    // call the function to get the estimated wait time 
    timeToWait = waitTime(numBusesNearby, numPeopleWaiting); 

    // call the function to print the message to the user
    printMessage(timeToWait);


}