
#include <memory>
#include "MainMenu.h"
void SmartPointerDemo() {
	std::unique_ptr<MainMenu> tesdrive(new MainMenu());
	tesdrive->main_menu();

}
int main() {
	SmartPointerDemo();
	
	return 0;
}