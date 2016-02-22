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
		Zone(int pwidth, int pheight, int px, int py);
		bool isEmpty();

		void setWidth(const int width);
		void setHeight(const int height);
		void setId(const int pid);

		int getWidth() const;
		int getHeight() const;
		int getX() const;
		int getY() const;
		int getId() const;
};