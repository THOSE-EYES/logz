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

#include <stdexcept>
#include <string>
#include <vector>

#include "cli/input/casters/StringArgumentCaster.hpp"
#include "common/interfaces/IParser.hpp"

namespace cli::input::parsers {
class ArgumentParser : public common::interfaces::IParser {
public:
	/**
	 * @brief Construct a new Argument Parser object
	 *
	 * @param argc number of command line parameters
	 * @param argv array of command line parameters
	 * @param delimiter the delimeter which is used to separate the parameter and it's value
	 */
	ArgumentParser( int argc, char** argv, char delimiter );

public:
	/**
	 * @brief Get the parameter by name
	 *
	 * @tparam T the type of the parameter
	 * @param parameterName the name of the parameter
	 * @return parameter's value
	 */
	template < class T >
	T getParameter( std::string parameterName ) const {
		// Check if the parameter even exists
		const auto entry = findEntry( parameterName );
		if( entry.empty() ) { return {}; }

		// Split the entry to get the value
		const auto splitEntry = split( entry, mDelimiter );

		// Get the value of the parameter
		cli::input::casters::ArgumentCaster< T, std::string > caster;
		return caster.cast( splitEntry.at( 1 ) );
	}

	/**
	 * @brief Get the parameter by name or return the default value
	 *
	 * @tparam T the type of the parameter
	 * @param parameterName the name of the parameter
	 * @param defaultValue the default value to return if there is no such parameter
	 * @return parameter's value
	 */
	template < class T >
	T getParameter( std::string parameterName, T defaultValue ) const {
		// Check if the parameter even exists
		const auto entry = findEntry( parameterName );
		if( entry.empty() ) { return defaultValue; }

		return getParameter< T >( parameterName );
	}

	/**
	 * @brief Get the parameter by name and throw an exception if it is not found
	 *
	 * @tparam T the type of the parameter
	 * @param parameterName the name of the parameter
	 * @param required is set to 'true' if the parameter is required
	 * @return parameter's value
	 */
	template < class T >
	T getRequiredParameter( std::string parameterName ) const {
		// Check if the parameter even exists
		const auto entry = findEntry( parameterName );
		if( entry.empty() ) {
			throw std::runtime_error( "Required parameter is not passed : " +
									  parameterName );
		}

		return getParameter< T >( parameterName );
	}

protected:
	/**
	 * @brief Find the parameter entry in the array of passed entries
	 *
	 * @param value the name of the parameter to find
	 * @return the entry
	 */
	std::string findEntry( const std::string& value ) const;

	/**
	 * @brief Splits the string using the given delimiter
	 *
	 * @param value the string to split
	 * @param delimiter the delimiter to use to split the string
	 * @return vector of tokens
	 */
	Tokens split( const std::string& value, char delimiter ) const override;

private:
	std::vector< std::string > mParameters;
	char					   mDelimiter;
};
} // namespace cli::input::parsers
