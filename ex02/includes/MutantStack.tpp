/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 08:40:43 by luis-ffe          #+#    #+#             */
/*   Updated: 2025/01/06 08:40:47 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template <class T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template <class T>
MutantStack<T>::~MutantStack(void) {}

template <class T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) {
	return (this->c.rbegin());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) {
	return (this->c.rend());
}