/* $Id$
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

package org.apache.etch.bindings.java.support;

import org.apache.etch.bindings.java.msg.Validator;

/**
 * Validator for float.
 */
public class Validator_float extends TypeValidator
{
	/**
	 * @param nDims the number of dimensions. 0 for a scalar.
	 * @return an instance of the validator.
	 */
	public static Validator_float get( int nDims )
	{
		checkDims( nDims );
		
		if (nDims >= validators.length)
			return new Validator_float( nDims );
		
		Validator_float v = validators[nDims];
		
		if (v == null)
			v = validators[nDims] = new Validator_float( nDims );
		
		return v;
	}
	
	private static Validator_float[] validators = new Validator_float[MAX_CACHED];
	
	/**
	 * Constructs the Validator.
	 *
	 * @param nDims the number of dimensions. 0 for a scalar.
	 */
	private Validator_float( int nDims )
	{
		super( Float.class, float.class, nDims, "float["+nDims+"]" );
	}

	public Validator elementValidator()
	{
		return get( nDims-1 );
	}
}
