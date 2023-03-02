#include "Dog.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Dog::Dog(void) : Animal("Dog") {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	this->_brain = new Brain;
	return ;
}

Dog::Dog(Dog &copy) : Animal(copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Dog::~Dog(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	delete this->_brain;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Dog	&Dog::operator=(const Dog &rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Dog::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC, YELLOW}, 3) + "\"Woaf!\"";
	return ;
}

void	Dog::_initBrain(void) {
	this->_brain->setIdea(0, "J'aimerais passer du temps à me faire câliner.");
	this->_brain->setIdea(1, "Je voudrais visiter un zoo et voir d'autres animaux.");
	this->_brain->setIdea(2, "Je voudrais apprendre à jouer au football avec mon maître.");
	this->_brain->setIdea(3, "J'aimerais passer du temps à jouer avec des chatons.");
	this->_brain->setIdea(4, "Je voudrais apprendre à faire du patin à roulettes.");
	this->_brain->setIdea(5, "J'aimerais passer du temps à jouer avec des enfants handicapés.");
	this->_brain->setIdea(6, "Je voudrais apprendre à faire du snowboard.");
	this->_brain->setIdea(7, "J'aimerais passer du temps à apprendre la langue des signes pour communiquer avec les sourds.");
	this->_brain->setIdea(8, "Je voudrais visiter un parc national et faire une randonnée.");
	this->_brain->setIdea(9, "J'aimerais passer du temps à jouer avec des animaux de la ferme.");
	this->_brain->setIdea(10,"Je voudrais apprendre à faire de la planche à voile.");
	this->_brain->setIdea(11,"J'aimerais passer du temps à apprendre à mon maître à obéir.");
	this->_brain->setIdea(12,"J'aimerais bien aller à la plage et jouer dans l'eau");
	this->_brain->setIdea(13,"Je me demande à quoi ressemble la vue depuis le sommet d'une montagne");
	this->_brain->setIdea(14,"J'adore les jouets en caoutchouc, j'aimerais bien en avoir un nouveau");
	this->_brain->setIdea(15,"J'aimerais apprendre à jouer à un jeu de société avec ma famille");
	this->_brain->setIdea(16,"Je me sens un peu seul aujourd'hui, j'aimerais bien avoir un ami chien pour jouer avec moi");
	this->_brain->setIdea(17,"J'adore les longues promenades dans la nature, j'aimerais en faire une aujourd'hui");
	this->_brain->setIdea(18,"J'aimerais bien essayer de courir plus vite et de sauter plus haut");
	this->_brain->setIdea(19,"Je suis curieux de savoir comment fonctionnent les voitures et les camions");
	this->_brain->setIdea(20,"J'aimerais bien apprendre à obéir à des ordres plus compliqués");
	this->_brain->setIdea(21,"J'aimerais aller dans un parc à chiens aujourd'hui.");
	this->_brain->setIdea(22,"Je veux jouer à la balle.");
	this->_brain->setIdea(23,"Mon maître m'a acheté un nouveau jouet, je suis tellement excité !");
	this->_brain->setIdea(24,"Je veux dormir sur le canapé aujourd'hui.");
	this->_brain->setIdea(25,"Je veux un nouveau collier, le mien est vieux.");
	this->_brain->setIdea(26,"J'aime sentir les fleurs pendant que je me promène.");
	this->_brain->setIdea(27,"Je suis excité de rencontrer d'autres chiens aujourd'hui.");
	this->_brain->setIdea(28,"Mon maître m'a promis une friandise si je suis sage.");
	this->_brain->setIdea(29,"J'adore faire des câlins à mon maître.");
	this->_brain->setIdea(30,"Je veux apprendre de nouveaux tours, cela rend mon maître heureux.");
	this->_brain->setIdea(31,"Je voudrais aller courir dans le parc.");
	this->_brain->setIdea(32,"J'ai envie d'un os à mâcher.");
	this->_brain->setIdea(33,"Il est temps pour ma promenade quotidienne.");
	this->_brain->setIdea(34,"J'aimerais jouer à attraper la balle.");
	this->_brain->setIdea(35,"J'ai besoin d'un bon brossage de poil.");
	this->_brain->setIdea(36,"J'ai envie d'une friandise.");
	this->_brain->setIdea(37,"Je me sens seul, j'aimerais jouer avec mon maître.");
	this->_brain->setIdea(38,"Je voudrais faire une sieste au soleil.");
	this->_brain->setIdea(39,"J'aimerais explorer de nouveaux sentiers lors de ma promenade.");
	this->_brain->setIdea(40,"Je voudrais essayer un nouveau jouet à mâcher.");
	this->_brain->setIdea(41,"Il est temps pour mon bain hebdomadaire.");
	this->_brain->setIdea(42,"Je me sens excité, j'aimerais jouer à cache-cache.");
	this->_brain->setIdea(43,"J'aimerais aller à la plage et nager dans l'eau.");
	this->_brain->setIdea(44,"Je voudrais apprendre un nouveau tour.");
	this->_brain->setIdea(45,"J'aimerais passer du temps à jouer avec d'autres chiens.");
	this->_brain->setIdea(46,"J'ai besoin de sortir et de sentir l'air frais.");
	this->_brain->setIdea(47,"Je voudrais aller à la montagne pour faire une randonnée.");
	this->_brain->setIdea(48,"J'aimerais passer du temps avec mon maître à jouer à des jeux de société.");
	this->_brain->setIdea(49,"Je voudrais aller à l'agility et essayer les obstacles.");
	this->_brain->setIdea(50,"J'ai besoin de plus d'exercice pour me dépenser.");
	this->_brain->setIdea(51,"Je voudrais essayer un nouveau parc à chiens.");
	this->_brain->setIdea(52,"J'aimerais passer du temps à jouer avec des enfants.");
	this->_brain->setIdea(53,"Je voudrais essayer la natation en eau profonde.");
	this->_brain->setIdea(54,"J'aimerais passer du temps avec mon maître à faire de la course à pied.");
	this->_brain->setIdea(55,"Je voudrais aller en voyage avec mon maître.");
	this->_brain->setIdea(56,"J'ai besoin de plus de jouets pour m'amuser.");
	this->_brain->setIdea(57,"Je voudrais apprendre à faire du skateboard.");
	this->_brain->setIdea(58,"J'aimerais visiter une ferme et rencontrer d'autres animaux.");
	this->_brain->setIdea(59,"Je voudrais apprendre à jouer du frisbee.");
	this->_brain->setIdea(60,"J'aimerais passer du temps à me détendre dans le jardin.");
	this->_brain->setIdea(61,"Je voudrais visiter un lac et nager.");
	this->_brain->setIdea(62,"J'aimerais passer du temps à apprendre des tours de cirque.");
	this->_brain->setIdea(63,"Je voudrais apprendre à faire du vélo.");
	this->_brain->setIdea(64,"J'aimerais passer du temps à me faire câliner.");
	this->_brain->setIdea(65,"Je voudrais visiter un zoo et voir d'autres animaux.");
	this->_brain->setIdea(66,"Je voudrais apprendre à jouer au football avec mon maître.");
	this->_brain->setIdea(67,"J'aimerais passer du temps à jouer avec des chatons.");
	this->_brain->setIdea(68,"Je voudrais apprendre à faire du patin à roulettes.");
	this->_brain->setIdea(69,"J'aimerais passer du temps à jouer avec des enfants handicapés.");
	this->_brain->setIdea(70,"Je voudrais apprendre à faire du snowboard.");
	this->_brain->setIdea(71,"J'aimerais passer du temps à apprendre la langue des signes pour communiquer avec les sourds.");
	this->_brain->setIdea(72,"Je voudrais visiter un parc national et faire une randonnée.");
	this->_brain->setIdea(73,"J'aimerais passer du temps à jouer avec des animaux de la ferme.");
	this->_brain->setIdea(74,"Je voudrais apprendre à faire de la planche à voile.");
	this->_brain->setIdea(75,"J'aimerais passer du temps à apprendre à mon maître à obéir.");
	this->_brain->setIdea(76,"J'aimerais bien aller à la plage et jouer dans l'eau");
	this->_brain->setIdea(77,"Je me demande à quoi ressemble la vue depuis le sommet d'une montagne");
	this->_brain->setIdea(78,"J'adore les jouets en caoutchouc, j'aimerais bien en avoir un nouveau");
	this->_brain->setIdea(79,"J'aimerais apprendre à jouer à un jeu de société avec ma famille");
	this->_brain->setIdea(80,"Je me sens un peu seul aujourd'hui, j'aimerais bien avoir un ami chien pour jouer avec moi");
	this->_brain->setIdea(81,"J'adore les longues promenades dans la nature, j'aimerais en faire une aujourd'hui");
	this->_brain->setIdea(82,"J'aimerais bien essayer de courir plus vite et de sauter plus haut");
	this->_brain->setIdea(83,"Je suis curieux de savoir comment fonctionnent les voitures et les camions");
	this->_brain->setIdea(84,"J'aimerais bien apprendre à obéir à des ordres plus compliqués");
	this->_brain->setIdea(85,"Je suis reconnaissant d'avoir une famille aimante qui prend soin de moi, je vais leur donner des câlins et des léchouilles pour leur montrer à quel point je les aime.");
	this->_brain->setIdea(86,"J'aimerais aller dans un parc à chiens aujourd'hui.");
	this->_brain->setIdea(87,"Je veux jouer à la balle.");
	this->_brain->setIdea(88,"Mon maître m'a acheté un nouveau jouet, je suis tellement excité !");
	this->_brain->setIdea(89,"Je veux dormir sur le canapé aujourd'hui.");
	this->_brain->setIdea(90,"Je veux un nouveau collier, le mien est vieux.");
	this->_brain->setIdea(91,"J'aime sentir les fleurs pendant que je me promène.");
	this->_brain->setIdea(92,"Je suis excité de rencontrer d'autres chiens aujourd'hui.");
	this->_brain->setIdea(93,"Mon maître m'a promis une friandise si je suis sage.");
	this->_brain->setIdea(94,"J'adore faire des câlins à mon maître.");
	this->_brain->setIdea(95,"Je veux apprendre de nouveaux tours, cela rend mon maître heureux.");
	this->_brain->setIdea(96,"Je veux jouer à la balle.");
	this->_brain->setIdea(97,"Je voudrais apprendre à jouer du frisbee.");
 	this->_brain->setIdea(98,"J'aimerais passer du temps à jouer avec des animaux de la ferme.");
	this->_brain->setIdea(99,"J'aimerais passer du temps avec mon maître à jouer à des jeux de société.");
	return ;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	Dog::getType(void) const { return ansi((short[]){BOLD, ITALIC, YELLOW}, 3) + this->_type; }

Brain	*Dog::getBrain(void) const { return this->_brain; }

/********************************************************************************/
