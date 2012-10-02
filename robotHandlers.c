task driveHandler()
{
	while(true)
	{
		motor[leftBackDrive] = vexRT[Ch3];
		motor[leftFrontDrive] = vexRT[Ch3];
		motor[rightBackDrive] = vexRT[Ch2];
		motor[rightFrontDrive] = vexRT[Ch2];
	}
}

task liftHandler()
{
	while(true)
	{
		if(vexRT[Btn5U])
		{
			while(!SensorValue[liftUpBtn] && !vexRT[Btn5D])
			{
				motor[leftLift] = 69;
				motor[rightLift] = 69;
			}
		}
		if(vexRT[Btn5D])
		{
			while(!SensorValue[liftDownBtn] && !vexRT[Btn5U])
			{
				motor[leftLift] = -69;
				motor[rightLift] = -69;
			}
		}
	}
    
}

task intakeHandler()
{
	while(true)
	{
		if(vexRT[Btn6U])
		{
			motor[intakeLeft] = 69;
			motor[intakeRight] = 69;
			wait1Msec(1000);
			motor[intakeLeft] = 0;
			motor[intakeRight] = 0;
			
			while(!SensorValue[intakeDownBtn])
			{
				motor[intakeLeft] = -69;
				motor[intakeRight] = -69;
			}
		}
	}
}