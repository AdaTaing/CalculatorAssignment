#include <stdio.h> // C Standard Library for input/output functions
#include <math.h> //Math Library

//prototypes
char optionDisplay(int s);//displaying menu options
double numChecker(char oper); //checks number input
char charChecker(int option); //checks char input
double opB(double num1, double num2, char oper); //option B
double opU(char oper, double num); //option U
double opA(double var_option[], char option);//option A
double variableAssign(double var_option[], char varName); //variable grab
void memory(double calculations[], int memCapacity); //option M
int reset(); //option R

int main(void){//Start of main
	//define variables
	int on = 0;
	double var_option[5] = {0};//for advanced option and variable define option
	double calculations[100] = {0}; //stores results of calculations made
	int memCapacity = 0;//checks the memory capacity

	//Show Details about this program
	puts("Welcome to my Command-Line Calculator (CLC)");
	puts("Developer: Ada Taing");
	puts("Version: 3");
	puts("Development Date: 2021/12/01");
	puts("---------------------------------------------");

	//make on = 1
	on = 1;
	
	do{ //start of while loop, condition is while on != 0

		//Define Variables
		char operation; //stores operation
		char option; //options of advanced option
		char varName; //stores a variable name
		int r;//decides whther to rest memory or not
		
		double num1;
		double num2;
		double result;
		long int mod_result; //for mod operartions only
		
		int a_on; //for when the user chooses advanced option

		//display first menu options
		switch (optionDisplay(1)){
		//If input B
			case 'B':
				//first number input
				puts("Please enter the first number:");
				num1 = numChecker(' ');	
	
				//operation choice
				puts("Please enter the operation ( + , - , * , / , % , ^ (for power)):"); //askes user to enter an operation
				operation = charChecker(1);//pass condition to check binary operation

				//second number input
				if(operation == '/'||operation == '%'){
					puts("Please enter the second number (non-zero):");
				}
				else{
					puts("Please enter the second number:");
				}
				num2 = numChecker(operation);
	
				//doing the operation chosen by the user
				result = opB(num1, num2, operation);

				//store result into memory
				if(memCapacity>99){
				//make room for another result
					for(int i = 1; i<99; i++){
						calculations[i] = calculations[i-1];
					}
					calculations[0] = result;
				}
				else{
					calculations[memCapacity] = result;
					memCapacity = memCapacity+1;
				}
					
				break; //end of case B
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//If input U
			case 'U':
				//user enters operation of choice
				puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
				operation = charChecker(2);

				//user inputs number
				if(operation == 'S'||operation == 'L'){
					puts("Please enter a positive number:");
				}
				else{
					puts("Please enter a number:");
				}
				num1 = numChecker(operation);

				//doing the operation and getting a number
				result = opU(operation, num1);

				//store result into memory
				if(memCapacity>99){
				//make room for another result
					for(int i = 1; i<99; i++){
						calculations[i] = calculations[i-1];
					}
					calculations[0] = result;
				}
				else{
					calculations[memCapacity] = result;
					memCapacity = memCapacity+1;
				}
					
				break; //end of case U
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//If input V
			case 'V':
				//enter variable name
				puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
				varName = charChecker(3);

				//enter value to assign to variable
				puts("Please enter a number to assign to the variable:");
				num1 = numChecker(' ');	
					
				//assigning the value to the variable chosen
				switch(varName){
					case 'a':
						var_option[0] = num1;
						break;
					case 'b':
						var_option[1] = num1;
						break;
					case 'c':
						var_option[2] = num1;
						break;
					case 'd':
						var_option[3] = num1;
						break;
					case 'e':
						var_option[4] = num1;
						break;
				}
				printf("Variable %c is set to:		%.2lf\n", varName, num1); //tells user the chosen variable and the assigned number

				break; //end of case V
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//If input A
			case 'A':
					a_on = 1;
					do{
						option = optionDisplay(2);
						switch(option){
							//binary
							case 'B':
								opA(var_option, option);
								break;

							//unary
							case 'U':
								opA(var_option, option);
								break;

							//exit
							case 'X':
								a_on = 0;
								break;
						}

						//store result into memory
						if(memCapacity>99){
							//make room for another result
							for(int i = 1; i<99; i++){
								calculations[i] = calculations[i-1];
							}
							calculations[0] = result;
						}
						else{
							calculations[memCapacity] = result;
							memCapacity = memCapacity+1;
						}
						
					}while(a_on!=0);
					
					break; //end of case A
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//If input M
			case 'M':
				memory(calculations, memCapacity);
				break; //end of case M
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//If input R
			case 'R':
				r = reset();
				if(r==1){
					for(int i = 0; i<99; i++){
						calculations[i] = 0;
					}
					memCapacity = 0;
					puts("Memory reset successful");
				}
				else{
					puts("Memory was not reset");
				}
				break; //end of case R
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//If input X
			case 'X':
				on = 0;
				break; //end of case X
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		}//end of switch
	
	} while(on!=0); //End While loop
	
	//Display a goodbye message
	puts("");
	puts("Thank you for using my calculator! Have a great day! :)");

}//End of main

