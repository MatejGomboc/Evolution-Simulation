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

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace simulation
{
    partial class Animal
    {
        public const uint stackDepth = 1000;
        public const uint maxHealth = 1000000;

        public enum Weapon
        {
            PAPER,
            ROCK,
            SCISSORS
        }

        public class ProgramCounter
        {
            public uint routineIndx;
            public uint instructionIndx;

            public ProgramCounter(uint routineIndx, uint instructionIndx)
            {
                this.routineIndx = routineIndx;
                this.instructionIndx = instructionIndx;
            }
        }

        public uint health
        {
            get
            {
                return this.health;
            }
            private set
            {
                this.health = value;
                this.health = Utils.clamp(this.health, 0, maxHealth);
            }
        }

        public List<Tuple<uint, Weapon>> claimants
        {
            get;
            private set;
        }

        public int[] memoryInt
        {
            get;
            private set;
        }

        public Program program
        {
            get;
            private set;
        }

        public ProgramCounter programCounter
        {
            get;
            private set;
        }

        public Stack<ProgramCounter> stack
        {
            get;
            private set;
        }

        public Animal(Program program, int[] memoryInt)
        {
            this.health = maxHealth;
            this.claimants = new List<Tuple<uint, Weapon>>();
            this.memoryInt = memoryInt;
            this.program = program;
            this.programCounter = new ProgramCounter(0, 0);
            this.stack = new Stack<ProgramCounter>();
        }

        public void consumeFood(uint foodEnergy)
        {
            health += foodEnergy;
        }
    }
}
