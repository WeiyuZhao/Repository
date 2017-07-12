#ifndef TESTDEFINITIONEN_MOTOR
#define TESTDEFINITIONEN_MOTOR

#ifdef TEST








void testMotor_Dreh1(){ //Dreh1 beduetet: Motor dreht sich im Uhrzeigersinn(Hochfahren).
	bool testResult = false;
	
	photocellVal = analogRead(photocellPin);
	if (photocellVal < minLight && ledState == 1)
        {testResult = true;}
	
	APITest::printTestResult(testResult, "Motor Dreh1 ", "ZWeiyu Zhao", "Wird der Motor automatisch im Uhrzeigersinn drehen?", "combine.ino");
}

void testMotor_Dreh2(){ //Dreh2 beduetet: Motor dreht sich gegen dem Uhrzeigersinn(Heruntenfahren).
	bool testResult = false;

	if (photocellVal > minLight && ledState == 0)
        {testResult = true;}
	
	APITest::printTestResult(testResult,"Motor Dreh2", "ZWeiyu Zhao", "Wird der Motor automatisch im Uhrzeigersinn drehen?", "combine.ino");
}

void runTests(){
  APITest::printTestStartHeader(); // Nicht modifizieren
  
  // Hier sollen die eigenen Tests hinzugefuegt werden
 testMotor_Dreh1();
testMotor_Dreh2();

  APITest::printTestEndFooter(); // Nicht modifizieren
}





#endif //TEST

#ifdef TEST  // Nicht modifizieren
	#define RUNTEST runTests();
#else
	#define RUNTEST
#endif


#endif //TESTDEFINITIONEN_Motor

