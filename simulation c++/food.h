/*
Copyright (C) 2018 Matej Gomboc (https://github.com/MatejGomboc/Evolution-Simulation)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef FOOD_H
#define FOOD_H

#include <cstdint>
#include <set>

class Animal;

class Food
{
private:
	const uint8_t m_energy;
	std::set<Animal* const> m_claimants;

public:
	Food(void);
	Food(const uint8_t energy);
	void add_claimant(Animal* const animal);
	uint8_t get_energy(void) const;
	Animal* const tournament(void);
	static uint8_t random_int(void);
};

#endif
