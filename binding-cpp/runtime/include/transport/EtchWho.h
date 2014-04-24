/* $Id$
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to you under the Apache License, Version
 * 2.0 (the "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ETCHWHO_H__
#define __ETCHWHO_H__
#include "common/EtchString.h"

class EtchWho {
public:

  /**
   * @param addr
   * @param port
   */
  EtchWho(EtchString addr, capu::int32_t port);

  /**
   * Destructor
   */
  virtual ~EtchWho();

  /**
   * @return the address of who.
   */
  EtchString getInetAddress();

  /**
   * @return the port of who.
   */
  capu::int32_t getPort();

  /**
   * @param addr
   * @param port
   * @return true if the specified addr and port match this who.
   */
  capu::bool_t matches(const EtchString &addr, capu::int32_t port);

private:
  EtchString mAddr;
  capu::int32_t mPort;
};

#endif


