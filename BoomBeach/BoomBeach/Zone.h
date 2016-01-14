#pragma once
class Zone
{
	private:
		int id;

		int width;
		int height;

		int x;
		int y;

	public:
		Zone();
		bool isEmpty();
};