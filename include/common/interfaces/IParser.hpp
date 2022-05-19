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

#include <string>
#include <vector>

namespace common::interfaces {
class IParser {
public:
	using Tokens = std::vector< std::string >;

protected:
	/**
         * @brief Splits the string using the given delimiter
         *
         * @param value the string to split
         * @param delimiter the delimiter to use to split the string
         * @return vector of tokens
         */
	virtual Tokens split( const std::string& value, char delimiter ) const = 0;
};
} // namespace common::interfaces
