#include <iostream>
#include <fstream>

class LogCommand
{
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class LogCommandConsole : LogCommand
{
public:
	void print(const std::string& message) override
	{
		std::cout << "Console print: "
			<< message
			<< std::endl;
	}
};

class LogCommandFile : LogCommand
{
public:
	LogCommandFile()
	{
		fout.open("LogCommandFile.txt");
		if (!fout.is_open())
		{
			std::cout << "LogCommandFile.txt isn't opened!"
				<< std::endl;
		}
	}
	~LogCommandFile()
	{
		fout.close();
	}
	void print(const std::string& message) override
	{
		fout << "Log print: "
			<< message
			<< std::endl;
	}
private:
	std::ofstream fout;
};

int main()
{
	LogCommandConsole lCC;
	lCC.print("Hello, World!");
	LogCommandFile lCF;
	lCF.print("Hello, World!");
	return 0;
}