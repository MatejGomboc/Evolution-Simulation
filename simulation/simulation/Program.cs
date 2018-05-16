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

namespace simulation
{
    class Program
    {
        public Animal.Instruction[] mainRoutine = null;
        public Animal.Instruction[][] subroutines = null;
        public Animal.Instruction[][] traps = null;

        public int subroutinesOffset()
        {
            return 1;
        }

        public int trapsOffset()
        {
            return 1 + subroutines.GetLength(0);
        }

        public Animal.Instruction this[int indxRoutine, int indxInstruction]
        {
            get
            {
                if (indxRoutine == 0)
	            {
		            return mainRoutine[indxInstruction];
	            }
	            else if (indxRoutine < 1 + subroutines.GetLength(0))
	            {
		            return subroutines[indxRoutine - 1][indxInstruction];
	            }
                else if (indxRoutine < 1 + subroutines.GetLength(0) + traps.GetLength(0))
	            {
                    return traps[indxRoutine - 1 - subroutines.GetLength(0)][indxInstruction];
	            }
	            else
	            {
		            throw new IndexOutOfRangeException("Routine index out of range.");
	            }
            }
            set
            {
                if (indxRoutine == 0)
                {
                    mainRoutine[indxInstruction] = value;
                }
                else if (indxRoutine < 1 + subroutines.GetLength(0))
                {
                    subroutines[indxRoutine - 1][indxInstruction] = value;
                }
                else if (indxRoutine < 1 + subroutines.GetLength(0) + traps.GetLength(0))
                {
                    traps[indxRoutine - 1 - subroutines.GetLength(0)][indxInstruction] = value;
                }
                else
                {
                    throw new IndexOutOfRangeException("Routine index out of range.");
                }
            }
        }
    }
}
