/*
    Robbie Robot Shop v1.0 beta, (c) 2016 by Professor George F. Rice.

    This file is part of Robbie Robot Shop (RRS), an example solution
    to Project #5 for UTA CSE 1325. 

    Permission is expressly DENIED to students in this class to include
    ANY of this code in a submitted Homework #5 solution during any semester 
    of this class. This restriction supercedes the license granted below,
    and use of this code for Homework #5 will be deemed an Honor Code Violation 
    regardless of disclosure.
    
    Permission is expressly GRANTED to students in this class to include
    this code, or any derivatives thereof, in Project #6 of the same class,
    providing that this header is not removed.
    
    RRS is otherwise free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    
    RRS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with RRS.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "locomotor.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Assume linear power draw proportional to speed
int Locomotor::power(int speed) {return _max_power_consumed * speed / _max_speed_possible;}
int Locomotor::max_power() const {return _max_power_consumed;}
int Locomotor::max_speed() const {return _max_speed_possible;}

ostream& operator<<(ostream& os, const Locomotor& locomotor) {
  return os << fixed << setprecision(2)
            << locomotor.name() << " (" << locomotor.type() << " PN " << locomotor.part_number()
            << ") weighs " << locomotor.weight() << "#, costs $" << locomotor.cost()
            << ", max power " << locomotor.max_power() << " watts"
            << " - " << locomotor.description();
}
