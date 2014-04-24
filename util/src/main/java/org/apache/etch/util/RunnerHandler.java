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

package org.apache.etch.util;

/**
 * RunnerHandler receives notification of runner events.
 */
public interface RunnerHandler
{
	/**
	 * Reports that the thread controlling the runner has started.
	 */
	void started();

	/**
	 * Reports that the thread controlling the runner has stopped.
	 */
	void stopped();

	/**
	 * Reports that the thread controlling the runner has caught an
	 * exception.
	 * @param what a short description of the origin
	 * @param e an exception that was caught
	 */
	void exception( String what, Exception e );
}
