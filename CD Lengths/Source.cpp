#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SECONDS_PER_HOUR = 3600;
const int SECONDS_PER_MINUTE = 60;

int main()
{
	int ID;
	int numSongs;
	int songMin;
	int songSecond;
	int TotalSecond = 0;
	int convert_to_Seconds = 0;
	ifstream data;

	int totalMin;
	int totalSec;

	data.open("cd.txt");

	cout << setw(8) << left << " CD ID  " << setw(3) << " "<< setw(7) << left << "CD Time" << endl;
	cout << setw(8) << "--------"<< setw(3) << " " <<setw(7) << "-------" << endl;

	while (data.peek() != EOF) 
	{
		data >> ID;
		data >> numSongs;

		for (int i = 1; i <= numSongs; i++)
		{
			data >> songMin;
			data >> songSecond;

			convert_to_Seconds = songMin * 60;


			TotalSecond += convert_to_Seconds;
			TotalSecond += songSecond;

		}

		cout << setw(8) << ID << setw(3) << " ";

		totalMin = TotalSecond / SECONDS_PER_MINUTE;
		totalSec = TotalSecond % SECONDS_PER_MINUTE;

		cout << right << setw(3) << totalMin << ":" << setw(2) << setfill('0') << totalSec << setfill(' ') << endl;
		
		songMin = 0;
		songSecond = 0;
		TotalSecond = 0;
		convert_to_Seconds = 0;
	}

	data.close();

	return 0;
}