/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 *
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me !
 *
 *
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.**
 *
 * Now, write your code! You got this! 💪🔥
 *
 *
                OK SIR I WILL DO MY BEST TO SOLVE THIS PROBLEM
 */

#include <stdio.h>

#define MAX_ROOMS 5 // max number of rooms

// Global variables
int lightStatus[MAX_ROOMS] = {0};                  // 0 = off, 1 = on
int temperature[MAX_ROOMS] = {27, 26, 34, 45, 76}; // temperature in each room
int motionSensor[MAX_ROOMS] = {0};                 // 0 = no motion, 1 = motion detected
int securitySystemStatus = 0;                      // 0 = off, 1 = on

// Function prototypes declaration for the main program
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main()
{ // Main program
    int choice;

    initializeSystem();// function call

    do// do while loop
    {
        displayMenu();// function call
        // asking the user to enter the choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            controlLights();
            break;
        case 2:
            readTemperature();
            break;
        case 3:
            detectMotion();
            break;
        case 4:
            securitySystem();
            break;
        case 5:
            analyzeHouseStatus();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem()
{ // Initialize the system
    printf("Initializing Smart Home System...\n");
    printf("System Initialized.\n");
}

void displayMenu()
{ // Display the menu
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights()
{ // Toggle lights in a room
// function to control the lights

    int roomNumber;
    printf("Enter room number (1-5): ");// asking the user to enter the room number
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)// checking the room number
    {
        printf("Invalid room number. Please try again.\n");// printing the error message
        return;
    }

    roomNumber--;// decrementing the room number
    lightStatus[roomNumber] = !lightStatus[roomNumber];// toggling the light status
    printf("Light in room %d is now %s.\n", roomNumber + 1, lightStatus[roomNumber] ? "on" : "off");// printing the light status
}

void readTemperature()
{// function to read the temperature
    int roomNumber;
    printf("Enter room number (1-5): ");// asking the user to enter the room number
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)// checking the room number
    {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    roomNumber--;// decrementing the room number
    printf("Temperature in room %d is %d degrees.\n", roomNumber + 1, temperature[roomNumber]);// printing the temperature
}

void detectMotion()
{// function to detect the motion
    int roomNumber;
    printf("Enter room number (1-5): ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS)// checking the room number
    {
        printf("Invalid room number. Please try again.\n");// printing the error message
        return;
    }

    roomNumber--;// decrementing the room number
    motionSensor[roomNumber] = !motionSensor[roomNumber];// toggling the motion sensor
    printf("Motion in room %d is %s.\n", roomNumber + 1, motionSensor[roomNumber] ? "detected" : "not detected");// printing the motion sensor status
}

void securitySystem()
{// function to control the security system
    securitySystemStatus = !securitySystemStatus;// toggling the security system
    printf("Security system is now %s.\n", securitySystemStatus ? "on" : "off");// printing the security system status
}

void analyzeHouseStatus()
{// function to analyze the house status
    int houseStatus = 0; // 0 = safe, 1 = unsafe

    for (int i = 0; i < MAX_ROOMS; i++)// loop to check the motion sensor status
    {
        if (motionSensor[i] == 1)// checking the motion sensor status
        {
            houseStatus = 1;// setting the house status to unsafe
            break;
        }
    }

    printf("House is %s.\n", houseStatus ? "unsafe" : "safe");// printing the house status
}
