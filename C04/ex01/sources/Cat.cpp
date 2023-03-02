#include "Cat.hpp"

/********************************************************************************/
/* ------------------------------- CONSTRUCTOR -------------------------------- */
/********************************************************************************/

Cat::Cat(void) : Animal("Cat") {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Default constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	this->_brain = new Brain;
	return ;
}

Cat::Cat(Cat &copy) : Animal(copy) {
	std::cout << ansi((short[]){BOLD, GREEN}, 2) + "Copy constructor called for " + __func__ + " of type " + this->_type + "." << std::endl;
	return ;
}

/********************************************************************************/
/* -------------------------------- DESTRUCTOR -------------------------------- */
/********************************************************************************/

Cat::~Cat(void) {
	std::cout << ansi((short[]){BOLD, RED}, 2) + "Default constructor called for " + __func__ + "." << std::endl;
	delete this->_brain;
	return ;
}

/********************************************************************************/
/* --------------------------------- OVERLOAD --------------------------------- */
/********************************************************************************/

Cat	&Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		Animal::operator=(rhs);
	return *this;
}

/********************************************************************************/
/* --------------------------------- METHODS ---------------------------------- */
/********************************************************************************/

void	Cat::makeSound(void) const {
	std::cout << ansi((short[]){HIGHLIGHT, ITALIC, BLUE}, 3) + "\"Miaou!\"";
	return ;
}

