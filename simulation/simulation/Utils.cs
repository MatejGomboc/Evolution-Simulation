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
    public static class Utils
    {
        private static Random random = new Random();
        public const float maxRandomFloatValue = 1.0e+12f;
        public const float minRandomFloatValue = -1.0e+12f;

        #region clamp
        public static float clamp(float value, float min, float max)
        {
	        if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

	        if (value > max)
		        return max;
	        else if (value < min)
		        return min;
	        else
		        return value;
        }

        public static int clamp(int value, int min, int max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

            if (value > max)
                return max;
            else if (value < min)
                return min;
            else
                return value;
        }

        public static uint clamp(uint value, uint min, uint max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in clamp function.");

            if (value > max)
                return max;
            else if (value < min)
                return min;
            else
                return value;
        }
        #endregion

        #region wrap
        public static int wrap(int value, int min, int max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in wrap function.");
            if (min == max) return min;

            if (value >= max) value -= ((value - min) / (max - min)) * (max - min);

            if (value < min)
            {
                value += ((max - value) / (max - min)) * (max - min);
                if (value == max) value = min;
            }

            return value;
        }

        public static uint wrap(uint value, uint min, uint max)
        {
            if (min > max) throw new ArithmeticException("MIN > MAX in wrap function.");
            if (min == max) return min;

            if (value >= max) value -= ((value - min) / (max - min)) * (max - min);

            if (value < min)
            {
                value += ((max - value) / (max - min)) * (max - min);
                if (value == max) value = min;
            }

            return value;
        }
        #endregion

        #region random
        public static float randomFloat(float min, float max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return ((float)random.NextDouble() * (max - min) / 0.99999999999999978f + min);
        }

        public static int randomInt(int min, int max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return random.Next(min, max + 1);
        }

        public static uint randomUint(uint min, uint max)
        {
            if (min > max)
                throw new ArithmeticException("MIN > MAX in randomFloat function.");
            else if (min == max)
                return min;
            else
                return (uint)random.Next((int)min, (int)max + 1);
        }

        public static float randomFloat()
        {
            return ((float)random.NextDouble() * (maxRandomFloatValue - minRandomFloatValue) / 0.99999999999999978f + minRandomFloatValue);
        }

        public static int randomInt()
        {
            return random.Next(int.MinValue, int.MaxValue);
        }

        public static uint randomUint()
        {
            return (uint)random.Next(int.MinValue, int.MaxValue);
        }
        #endregion

        #region division
        public static int secureDivide(int value1, int value2)
        {
            if (value1 == value2)
                return 1;
            else if (value2 == 0)
            {
                if (value1 > 0)
                    return int.MaxValue;
                else
                    return int.MinValue;
            }
            else
                return value1 / value2;
        }

        public static int secureRemainder(int value1, int value2)
        {
            if (value1 == value2)
                return 0;
            else if (value2 == 0)
                return 0;
            else
                return value1 % value2;
        }

        public static float secureDivide(float value1, float value2)
        {
            if ((value1 == value2) || (value1 == -value2))
                return 1.0f;
            else if (value2 == 0.0f)
            {
                if (value1 > 0.0f)
                    return float.PositiveInfinity;
                else
                    return float.NegativeInfinity;
            }
            else
                return value1 / value2;
        }
        #endregion

        #region multiplication
        public static int secureMultiply(int value1, int value2)
        {
            try
            {
                checked
                {
                    return value1 * value2;
                }
            }
            catch(OverflowException)
            {
                if ((value1 > 0) && (value2 > 0))
                {
                    return int.MaxValue;
                }
                else
                {
                    return int.MinValue;
                }
            }
        }

        public static float secureMultiply(float value1, float value2)
        {
            if ((value1 == 0.0f) || (value2 == 0.0f))
            {
                return 0.0f;
            }
            else
            {
                return value1 * value2;
            }
        }
        #endregion

        #region addition
        public static int secureAdd(int value1, int value2)
        {
            try
            {
                checked
                {
                    return value1 + value2;
                }
            }
            catch (OverflowException)
            {
                if ((value1 > 0) && (value2 > 0))
                {
                    return int.MaxValue;
                }
                else if ((value1 < 0) && (value2 < 0))
                {
                    return int.MinValue;
                }
                else
                {
                    throw new ArithmeticException("Unexpected overflow occurred in secureAdd() function.");
                }
            }
        }

        public static float secureAdd(float value1, float value2)
        {
            if (value1 == -value2)
            {
                return 0.0f;
            }
            else
            {
                return value1 + value2;
            }
        }
        #endregion

        #region subtraction
        public static int secureSubtract(int value1, int value2)
        {
            try
            {
                checked
                {
                    return value1 - value2;
                }
            }
            catch (OverflowException)
            {
                if ((value1 > 0) && (value2 < 0))
                {
                    return int.MaxValue;
                }
                else if ((value1 < 0) && (value2 > 0))
                {
                    return int.MinValue;
                }
                else
                {
                    throw new ArithmeticException("Unexpected overflow occurred in secureSubtract() function.");
                }
            }
        }

        public static float secureSubtract(float value1, float value2)
        {
            if (value1 == value2)
            {
                return 0.0f;
            }
            else
            {
                return value1 - value2;
            }
        }
        #endregion
    }
}