//options display
char optionDisplay(int s){
	int check = 1;
	char menuChoice;
	if(s == 1){ //main menu
		while(check!=0){
			//Display message that askes the user to choose an option to proceed with
			puts("");
			puts("Please select one of the following options: ");
			//Display the options
			puts("B) - Binary Mathematical Operations such as addition and subtraction.");
			puts("U) - Unary Mathematical Operations, such as square root, and log.");
			puts("V) – Define variables and assign them values.");
			puts("A) - Advances Mathematical Operations, using variables, arrays.");
			puts("M) - To see the memory");
			puts("R) - To reset the memory");
			puts("X) - Exit");

			//get user input
			if(scanf(" %c", &menuChoice)){
				switch(menuChoice){
					//makes choice to 'B'
					case 'b':
					case 'B':
						menuChoice = 'B';
						check = 0;
						break;
					//makes choice to 'U'
					case 'u':
					case 'U':
						menuChoice = 'U';
						check = 0;
						break;
					//makes choice to 'V'
					case 'v':
					case 'V':
						menuChoice = 'V';
						check = 0;
						break;
					//makes choice to 'A'
					case 'a':
					case 'A':
						menuChoice = 'A';
						check = 0;
						break;
					//makes choice to 'M'
					case 'm':
					case 'M':
						menuChoice = 'M';
						check = 0;
						break;
					//makes choice to 'R'
					case 'r':
					case 'R':
						menuChoice = 'R';
						check = 0;
						break;
					//makes choice to 'X'
					case 'x':
					case 'X':
						menuChoice = 'X';
						check = 0;
						break;
					default:
						puts("Not an Option on this list.");
				}
			}
			else{ //If input not a char
				puts("Not a Valid Option");
			}
		}
	}
	else if(s == 2){ //advanced option menu
		while(check!=0){
			puts("Select one of the following items:");
			puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
			puts("U) - Unary Mathematical Operations, such as square root, and log.");
			puts("X) - Exit and back to the main menu");

			//get user input
			if(scanf(" %c", &menuChoice)){
				switch(menuChoice){
					//makes choice to 'B'
					case 'b':
					case 'B':
						menuChoice = 'B';
						check = 0;
						break;
					//makes choice to 'U'
					case 'u':
					case 'U':
						menuChoice = 'U';
						check = 0;
						break;
					//makes choice to 'X'
					case 'x':
					case 'X':
						menuChoice = 'X';
						check = 0;
						break;
					default:
						puts("Not an Option on this list.");
				}
			}
			else{ //If input not a char
				puts("Not a Valid Option");
			}
		}
		
	}
	return menuChoice;
}

//number checker
double numChecker(char oper){//oper to check if there are number restrictions
	double num;
	if(oper == '/'|| oper == '%'){
		while(1){
			//get user input
			fflush(stdin); //fixes float scanning problems
			if(scanf("%lf", &num)){
				if(num!=0){
					break;
				}
				else{
					puts("Input is invalid");
				}
			}
			else{
				puts("Input is invalid");
			}//end of if
			puts("Please enter the number again (That's not zero): ");
			while ( getchar() != '\n' ); //breaks the inevitable infinite loop involving scanf
		}//end of while
	}
	else if(oper == 'S'|| oper == 'L'){
		while(1){
			//get user input for positive number
			fflush(stdin); //fixes float scanning problems
			if(scanf("%lf", &num)){
				if(num>=0){//if it is a positvive number
					break;
				}
				else{
					puts("Input is invalid");
				}
			}
			else{
				puts("Input is invalid");
			}//end of if
			puts("Please enter a positive number:");
			while ( getchar() != '\n' ); //breaks the inevitable infinite loop involving scanf
		}
	}
	else{
		//gets user input
		while(1){
			fflush(stdin);
				if(scanf("%lf", &num)){
				break;
			}	
			else{
				puts("Input was not a number");
			}
			printf("Please enter the number again: "); //askes user to enter first number again
			while ( getchar() != '\n' ); //breaks the inevitable infinite loop involving scanf
		}//end of while
	}
	puts("");
	return num;
}

