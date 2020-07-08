#include "SailBoat.h"
#include "Boat.cpp"

class NarrowBoat : Boat
{
public:

	NarrowBoat(int bookingId, int boatLength, int boatDraft, char boatName[35])
	{
		this->BookingId = bookingId;
		this->BoatLength = boatLength;
		this->BoatDraft = boatDraft;

		for (int i = 0; i < 35; i++)
		{
			for (int i = 0; i < 35; i++) {
				if (boatName[i] == NULL)
					boatName[i] = ' ';

				this->BoatName[i] = boatName[i];
			}
		}
	}
};