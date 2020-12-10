#ifndef STG_FPS_H
#define STG_FPS_H

class Fps final {
private:
	static const int N = 60;
	int startTime;
	int count;
public:
	Fps();
	void Update();
	void Wait();
};

#endif // !STG_FPS_H