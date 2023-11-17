/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-harco <gd-harco@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:15:11 by gd-harco          #+#    #+#             */
/*   Updated: 2023/11/10 15:01:26 by gd-harco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

LMateria	*g_List;

//Never alocate Materias on the stack, it will cause a crash when freeing the list.

int main(void) {
	Character	*Cloud = new Character("Cloud");
	Character	*Aerith = new Character("Aerith");
	g_List = new LMateria;
	g_List->current = NULL;
	g_List->next = NULL;

	AMateria	*iceSword = new Ice();
	AMateria	*healStick = new Cure();
	AMateria	*iceGauntlet = new Ice();
	AMateria	*healthPotion = new Cure();
	// AMateria	*iceArrow = new Ice();
	// AMateria	*chocobo = new Cure();

	Cloud->equip(iceSword);
	Cloud->equip(healStick);
	Cloud->equip(iceGauntlet);
	Cloud->equip(healthPotion);
	//TODO: Copy assignment operator never called, see why
	// Aerith = Cloud;
	Aerith->equip(Cloud->getInventory(1)->clone());
	Aerith->use(1, *Cloud);
	Aerith->unequip(1);
	Aerith->unequip(2);
	Aerith->unequip(3);
	LMateriaFree();
	delete Cloud;
	delete Aerith;
}
