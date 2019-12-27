####################################################################################################
# \file makefile.inc
# \brief  Makefile for the include files of python3 library
# \author C. Jimenez
# \copyright Copyright(c) 2019 Cedric Jimenez
#
# This file is part of cantools.
#
# cantools is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cantools is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with cantools.  If not, see <http://www.gnu.org/licenses/>.
####################################################################################################


# Library directory
LIBRARY_DIR := $(ROOT_DIR)/3rdparty/python3.8

# Source directories
SOURCE_DIRS := $(LIBRARY_DIR)

# Source files
PROJECT_SOURCE_FILES := 
              
# Project specific include directories
PROJECT_INC_DIRS := $(PROJECT_INC_DIRS) \
                    $(ROOT_DIR)/build/3rdparty/python3/lib/$(TARGET)/include/python3.8

