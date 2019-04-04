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


#include "animal.h"
#include "food.h"
#include <random>


Animal::Animal(void) :
m_fitness(random_int()), m_weapon(random_weapon()), m_fit_loss_rate(random_int()),
m_eat_prob(random_prob()), m_mate_prob(random_prob()), m_mutate_prob(random_prob())
{
}


Animal::Animal(const uint8_t fitness, const Weapon weapon, const uint8_t fit_loss_rate,
	const float eat_prob, const float mate_prob, const float mutate_prob) :
	m_fitness(fitness), m_weapon(weapon), m_fit_loss_rate(fit_loss_rate),
	m_eat_prob(eat_prob), m_mate_prob(mate_prob), m_mutate_prob(mutate_prob)
{
}


bool Animal::decide(const float probability)
{
	// use a hardware entropy source if available, otherwise use PRNG
	std::bernoulli_distribution distribution(probability);
	return distribution(std::random_device::random_device());
}


void Animal::add_claimant(Animal* const animal)
{
	if (animal != this)
		m_claimants.emplace(animal);
}


bool Animal::fight(Animal* const animal1, Animal* const animal2)
{
	// first fight with weapons
	switch (animal1->m_weapon)
	{
		case Weapon::paper:
		{
			if (animal2->m_weapon == Weapon::rock)
				return false;
			else if (animal2->m_weapon == Weapon::scissors)
				return true;
		}
		case Weapon::rock:
		{
			if (animal2->m_weapon == Weapon::scissors)
				return false;
			else if (animal2->m_weapon == Weapon::paper)
				return true;
		}
		case Weapon::scissors:
		{
			if (animal2->m_weapon == Weapon::paper)
				return false;
			else if (animal2->m_weapon == Weapon::rock)
				return true;
		}
	}

	// second decide by fitness value
	if (animal1->m_fitness > animal2->m_fitness)
		return false;
	else if (animal2->m_fitness > animal1->m_fitness)
		return true;

	// third random choice
	if (decide(0.5))
		return false;
	else
		return true;
}


Animal* const Animal::mate(Animal* const animal1, Animal* const animal2)
{
	Animal* new_animal = new Animal(*animal1);

	if (decide(0.5))
		new_animal->m_eat_prob = animal2->m_eat_prob;
	
	if (decide(0.5))
		new_animal->m_fit_loss_rate = animal2->m_fit_loss_rate;
	
	if (decide(0.5))
		new_animal->m_mate_prob = animal2->m_mate_prob;
	
	if (decide(0.5))
		new_animal->m_mutate_prob = animal2->m_mutate_prob;

	if (decide(0.5))
		new_animal->m_weapon = animal2->m_weapon;

	if (decide(0.5))
		new_animal->m_fitness = animal2->m_fitness;

	new_animal->m_claimants.clear();

	return new_animal;
}


void Animal::mutate(void)
{
	if (decide(0.5))
		m_eat_prob = random_prob();

	if (decide(0.5))
		m_fit_loss_rate = random_int();

	if (decide(0.5))
		m_mate_prob = random_prob();

	if (decide(0.5))
		m_mutate_prob = random_prob();

	if (decide(0.5))
		m_weapon = random_weapon();
}


void Animal::ageing(void)
{
	// slowly dying
	if (m_fit_loss_rate > m_fitness)
		m_fitness = 0;
	else
		m_fitness -= m_fit_loss_rate;
}


void Animal::eat_food(const uint8_t energy)
{
	if (energy > 255 - m_fitness)
		m_fitness = 255;
	else
		m_fitness += energy;
}


Animal* const Animal::tournament(void)
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


Animal::Weapon Animal::random_weapon(void)
{
	// use a hardware entropy source if available, otherwise use PRNG
	std::uniform_int_distribution<> distribution(0, 2);

	switch (distribution(std::random_device::random_device()))
	{
		case 0:
			return Weapon::paper;
		case 1:
			return Weapon::rock;
		default:
			return Weapon::scissors;
	}
}


float Animal::random_prob(void)
{
	// use a hardware entropy source if available, otherwise use PRNG
	std::uniform_real_distribution<float> distribution(0.0, 1.0);
	return distribution(std::random_device::random_device());
}


uint8_t Animal::random_int(void)
{
	// use a hardware entropy source if available, otherwise use PRNG
	std::uniform_int_distribution<int> distribution(1, 255);
	return distribution(std::random_device::random_device());
}


uint8_t Animal::get_fitness(void) const
{
	return m_fitness;
}


void Animal::simulate(const std::vector<Animal* const>& animals, const std::vector<Food* const>& food)
{
	if ((decide(m_eat_prob)) && (food.size() > 0)) // if wants to eat
	{
		// use a hardware entropy source if available, otherwise use PRNG
		std::uniform_int_distribution<size_t> distribution(0, food.size() - 1);
		size_t selection = distribution(std::random_device::random_device());
		food[selection]->add_claimant(this);
	}
	
	if ((decide(m_mate_prob)) && (animals.size() > 1)) // if wants to mate
	{
		// use a hardware entropy source if available, otherwise use PRNG
		std::uniform_int_distribution<size_t> distribution(0, animals.size() - 1);
		size_t selection = distribution(std::random_device::random_device());
		animals[selection]->add_claimant(this);
	}
}