//char checker
char charChecker(int option){
	char input;//stores input
	int check=1;//check condition

	while(check!=0){//check loop
		fflush(stdin);
		scanf(" %c", &input);
		//check input
		switch(option){
			case 1://binary operation
				if(input == '+' || input == '-' || input == '*' || input == '/'|| input == '%' || input == '^'){ //check if operation input is one of the options
					check = 0;
				}
				else{
					puts("Input was not an option.");
					//askes user to enter operation number again
					puts("Please enter the operation again ( + , - , * , / , % , ^ (for power)):"); 
				}//end of if
				break;

			case 2://unary operation
				switch(input){
					case 's':
					case 'S':
						input = 'S';
						check = 0;
						break;
					case 'l':
					case 'L':
						input = 'L';
						check = 0;
						break;
					case 'e':
					case 'E':
						input = 'E';
						check = 0;
						break;
					case 'c':
					case 'C':
						input = 'C';
						check = 0;
						break;
					case 'f':
					case 'F':
						input = 'F';
						check = 0;
						break;
					//if anything else
					default:
						puts("Not an option");
						puts("Please enter the operation again ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
						break;
				}
				break;

			case 3://variable selection
				if(input == 'a' || input == 'b' || input == 'c' || input == 'd'|| input == 'e'){ //if input is one of the options
					check = 0;
				}
				else if(input == 'A' || input == 'B' || input == 'C' || input == 'D'|| input == 'E'){ //if input is one of the options but is capitalized
					puts("Variables are case sensitive, therefore capital letters are not on the list");
					puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
				}
				else{
					puts("Input was not an option.");
					puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
				}//end of if
				break;

			case 4://selection between var and num
				switch(input){
					//Variable
					case 'v':
					case 'V':
						input = 'V';
						check = 0;
						break;
											
					//number
					case 'n':
					case 'N':
						input = 'N';
						check = 0;
						break;
											
					//any other option
					default:
						puts("Invalid Option");
							puts("Please input option again ( V (Variable) N (Number))");
							break;
				}
				break;
				
			case 5: //choosing a variable
				if(input == 'a' || input == 'b' || input == 'c' || input == 'd'|| input == 'e'){ //if input is one of the options
					check = 0;
				}
				else if(input == 'A' || input == 'B' || input == 'C' || input == 'D'|| input == 'E'){ //if input is one of the options but is capitalized
					puts("Variables are case sensitive, therefore capital letters are not on the list");
					puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
				}
				else{
					puts("Input was not an option.");
					puts("Please enter the name of the variable ( A single character between 'a' to 'e' ):");
				}//end of if
				break;
		}
	}//end of check loop
	puts("");
	return input; //returns input
}

//option B
double opB (double num1, double num2, char oper){
	double result; //result of operation
	long int mod_result; //result of mod operation

		//doing the operation chosen by the user
		switch(oper){
			case '+': //add
				result = num1 + num2;
				printf("The result is:	%.2lf\n", result);
				break;
						
			case '-': //subtract
				result = num1 - num2;
				printf("The result is:	%.2lf\n", result);
				break;
						
			case '*': //multiply
				result = num1 * num2;
				printf("The result is:	%.2lf\n", result);
				break;
					
			case '/': //divide
				result = (double)num1 / (double)num2;
				printf("The result is:	%.2lf\n", result);
				break;
					
			case '%': //remainder
				mod_result = (long int)num1 % (long int)num2;
				result = (double)mod_result;
				printf("The result is:	%.0lf\n", result);
				break;
						
			case '^': //power
				result = pow(num1, num2);
				printf("The result is:	%.2lf\n", result);
				break;
						
		}//end of switch
	return result;
}

//option U
double opU(char oper, double num){
	double result;
	switch(oper){
		//Sq root
		case 's':
		case 'S':
			result = sqrt(num);
			printf("The result is:	%.2lf\n", result);
								
			break;//end of sq root
		//Log (log10)
		case 'l':
		case 'L':
			result = log10(num);
			printf("The result is:	%.2lf\n", result);
								
			break;//end of log (log10)
		//exponential
		case 'e':
		case 'E':
			result = exp(num);
			printf("The result is:	%.2lf\n", result);
								
			break;//end of exponential
		//ceil
		case 'c':
		case 'C':
			result = ceil(num);
			printf("The result is:	%.2lf\n", result);
								
			break;//end of ceil
		//floor
		case 'f':
		case 'F':
			result = floor(num);
			printf("The result is:	%.2lf\n", result);
								
			break;//end of floor
		}
		puts("");
		return result;
}

//option A
double opA(double var_option[], char option){
	double num1;
	double num2;
	char operation;
	double result;
	char type;
	char varName;
	switch(option){
		//binary
		case 'B':
			//first input
			puts("For the first value, do you want to use a variable or a number?");
			puts("V) - variable");
			puts("N) - number");
			type = charChecker(4);

			//var option
			if(type == 'V'){
				puts("Please enter the name of the variable for the first number ( A single character between 'a' to 'e' ):");
				varName = charChecker(5);
				num1 = variableAssign(var_option, varName);
			}
			//num option
			else if(type == 'N'){
				puts("Please enter the first number:");
				num1 = numChecker(' ');	
			}


			//operation input
			puts("Please enter the operation ( + , - , * , / , % , ^ (for power)):"); //askes user to enter an operation
			operation = charChecker(1);//pass condition to check binary operation


			//Second input
			int check2 = 1;//for checking if variable is zero
			while(check2!=0){
				puts("For the second value, do you want to use a variable or a number?");
				puts("V) - variable");
				puts("N) - number");
				type = charChecker(4);

				//var option
				if(type == 'V'){
					puts("Please enter the name of the variable for the second number ( A single character between 'a' to 'e' ):");
					varName = charChecker(5);
					num2 = variableAssign(var_option, varName);
					if(operation == '/'||operation == '%'){
						if(num2!=0){
							check2 = 0;
						}
						else{
							puts("Variable is invalid because it is zero");
						}
					}
					else{
						check2 = 0;
					}
				}
				//num option
				else if(type == 'N'){
					if(operation == '/'||operation == '%'){
						puts("Please enter the second number (non-zero):");
					}
					else{
						puts("Please enter the second number:");
					}
					num2 = numChecker(operation);	
					check2 = 0;
				}

			}

			//doing the operation chosen by the user
			result = opB(num1, num2, operation);

			break;

		//unary
		case 'U':
			//user enters operation of choice
			puts("Please enter the operation ( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) ):");
			operation = charChecker(2);

			//user number/variable input
			int check3 = 1;//for checking if variable is negative
			while(check3!=0){
				puts("For the value, do you want to use a variable or a number?");
				puts("V) - variable");
				puts("N) - number");
				type = charChecker(4);

				//var option
				if(type == 'V'){
					puts("Please enter the name of the variable for the second number ( A single character between 'a' to 'e' ):");
					varName = charChecker(5);
					num1 = variableAssign(var_option, varName);
					if(operation == 'S'||operation == 'L'){
						if(num1>=0){
							check3 = 0;
						}
						else{
							puts("Variable is invalid because it is negative");
						}
					}
					else{
						check3 = 0;
					}
				}
				//num option
				else if(type == 'N'){
					if(operation == 'S'||operation == 'L'){
						puts("Please enter a positive number:");
					}
					else{
						puts("Please enter a number:");
					}
					num1 = numChecker(operation);	
					check3 = 0;
				}

			}

			result = opU(operation, num1);
			break;
	}

	return result;
}

//entering variable name
double variableAssign(double var_option[], char varName){
	double num;
	switch(varName){
		case 'a':
			num = var_option[0];
			break;
		case 'b':
			num = var_option[1];
			break;
		case 'c':
			num = var_option[2];
			break;
		case 'd':
			num = var_option[3];
			break;
		case 'e':
			num = var_option[4];
			break;
	}
	return num;
}

//option M
void memory(double calculations[], int memCapacity){
	double input;
	int input2;
	if(memCapacity == 0){
		puts("There is nothing in the memory");
	}
	else{
		do{
			printf("Amount of calculation results stored: %d\n", memCapacity);
			puts("Choose an option by picking a number:");
			puts("1 - see memory");
			puts("2 - exit");
			input = numChecker(' ');
			if(input==1){
				while(1){
					puts("Which item you would like to view?");
					printf("-Choose a number between 1 and %d to view a particular item\n", (memCapacity));
					puts("-Choose 0 to view the whole list");

					scanf("%d", &input2);
					if(input2>=1 && input2<=(memCapacity)){
						printf("[%d] is %.2lf\n", input2, calculations[input2-1]);
						break;
					}
					else if(input2 == 0){
						for(int i = 0; i<(memCapacity); i++){
							printf("[%.d] is %.2lf\n", i+1, calculations[i]);
						}
						break;
					}
					else{
						puts("Invalid input");
					}

				}

			}
			else if(input==2){
				break;
			}
			else{
				puts("Not one of the options");
			}
			
		}while(1);
	}
}

//option R
int reset(){
	int input;
	while(1){
		puts("Are you sure you want to reset the memory?");
		puts("1 - yes");
		puts("0 - no");
		scanf("%d", &input);
		if(input == 1 || input == 0){
			break;
		}
		else{
			puts("Not an option");
		}
	} 
	return input;
}
