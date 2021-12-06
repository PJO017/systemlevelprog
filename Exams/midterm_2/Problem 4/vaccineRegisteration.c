#include <stdio.h>
#include <time.h>
#include <string.h>

// Date structure 
struct date {
  int day;
  int month;
  int year;
};

// Vaccine Registration struct
struct vaccineReg
{
  char firstName[10];
  char lastName[10];
  struct date DOB;
  int doseNumber;
  struct date prevDose;
  char vaccineType[30];
  char zipcode[6];
  char code[9];
};

// Array to Store users
struct vaccineReg users[20];
int lastRegPtr = 0;

// Get user age
int getAge(struct date dob) {
  int cur_year, cur_month, cur_day, age;

  time_t seconds=time(NULL);
  struct tm* current_time=localtime(&seconds); // Get current date

  cur_year = current_time->tm_year + 1900; 
  cur_month = current_time->tm_mon;
  cur_day = current_time->tm_mday;

  // Calculate age
  age = cur_year - dob.year;      // Current year - birth year

  if (dob.month-1 > cur_month) {   // If birthday month hasn't passed then subtract 1
    age = age - 1;
  } else if (cur_month == dob.month-1 && dob.day-1 > cur_day){   // Else if it is birthday month but 
    age = age - 1;                                               // day hasn't passed subtract 1
  }

  return age;
}

// Generate user code
char *generateCode(struct vaccineReg reg) {
  // Get age
  char age[2];
  sprintf(age, "%d", getAge(reg.DOB));

  char code[8];
  char *code_ptr = code;

  // Create code
  code_ptr[0] = reg.firstName[0];           // First letter of first name
  code_ptr[1] = reg.lastName[0];           // First letter of last name
  code_ptr[2] = age[0];                   // First digit of age
  code_ptr[3] = age[1];                  // Second digit of age
  code_ptr[4] = reg.vaccineType[0];     // First letter of vaccine type
  code_ptr[5] = reg.zipcode[2];        // Third to last digit of zipcode
  code_ptr[6] = reg.zipcode[3];       // Second to last digit of zipcode
  code_ptr[7] = reg.zipcode[4];      // Last digit of zipcode

  return code_ptr;
}

void retrieve() {
  // Get code 
  printf("\n");
  char code[8];
  printf("Enter code: ");
  scanf("%s", code);

  // Iterate users and look for code
  for (int i = 0; i < 20; i++) {
    // If code matches print info
    if (strcmp(code, users[i].code) == 0) {
      printf("\n");
      printf("-- Info --\n");
      printf("First name: %s\n", users[i].firstName);
      printf("Last name: %s\n", users[i].lastName);
      printf("Date of Birth: %d/%d/%d\n", users[i].DOB.month, users[i].DOB.day, users[i].DOB.year);
      printf("Vaccine type: %s\n", users[i].vaccineType);
      printf("Dose number: %d\n", users[i].doseNumber);
      printf("Date of previous : %d/%d/%d\n", users[i].prevDose.month, users[i].prevDose.day, users[i].prevDose.year);
      printf("Zip code: %s\n", users[i].zipcode);
      printf("Code: %s\n", users[i].code);
      return;
    }
  }
  printf("Info not found.\n");
}

void Register() {
  struct vaccineReg newReg;

  printf("\nEnter info:\n");

  // Get first name
  printf("Enter first name: ");
  scanf(" %s", newReg.firstName);

  // Get last name
  printf("Enter last name: ");
  scanf(" %s", newReg.lastName);

  // Get date of birth
  printf("Enter date of birth in this format (mon day year): ");
  scanf("%d%d%d", &newReg.DOB.month, &newReg.DOB.day, &newReg.DOB.year);

  // Get vaccine type
  printf("Enter vaccine type (Pfizer, Moderna, J&J): ");
  scanf(" %s", newReg.vaccineType);

  // Get dose number
  printf("Enter dose number: ");
  scanf(" %d", &newReg.doseNumber);

  // Get date of previous dose
  // If this first dose
  if (newReg.doseNumber == 1) {
    newReg.prevDose.month = 0;
    newReg.prevDose.day = 00;
    newReg.prevDose.year = 0000;
  } else {
    printf("Enter date of previous dose in this format (mon day year): ");
    scanf(" %d%d%d", &newReg.prevDose.month, &newReg.prevDose.day, &newReg.prevDose.year);
  }


  // Get zipcode
  printf("Enter zip code: ");
  scanf(" %s", newReg.zipcode);


  // Generate code
  strcpy(newReg.code, generateCode(newReg));
  printf(">> Generated Registeration Code: %s\n", newReg.code);

  // Save registration
  users[lastRegPtr++] = newReg;
}

// Print menu options
void menu() {
  while (1) { 
    printf("\n-- Vaccine Registration -- \n");
    int choice;
    printf("1) Register\n2) Retrieve\n3) Exit\n>> ");
    scanf(" %d", &choice);

    if (choice == 1) {
      Register();
    } 
    if (choice == 2) {
      retrieve();
    }
    if (choice == 3) {
      break;
    }
    printf("\n");
  }
}

int main() {
  menu();
  return 0;
}

