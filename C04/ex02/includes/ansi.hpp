#ifndef ANSI_HPP
# define ANSI_HPP

# include <sstream>

/*_____________FOR USE____________*/
/*
Starting with \033[ then add your style
(for serveral choices separete with ;),
add your color and finish with 'm'

Note : The white color is default,
so there is no need to add it to use it.
*/

//      STYLE
# define NORMAL 0
# define BOLD 1
# define DARK 2
# define ITALIC 3
# define UNDERLINE 4
# define BLINK 5
# define HIGHLIGHT 7
# define TRANSPARENT 8
# define STRIKETHROUGH 9

//      COLOR
# define BLACK 30
# define RED 31
# define GREEN 32
# define YELLOW 33
# define BLUE 34
# define PURPLE 35
# define CYAN 36

std::string	ansi(const short set[], short size);

#endif
