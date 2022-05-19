/**
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

#pragma once

#include "math/BasicComplex.hpp"

namespace math {
template < class T >
class CordicComplex : public BasicComplex< T > {
	using BasicComplex< T >::mImaginary;
	using BasicComplex< T >::mReal;

public:
	/**
	 * @brief Construct a new CordicComplex object
	 * 
	 * @param real 
	 * @param imaginary 
	 */
	CordicComplex( T real, T imaginary )
		: BasicComplex< T >{ real, imaginary } {}

public:
	/**
	 * @brief Natual logarithm of the complex number
	 * 
	 * @return the logarithm of the complex number
	 */
	double log() const override {
		// Calling the log() method with basic parameter
		return log( 1.0 );
	}

	/**
	 * @brief Natual logarithm of the complex number
	 * 
	 * @param scaleFactor 
	 * @return the logarithm of the complex number
	 */
	double log( double scaleFactor ) const {
		const auto modulus = std::pow( mReal, 2 ) + std::pow( mImaginary, 2 );
		const auto xn	   = modulus * scaleFactor + 1;
		const auto yn	   = modulus * scaleFactor - 1;

		const auto wn		  = std::atanh( yn / xn );
		const auto subtrahend = std::log( scaleFactor ) / 2;
		return wn - subtrahend;
	}
};
} // namespace math