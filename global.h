 /*******************************************************************\
 * Copyright 2012 Kai-Feng Chou - mapleellpam at gmail dot com       *
 *                                                                   *
 * Licensed under the Apache License, Version 2.0 (the "License");   *
 * you may not use this file except in compliance with the License.  *
 * You may obtain a copy of the License at                           *
 *                                                                   *
 *   http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                   *
 * Unless required by applicable law or agreed to in writing,        *
 * software distributed under the License is distributed on an       *
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY            *
 * KIND, either express or implied. See the License for the          *
 * specific language governing permissions and limitations           *
 * under the License.                                                *
 *                                                                   *
 * ProgrameNode Translator                                           *
 * Copyright 2012 mapleellpam at gmail dot com   All rights reserved.*
 *                                                                   *
 *                                                                   *
 *     Author: mapleelpam at gmail.com - Kai-Feng Chou - maple       *
 \*******************************************************************/

#ifndef __MAPLE_GLOBAL_H__
#define __MAPLE_GLOBAL_H__

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <stdlib.h>
#include <fstream>

#define USE_STD_SMART_PTR

#ifdef USE_STD_SMART_PTR
	#include <tr1/memory>
	#define SHARED_PTR(X) std::tr1::shared_ptr<X>
	#define STATIC_CAST(T,X) std::tr1::static_pointer_cast<T>(X)
	#define DYNA_CAST(T,X) std::tr1::dynamic_pointer_cast<T>(X)
	#define CONST_CAST(T,X) std::tr1::const_pointer_cast<T>(X)
#endif

////#include <boost/assert.hpp>
////#include <boost/test/test_tools.hpp>
//
//#define ENABLE_DEBUG_EXCESS_INFO false
//#define _DS(STR) ( std::string(STR) )
//#define _DS2(STR) ( (ENABLE_DEBUG_EXCESS_INFO)?std::string(STR):std::string("") )


#endif
