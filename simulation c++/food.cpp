/*
Copyright (C) 2019 Matej Gomboc (https://github.com/MatejGomboc/Evolution-Simulation)

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


#include "food.h"
#include "animal.h"
#include <random>


Food::Food(void) :
	m_energy(random_int())
{
}


Food::Food(const uint8_t energy) :
	m_energy(energy)
{
}


void Food::add_claimant(Animal* const animal)
{
	m_claimants.emplace(animal);
}


uint8_t Food::get_energy(void) const
{
	return m_energy;
}


Animal* const Food::tournament(void)
{
	if (m_claimants.size() > 0)
	{
		while (m_claimants.size() > 1)
		{
			if (Animal::fight(*m_claimants.begin(), *(++m_claimants.begin())))
				m_claimants.erase(m_claimants.begin());
			else
				m_claimants.erase(++m_claimants.begin());
		}

		Animal* const winner = *m_claimants.begin();
		m_claimants.clear();
		return winner;
	}
	else
	{
		return nullptr;
	}
}


uint8_t Food::random_int(void)
{
	// use a hardware entropy source if available, otherwise use PRNG
	std::uniform_int_distribution<int> distribution(1, 255);
	return distribution(std::random_device::random_device());
}
