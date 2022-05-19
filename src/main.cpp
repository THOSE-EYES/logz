#/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *  http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <iostream>

#include "cli/input/parsers/ArgumentParser.hpp"
#include "math/CordicComplex.hpp"

int main( int argc, char** argv ) {
	// Get the command line parameters
	cli::input::parsers::ArgumentParser parser( argc, argv, '=' );
	const auto realPart		 = parser.getRequiredParameter< int >( "Re" );
	const auto imaginaryPart = parser.getRequiredParameter< int >( "Im" );
	const auto factor		 = parser.getRequiredParameter< double >( "Kc" );

	// Calculate the natural logarithm
	math::CordicComplex< int > complex( realPart, imaginaryPart );
	std::cout << "Natural logarithm of the given complex number is : "
			  << complex.log( factor ) << std::endl;

	return 0;
}