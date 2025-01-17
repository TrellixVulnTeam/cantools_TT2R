/*
Copyright(c) 2019 Cedric Jimenez

This file is part of cantools.

cantools is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

cantools is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with cantools.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NOCOPY_H
#define NOCOPY_H


/** \brief Interface for classes which instances cannot be copied */
class INoCopy
{
    public:

        /** \brief Default constructor */
        INoCopy() = default;

        /** \brief Deleted copy constructor */
        INoCopy(const INoCopy& copy) = delete;

        /** \brief Deleted move constructor */
        INoCopy(const INoCopy&& copy) = delete;

        /** \brief Deleted copy operator */
        INoCopy& operator = (const INoCopy& copy) = delete;
};


#endif // NOCOPY_H
