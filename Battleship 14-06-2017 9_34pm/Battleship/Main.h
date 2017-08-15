#pragma once
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 32

class BShip // TF: Class
{
	public: // TF: Access Specifier
		BShip(); // Constructor
		~BShip(); // Destructor
		BShip(const BShip &obj); // Copy constructor
		int GetLength() const; // Get the ships length
		void SetLength(int _iLength); // Set the ships length
		char cOrientation; // 0 = Horizontal, 1 = Vertical
		short sXCoord; // Ship x coordinate
		short sYCoord; // Ship y coordinate
		bool bSunk = false; // The status of the ship, if its sunk or not

	private:
		int m_iLength; // Length of the ship		
};

BShip::BShip() // TF: Default Parameter, TF: Constructor
{
	m_iLength = 0;
}

BShip::BShip(const BShip &obj) // TF: Copy Constructor
{	
	int m_ciLength; 
	m_ciLength = obj.m_iLength;
}

BShip::~BShip() // TF: Destructor
{

}

int BShip::GetLength() const // Get length function
{
	return (m_iLength);
}

void BShip::SetLength(int _iLength) // Set length function
{
	m_iLength = _iLength;
}

