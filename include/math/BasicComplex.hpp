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

#include <cmath>

namespace math {
template < class T >
class BasicComplex {
public:
	/**
	 * @brief Construct a new Basic Complex object
	 * 
	 * @param real 
	 * @param imaginary 
	 */
	BasicComplex( T real, T imaginary )
		: mReal{ real }
		, mImaginary{ imaginary } {}

public:
	/**
	 * @brief Get the real part of the complex number
	 * 
	 * @return the real part of the number
	 */
	T getReal() const {
		return mReal;
	}

	/**
	 * @brief Get the imaginary part of the complex number
	 * 
	 * @return the imaginary part of the number
	 */
	T getImaginary() const {
		return mImaginary;
	}

public:
	/**
	 * @brief Get the modulus of the complex 
	 * 
	 * @return the modulus of the given number
	 */
	double mod() const {
		return std::sqrt( std::pow( mReal, 2 ) + std::pow( mImaginary, 2 ) );
	}

	/**
	 * @brief Natual logarithm of the complex number
	 * 
	 * @return the logarithm of the complex number
	 */
	virtual double log() const = 0;

protected:
	T mReal;
	T mImaginary;
};
} // namespace math