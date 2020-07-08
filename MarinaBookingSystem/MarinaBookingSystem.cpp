#include <iostream>
#include "Boat.cpp"
#include <vector>
#include "Booking.h"

char UserInput;
bool StopProgram = false;
int BoatSize;
int BoatDraft;

std::vector<Boat> tempHoldingBay;
std::vector<Boat> marinaHoldingBay;

std::vector<Booking> Bookings;

/// Check if the combined boats in the list are greater than the dock capacity 
static bool checkAvailableSpaces(Boat boat)
{
    // Add the requested boatLength to the combined length count.
    int currentCombinedLength = 0 + boat.BoatLength;

    // Check if their are any boats currently docked
    if (marinaHoldingBay.empty == false)
    {
        // Loop through the existing boats in the list
        for (int i = 0; i < marinaHoldingBay.size; i++)
        {
            // Calculate the combined length of all docked boats 
            currentCombinedLength += marinaHoldingBay[i].BoatLength;
        }

        if (currentCombinedLength <= 150)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

static void unDockBoat(Boat boat)
{
    for (int i = 0; i < marinaHoldingBay.size; i++)
    {
        // Check if the booking Id's match
        if (marinaHoldingBay[i].BookingId == boat.BookingId)
        {
            // Remove the boat from the marina holding dock
            marinaHoldingBay.erase(marinaHoldingBay.begin() + i);
        }
    }
}

static void dockBoatInTempHold(Boat boat)
{
    for (int i = 0; i < marinaHoldingBay.size; i++)
    {
        // Check if the booking Id's match
        if (marinaHoldingBay[i].BookingId == boat.BookingId)
        {
            // Add to the holding cell
            tempHoldingBay.push_back(marinaHoldingBay[i]);

            // Remove the boat from the marina holding dock
            marinaHoldingBay.erase(marinaHoldingBay.begin() + i);
        }
    }
}

static void unDockBoatInTempHold()
{
    // Add the boat back into the holding dock
    marinaHoldingBay.insert(marinaHoldingBay.begin, tempHoldingBay[0]);

    // Remove the boat from the temp dock
    tempHoldingBay.erase(tempHoldingBay.begin);
}

static void dockBoat(Boat boat)
{
    // Add the boat to the start of the list
    marinaHoldingBay.insert(marinaHoldingBay.begin, boat);
}

static void addBooking()
{

    std::cout << "Please enter the boat size in (m): ";
    std::cin >> BoatSize;

    if (BoatSize > 15)
    {
        char input;
        std::cout << "\nSorry, our max boat size is 15 metres.\n";
        std::cout << "\n1) Main Menu.\n";
        StopProgram = true;
        std::cin >> input;
        system("CLS");
        return;
    }

    std::cout << "Please enter the boat draft in (m): ";
    std::cin >> BoatDraft;

    if (BoatDraft > 5)
    {
        char input;
        std::cout << "\nSorry, our max boat size is 15 metres.\n";
        std::cout << "\n1) Main Menu.\n";
        StopProgram = true;
        std::cin >> input;
        system("CLS");
        return;
    }
}

static void displayAllRecords()
{




    std::cout << "Current Docked Boats" << std::endl;

    for (int i = 0; i < Bookings.size; i++)
    {



        std::cout << i << ") "
            << Bookings[i].BookingId << "   "
            << Bookings[i].CustomerName << "    "
            << Bookings[i].DockDuration << "   "
            << Bookings[i].DockedBoat->BoatLength << "   "
            << Bookings[i].DockedBoat->BoatDraft << "    "
            << Bookings[i].DockTime << "    "
            << Bookings[i].DepartTime << "    "
            << Bookings[i].TotalBookingFee << "    " << std::endl;

    }


}

int main()
{

    do {
        std::cout << "Welcome to the Marina Booking System! \n\n";
        std::cout << "Please select an option: \n";

        // Prompt user with interaction options
        std::cout << "1) Record a new booking. \n";
        std::cout << "2) Delete a record. \n";
        std::cout << "3) Display all records. \n";
        std::cout << "4) Exit the program. \n";
        std::cin >> UserInput;

        switch (UserInput)
        {
        case '1':
            addBooking();
            break;
        case '2':
            //deleteRecord();
            break;
        case '3':
            displayAllRecords();
            break;
        case '4':
            return 0;
            break;
        }

    } while (StopProgram);

    return 0;
}