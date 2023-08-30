#pragma once
class Sample
{
public:
	int GetSomeData() const
	{
		//_someData += 10;
		return _someData;
	}
	void SetSomeData(int newSomeData)
	{
		_someData = newSomeData;
	}
private:
	int _someData = 5;
};

