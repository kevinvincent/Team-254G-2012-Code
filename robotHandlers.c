task driveHandler()
{
	while(true)
	{
		motor[leftBackDrive] = vexRT[Ch3];
		motor[leftFrontDrive] = vexRT[Ch3];
		motor[rightBackDrive] = vexRT[Ch2]*-1;
		motor[rightFrontDrive] = vexRT[Ch2]*-1;
	}
}

//-7500
task liftAutos()
{
	while(true)
	{
		if(vexRT[Btn7D])
		{
			while(!SensorValue[liftDown] && !vexRT[Btn5U] && !vexRT[Btn5D])
			{
				motor[leftLift] = -127;
				motor[rightLift] = -127;
				motor[leftOtherIntake] = -127;
				motor[rightOtherIntake] = -127;
			}
		}
	}
}


int trim=15;

task intakeAutos()
{
	while(true)
	{
		if(vexRT[Btn8U])
		{
				trim+=1;
				wait1Msec(250);
		}
		if(vexRT[Btn8D])
		{
				trim-=1;
				wait1Msec(250);
		}
		if(vexRT[Btn8R])
		{
				trim = 10;
		}
		if(vexRT[Btn8L])
		{
				trim = -15;
		}
	}
}

task intakeHandler()
{
	while(true)
	{

		if(vexRT[Btn6U])
		{
				motor[leftIntake] = 127;
				motor[rightIntake] = 127;
				//motor[leftOutsideIntake] = 127;
				//motor[rightOutsideIntake] = 127;
		}
		else if(vexRT[Btn6D])
		{
				motor[leftIntake] = -127;
				motor[rightIntake] = -127;
				//motor[leftOutsideIntake] = -127;
				//motor[rightOutsideIntake] = -127;
		}
		else
		{
			motor[leftIntake] = trim;
			motor[rightIntake] = trim;
			//motor[leftOutsideIntake] = trim;
			//motor[rightOutsideIntake] = trim;
		}
}
}

task liftHandler()
{
	while(true)
	{
		if(vexRT[Btn5U] && !SensorValue[liftUp])
		{
			motor[leftLift] = 127;
			motor[rightLift] = 127;
			motor[leftOtherIntake] = 127;
			motor[rightOtherIntake] = 127;
		}
		else if(vexRT[Btn5D] && !SensorValue[liftDown])
		{
			motor[leftLift] = -127;
			motor[rightLift] = -127;
			motor[leftOtherIntake] = -127;
			motor[rightOtherIntake] = -127;
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