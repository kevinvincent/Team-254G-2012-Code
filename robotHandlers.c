#define Fwd
#define Rev
#define SnsrLiftDown	(SensorValue[liftDown])
#define SnsrLiftUp		(SensorValue[liftUp])
#define JoyLeft			(vexRT[Ch3])
#define JoyRight		(-vexRT[Ch2])
#define BtnIntakeIn		(vexRT[Btn6D])
#define BtnIntakeOut	(vexRT[Btn6U])
#define BtnTrimUp		(vexRT[Btn8U])
#define BtnTrimDown		(vexRT[Btn8D])
#define BtnTrim10		(vexRT[Btn8R])
#define BtnTrim_15		(vexRT[Btn8L])
#define BtnIHaveNoIdea	(vexRT[Btn7D]) //LOL, change this name
#define BtnLiftUp		(vexRT[Btn5U])
#define BtnLiftDown		(vexRT[Btn5D])


task driveHandler()
{
	while(true)
	{
		motor[leftBackDrive] =		JoyLeft;
		motor[leftFrontDrive] =		JoyLeft;
		motor[rightBackDrive] =		JoyRight;
		motor[rightFrontDrive] =	JoyRight;
	}
}

//-7500
task liftAutos()
{
	while(true)
	{
		if(BtnIHaveNoIdea)
		{
			while(!SnsrLiftDown && !BtnLiftDown && !BtnLiftUp)
			{
				motor[leftLift] =			Rev;
				motor[rightLift] =			Rev;
				motor[leftOtherIntake] =	Rev;
				motor[rightOtherIntake] =	Rev;
			}
		}
	}
}


int trim=15;

task intakeAutos()
{
	while(true)
	{
		if(BtnTrimUp)
		{
			trim+=1;
			wait1Msec(250);
		}
		if(BtnTrimDown)
		{
			trim-=1;
			wait1Msec(250);
		}
		if(BtnTrim10)
		{
			trim = 10;
		}
		if(BtnTrim_15)
		{
			trim = -15;
		}
	}
}

task intakeHandler()
{
	while(true)
	{

		if(BtnIntakeOut)
		{
				motor[leftIntake] =			Fwd;
				motor[rightIntake] =		Fwd;
				//motor[leftOutsideIntake] =	Fwd;
				//motor[rightOutsideIntake] =	Fwd;
		}
		else if(BtnIntakeIn)
		{
				motor[leftIntake] =			Rev;
				motor[rightIntake] =		Rev;
				//motor[leftOutsideIntake] =	Rev;
				//motor[rightOutsideIntake] =	Rev;
		}
		else
		{
			motor[leftIntake] =			trim;
			motor[rightIntake] =		trim;
			//motor[leftOutsideIntake] =	trim;
			//motor[rightOutsideIntake] =	trim;
		}
	}
}

task liftHandler()
{
	while(true)
	{
		if(BtnLiftUp && !SnsrLiftUp)
		{
			motor[leftLift] =			Fwd;
			motor[rightLift] =			Fwd;
			motor[leftOtherIntake] =	Fwd;
			motor[rightOtherIntake] =	Fwd;
		}
		else if(BtnLiftDown && !SnsrLiftDown)
		{
			motor[leftLift] =			Rev;
			motor[rightLift] =			Rev;
			motor[leftOtherIntake] =	Rev;
			motor[rightOtherIntake] =	Rev;
		}

		else
		{
			motor[leftLift] = 0;
			motor[rightLift] = 0;
			motor[leftOtherIntake] = 0;
			motor[rightOtherIntake] = 0;
		}
	}
}
