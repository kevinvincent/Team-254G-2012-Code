#define TICKSPERREVOLUTION 360
#define CIRCUMFERENCE 12.5663706144
#define TICKSTOCMRATIO TICKSPERREVOLUTION/CIRCUMFERENCE
#define P 1

//Autonomous Constants
#define FORWARDTIME 2000
#define TURNDISTANCE 25
#define INTOPOSITIONTIME 500

#include "pid.c"

void drive(int left, int right)
{
	motor[leftBackDrive] =	  left;
	motor[leftFrontDrive] =	  left;
	motor[rightBackDrive] =	 -right;
	motor[rightFrontDrive] = -right;
}
void drive(int speed)
{
	motor[leftBackDrive]	=  speed;
	motor[leftFrontDrive]	=  speed;
	motor[rightBackDrive]	= -speed;
	motor[rightFrontDrive]	= -speed;
}

void driveStraight()
{
	while(true)
	{
		drive(100);
		int error = nMotorEncoder[rightFrontDrive] - nMotorEncoder[leftFrontDrive];
		int differential = P*error;
		if(differential < -2)
		{
			drive(100 + differential,100 - differential);
		}
		else if(differential > 2)
		{
			drive(100 - differential,100 + differential);
		}
		else
		{
			drive(100);
		}
	}
}

void driveForward(float distance)
{
	float distanceCm = distance * 30.48;
	float ticksTraveled = nMotorEncoder[leftFrontDrive]+nMotorEncoder[rightFrontDrive]/2;
	float distanceTraveled = (ticksTraveled/TICKSPERREVOLUTION)*CIRCUMFERENCE;

	while(distanceTraveled <= distanceCm)
	{
		drive(pid(distanceCm, distanceTraveled));
		ticksTraveled = nMotorEncoder[leftFrontDrive]+nMotorEncoder[rightFrontDrive]/2;
		distanceTraveled = (ticksTraveled/TICKSPERREVOLUTION)*CIRCUMFERENCE;
	}

	resetPID();

}

void turnLeft(int distanceInCmToTravel, int speed)
{
	nMotorEncoder[leftFrontDrive] = 0;
	nMotorEncoder[rightFrontDrive] = 0;

	float turnTicks = TICKSTOCMRATIO*distanceInCmToTravel;
	float ticksTraveled = nMotorEncoder[rightFrontDrive];

	while(ticksTraveled<turnTicks)
	{
		drive(-speed,speed);
		ticksTraveled = nMotorEncoder[rightFrontDrive];
	}

	drive(0);
}

void turnRight(int distanceInCmToTravel, int speed) //-1 = right / 1 = left
{
	nMotorEncoder[leftFrontDrive] = 0;
	nMotorEncoder[rightFrontDrive] = 0;

	float turnTicks = TICKSTOCMRATIO*distanceInCmToTravel;
	float ticksTraveled = nMotorEncoder[leftFrontDrive];

	while(ticksTraveled<turnTicks)
	{
		drive(speed,-speed);
		ticksTraveled = nMotorEncoder[leftFrontDrive];
	}

	drive(0);
}

void blueRight()
{
	drive(127);
	wait1Msec(FORWARDTIME);
	drive(0,0);
}
void redLeft()
{
	drive(127);
	wait1Msec(FORWARDTIME);
	drive(0,0);
}
void redRight()
{
	drive(127);
	wait1Msec(FORWARDTIME);
	drive(0,0);
}
void blueLeft()
{
	drive(127);
	wait1Msec(FORWARDTIME);
	drive(0,0);
}
