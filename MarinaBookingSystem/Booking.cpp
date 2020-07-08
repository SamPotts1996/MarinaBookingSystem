#include "Boat.cpp"
#include <cstddef>

class Booking
{
public:

	int BookingId;
	Boat* DockedBoat;
	char CustomerName[35];
	char DockTime[10];
	char DepartTime[10];
	int DockDuration;
	double TotalBookingFee;

	Booking(int bookingId, Boat* dockedBoat, char customerName[35], char dockTime[10], char departTime[10], int dockDuration, double totalBookingFee)
	{
		this->BookingId = bookingId;
		this->DockedBoat = dockedBoat;
		this->DockDuration = dockDuration;
		this->TotalBookingFee = totalBookingFee;

		for (int i = 0; i < 35; i++) {
			if (customerName[i] == NULL)
				customerName[i] = ' ';

			this->CustomerName[i] = customerName[i];

			if (i <= 10)
			{
				this->DockTime[i] = dockTime[i];
				this->DepartTime[i] = dockTime[i];
			}
		}
	}
};

