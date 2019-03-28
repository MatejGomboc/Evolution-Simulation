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

#include "simulation.h"


Simulation::Simulation(const size_t N_animals, const size_t N_food) :
	m_max_N_animals(N_animals)
{
	m_animals.reserve(N_animals);

	for (size_t i = 0; i < N_animals; i++)
		m_animals.push_back(new Animal());

	m_food.reserve(N_food);

	for (size_t i = 0; i < N_food; i++)
		m_food.push_back(new Food());
}


Simulation::~Simulation()
{
	for (size_t i = 0; i < m_animals.size(); i++)
		delete m_animals[i];

	for (size_t i = 0; i < m_food.size(); i++)
		delete m_food[i];
}


void Simulation::simulate(void)
{
	// simulate behaviour
	for (size_t i = 0; i < m_animals.size(); i++)
	{
		m_animals[i]->simulate(m_animals, m_food);
	}

	// fight for and eat food
	for (size_t i = 0; i < m_food.size(); i++)
	{
		Animal* const winner = m_food[i]->tournament();
		if (winner != nullptr)
		{
			winner->eat_food(m_food[i]->get_energy());
			delete m_food[i];
			m_food.erase(m_food.begin() + i);
			i--;
		}
	}

	// fight for and mate
	for (size_t i = 0; i < m_animals.size(); i++)
	{
		Animal* const winner = m_animals[i]->tournament();
		if ((winner != nullptr) && (m_animals.size() <= m_max_N_animals))
			m_animals.push_back(Animal::mate(m_animals[i], winner));
	}

	// kill the weakest
	for (size_t i = 0; i < m_animals.size(); i++)
	{
		if (m_animals[i]->get_fitness() < 1)
		{
			delete m_animals[i];
			m_animals.erase(m_animals.begin() + i);
			i--;
		}
	}
}
