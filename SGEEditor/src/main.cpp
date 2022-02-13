#include <iostream>

#include <SGECore/Application.hpp>


class MyApp : public SGE::Application {
	virtual void on_update() override {
		//std::cout << "Update frame: " << frame++ << std::endl;
	}

	int frame = 0;
};

int main() {
	auto myApp = std::make_unique<MyApp>();

	int returnCode = myApp->start(1024, 768, "App");

	std::cin.get();

	return returnCode;
}