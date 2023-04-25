#pragma once

# include <deque>
# include <list>

void	insert(std::deque<unsigned int> &sequence);
void    insert(std::list<unsigned int> &sequence);
void	merge(std::deque<unsigned int> &sequence, std::deque<unsigned int> &left, std::deque<unsigned int> &right);
void	merge(std::list<unsigned int> &sequence, std::list<unsigned int> &left, std::list<unsigned int> &right);
void	merge_insert(std::deque<unsigned int> &sequence, unsigned int threshold);
void	merge_insert(std::list<unsigned int> &sequence, unsigned int threshold);