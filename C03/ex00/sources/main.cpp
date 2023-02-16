#include "ClapTrap.hpp"

int    main(void) {
    ClapTrap uno("Clappi");
    ClapTrap dos("None");
    ClapTrap three("Claapo");
    ClapTrap four(three);


    dos = three;
    std::cout << std::endl;
    std::cout << "Let's fight !" << std::endl << std::endl;

    std::cout << "  found a stick on the floor." << std::endl ;
    uno.setAttackDamage(3);
    
    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 1" << ansi(NULL, 0) << std::endl;
    dos.attack(uno.getName());
    uno.takeDamage(0);

    uno.attack(dos.getName());
    dos.takeDamage(3);
    
    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 2" << ansi(NULL, 0) << std::endl;
    dos.beRepaired(2);
    
    uno.attack(dos.getName());
    dos.takeDamage(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 3" << ansi(NULL, 0) << std::endl;
    dos.attack(uno.getName());
    uno.takeDamage(0);

    uno.attack(dos.getName());
    dos.takeDamage(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 4" << ansi(NULL, 0) << std::endl;
    dos.beRepaired(3);

    uno.attack(dos.getName());
    dos.takeDamage(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 5" << ansi(NULL, 0) << std::endl;
    uno.attack(dos.getName());
    dos.takeDamage(3);
    uno.attack(dos.getName());
    dos.takeDamage(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 6" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 7" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 8" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 9" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 10" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 11" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);

    std::cout << std::endl << ansi((short[]){PURPLE}, 1) << "ROUND 11" << ansi(NULL, 0) << std::endl;
    uno.beRepaired(3);
	return 0;
}