void	Cat::_initBrain(void) {
	this->_brain->setIdea(0, "Je voudrais explorer le jardin aujourd'hui.");
	this->_brain->setIdea(1, "J'aime jouer avec des balles et d'autres jouets.");
	this->_brain->setIdea(2, "Parfois, j'aime me cacher dans des endroits confortables pour faire une petite sieste.");
	this->_brain->setIdea(3, "Je suis toujours excité quand il est temps de manger et j'adore essayer de voler de la nourriture.");
	this->_brain->setIdea(4, "Je suis fier de mon pelage et j'aime le lécher pour le garder propre.");
	this->_brain->setIdea(5, "Je pourrais dormir toute la journée, mais je préfère faire des bêtises.");
	this->_brain->setIdea(6, "J'aime regarder les oiseaux par la fenêtre, mais j'aimerais bien les chasser un jour.");
	this->_brain->setIdea(7, "Quand j'entends le bruit de la nourriture dans ma gamelle, je me jette dessus comme un affamé.");
	this->_brain->setIdea(8, "Parfois, je suis trop paresseux pour nettoyer mes poils, alors je laisse mes maîtres le faire.");
	this->_brain->setIdea(9, "J'adore jouer avec des pelotes de laine et les griffer jusqu'à ce qu'elles soient toutes défaites.");
	this->_brain->setIdea(10, "J'aime me frotter contre les jambes de mes maîtres pour leur montrer que je les aime.");
	this->_brain->setIdea(11, "Quand je suis sur le rebord de la fenêtre, je fais semblant de chasser les oiseaux pour m'amuser.");
	this->_brain->setIdea(12, "Je n'aime pas trop les autres chats, je préfère être le seul roi de la maison.");
	this->_brain->setIdea(13, "Parfois, j'ai l'impression que mes maîtres ne comprennent pas vraiment ce que je leur dis.");
	this->_brain->setIdea(14, "Quand je suis fatigué, j'aime me mettre en boule dans un coin douillet et ronronner jusqu'à m'endormir.");
	this->_brain->setIdea(15, "J'adore dormir toute la journée sur le canapé.");
	this->_brain->setIdea(16, "Je suis très doué pour attraper les souris.");
	this->_brain->setIdea(17, "Je suis très joueur et j'aime jouer avec des balles.");
	this->_brain->setIdea(18, "Je suis un chat très sociable et j'aime être entouré de mes amis chats.");
	this->_brain->setIdea(19, "Je suis un chat très câlin et j'aime passer du temps sur les genoux de mon humain.");
	this->_brain->setIdea(20, "Je suis très curieux et j'aime explorer tous les coins et recoins de la maison.");
	this->_brain->setIdea(21, "J'aime me faire brosser le pelage pour être encore plus beau.");
	this->_brain->setIdea(22, "J'adore grimper aux arbres et sauter de branche en branche.");
	this->_brain->setIdea(23, "J'aime me cacher dans des endroits insolites comme des cartons ou des sacs en papier.");
	this->_brain->setIdea(24, "Je suis très agile et j'aime sauter très haut pour attraper des objets en l'air.");
	this->_brain->setIdea(25, "Je pourrais grimper sur ce mur et sauter de l'autre côté. Mais il y a peut-être un chien dans le jardin d'à côté.");
	this->_brain->setIdea(26, "Je suis un chat si mignon et si doux. Tout le monde devrait m'aimer !");
	this->_brain->setIdea(27, "J'ai vraiment besoin d'un câlin en ce moment. Peut-être que si je me frotte contre les jambes de mon propriétaire, il me donnera un câlin.");
	this->_brain->setIdea(28, "Cette boîte a l'air confortable. Je vais y faire une petite sieste.");
	this->_brain->setIdea(29, "Si je saute sur cette étagère, je pourrais atteindre ces bibelots que j'ai toujours voulu jouer avec.");
	this->_brain->setIdea(30, "Je me demande ce qu'il y a derrière cette porte fermée. Je pourrais essayer de l'ouvrir...");
	this->_brain->setIdea(31, "Il y a une souris qui court dans le jardin. Je pourrais peut-être l'attraper si je suis assez rapide.");
	this->_brain->setIdea(32, "Mon propriétaire a laissé une chaussette par terre. Je pourrais la prendre et jouer avec.");
	this->_brain->setIdea(33, "J'aime me faire gratter derrière les oreilles.");
	this->_brain->setIdea(34, "Les souris sont ma proie préférée.");
	this->_brain->setIdea(35, "Dormir au soleil est ma position favorite.");
	this->_brain->setIdea(36, "Je suis un chasseur agile et rapide.");
	this->_brain->setIdea(37, "Les câlins sont toujours les bienvenus.");
	this->_brain->setIdea(38, "Je suis un maître de la détente.");
	this->_brain->setIdea(39, "J'aime m'asseoir sur le rebord de la fenêtre et regarder le monde passer.");
	this->_brain->setIdea(40, "Les plumes sont un jouet amusant à chasser.");
	this->_brain->setIdea(41, "Les papiers froissés sont parfaits pour jouer.");
	this->_brain->setIdea(42, "Mon ronronnement est ma façon de montrer mon bonheur.");
	this->_brain->setIdea(43, "J'aime regarder les oiseaux voler dans le ciel.");
	this->_brain->setIdea(44, "Je suis un expert pour me cacher dans les endroits les plus improbables.");
	this->_brain->setIdea(45, "Les croquettes sont délicieuses, mais j'aime aussi manger des herbes.");
	this->_brain->setIdea(46, "Je suis un animal de compagnie indépendant, mais j'aime quand même passer du temps avec mes humains.");
	this->_brain->setIdea(47, "Je peux passer des heures à lécher ma fourrure pour qu'elle soit bien propre.");
	this->_brain->setIdea(48, "Les boîtes sont le meilleur endroit pour jouer à cache-cache.");
	this->_brain->setIdea(49, "J'aime faire des siestes dans les endroits les plus insolites.");
	this->_brain->setIdea(50, "Je suis curieux et j'aime explorer de nouveaux endroits.");
	this->_brain->setIdea(51, "Les plages de soleil sont mes moments préférés de la journée.");
	this->_brain->setIdea(52, "J'aime jouer avec des balles en laine.");
	this->_brain->setIdea(53, "Je me demande si je devrais chasser une souris aujourd'hui.");
	this->_brain->setIdea(54, "J'adore regarder les oiseaux par la fenêtre.");
	this->_brain->setIdea(55, "J'aimerais prendre une petite sieste sur le canapé.");
	this->_brain->setIdea(56, "J'ai besoin d'un câlin de mon propriétaire.");
	this->_brain->setIdea(57, "Je me demande si je devrais jouer avec ma balle en mousse.");
	this->_brain->setIdea(58, "Je voudrais explorer le jardin aujourd'hui.");
	this->_brain->setIdea(59, "Je suis curieux de savoir ce que mon propriétaire prépare dans la cuisine.");
	this->_brain->setIdea(60, "J'ai besoin de me toiletter pour être beau/belle.");
	this->_brain->setIdea(61, "Je voudrais jouer avec une ficelle ou un ruban.");
	this->_brain->setIdea(62, "J'ai envie de faire une sieste sur le radiateur.");
	this->_brain->setIdea(63, "J'aime me prélasser au soleil et sentir la chaleur sur mon pelage.");
	this->_brain->setIdea(64, "Parfois, j'ai l'impression que je suis un roi ou une reine qui mérite toutes les attentions.");
	this->_brain->setIdea(65, "J'aime sentir l'odeur de l'herbe fraîchement coupée.");
	this->_brain->setIdea(66, "Je suis fasciné par les oiseaux et j'adore les observer.");
	this->_brain->setIdea(67, "Les souris sont mes proies préférées et j'aime les chasser pour m'amuser.");
	this->_brain->setIdea(68, "Quand je suis heureux, j'aime me frotter contre les jambes de mes humains.");
	this->_brain->setIdea(69, "J'aime jouer avec des balles et d'autres jouets.");
	this->_brain->setIdea(70, "Parfois, j'aime me cacher dans des endroits confortables pour faire une petite sieste.");
	this->_brain->setIdea(71, "Je suis toujours excité quand il est temps de manger et j'adore essayer de voler de la nourriture.");
	this->_brain->setIdea(72, "Je suis fier de mon pelage et j'aime le lécher pour le garder propre.");
	this->_brain->setIdea(73, "Je pourrais dormir toute la journée, mais je préfère faire des bêtises.");
	this->_brain->setIdea(74, "J'aime regarder les oiseaux par la fenêtre, mais j'aimerais bien les chasser un jour.");
	this->_brain->setIdea(75, "Quand j'entends le bruit de la nourriture dans ma gamelle, je me jette dessus comme un affamé.");
	this->_brain->setIdea(76, "Parfois, je suis trop paresseux pour nettoyer mes poils, alors je laisse mes maîtres le faire.");
	this->_brain->setIdea(77, "J'adore jouer avec des pelotes de laine et les griffer jusqu'à ce qu'elles soient toutes défaites.");
	this->_brain->setIdea(78, "J'aime me frotter contre les jambes de mes maîtres pour leur montrer que je les aime.");
	this->_brain->setIdea(79, "Quand je suis sur le rebord de la fenêtre, je fais semblant de chasser les oiseaux pour m'amuser.");
	this->_brain->setIdea(80, "Je n'aime pas trop les autres chats, je préfère être le seul roi de la maison.");
	this->_brain->setIdea(81, "Parfois, j'ai l'impression que mes maîtres ne comprennent pas vraiment ce que je leur dis.");
	this->_brain->setIdea(82, "Quand je suis fatigué, j'aime me mettre en boule dans un coin douillet et ronronner jusqu'à m'endormir.");
	this->_brain->setIdea(83, "J'adore dormir toute la journée sur le canapé.");
	this->_brain->setIdea(84, "Je suis très doué pour attraper les souris.");
	this->_brain->setIdea(85, "Je suis très joueur et j'aime jouer avec des balles.");
	this->_brain->setIdea(86, "Je suis un chat très sociable et j'aime être entouré de mes amis chats.");
	this->_brain->setIdea(87, "Je suis un chat très câlin et j'aime passer du temps sur les genoux de mon humain.");
	this->_brain->setIdea(88, "Je suis très curieux et j'aime explorer tous les coins et recoins de la maison.");
	this->_brain->setIdea(89, "J'aime me faire brosser le pelage pour être encore plus beau.");
	this->_brain->setIdea(90, "J'adore grimper aux arbres et sauter de branche en branche.");
	this->_brain->setIdea(91, "J'aime me cacher dans des endroits insolites comme des cartons ou des sacs en papier.");
	this->_brain->setIdea(92, "Je suis très agile et j'aime sauter très haut pour attraper des objets en l'air.");
	this->_brain->setIdea(93, "Je pourrais grimper sur ce mur et sauter de l'autre côté. Mais il y a peut-être un chien dans le jardin d'à côté.");
	this->_brain->setIdea(94, "Je suis un chat si mignon et si doux. Tout le monde devrait m'aimer !");
	this->_brain->setIdea(95, "Cette boîte a l'air confortable. Je vais y faire une petite sieste.");
	this->_brain->setIdea(96, "Si je saute sur cette étagère, je pourrais atteindre ces bibelots que j'ai toujours voulu jouer avec.");
	this->_brain->setIdea(97, "Je me demande ce qu'il y a derrière cette porte fermée. Je pourrais essayer de l'ouvrir...");
	this->_brain->setIdea(98, "Il y a une souris qui court dans le jardin. Je pourrais peut-être l'attraper si je suis assez rapide.");
	this->_brain->setIdea(99, "Mon propriétaire a laissé une chaussette par terre. Je pourrais la prendre et jouer avec.");
	return;
}

/********************************************************************************/
/* --------------------------------- ACCESSOR --------------------------------- */
/********************************************************************************/

std::string	Cat::getType(void) const { return ansi((short[]){BOLD, ITALIC, BLUE}, 3) + this->_type; }

Brain	*Cat::getBrain(void) const { return this->_brain; }

/********************************************************************************/
