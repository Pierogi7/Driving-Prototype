
class Time
{
public:
	Time();
	~Time();

	//calculate delta time
	void Calc();

	//returns deltaTime
	float get_delta();

private:
	//var
	float deltaTime;
	float lastFrame;
};


